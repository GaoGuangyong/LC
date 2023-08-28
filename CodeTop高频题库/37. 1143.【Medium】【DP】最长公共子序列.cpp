// https://leetcode.cn/problems/longest-common-subsequence/solution/zui-chang-gong-gong-zi-xu-lie-tu-jie-dpz-6mvz/

// DP

// 状态表示：
// f[i][j] 表示 text1 的 [1 ~ i] 和 text2 的 [1 ~ j] 的最长公共子序列长度（下标从 1 开始），则答案为 f[m][n]

// 初始化：
// 空字符串与任意有长度的字符串的最长公共子序列长度肯定为 0
// 使用 vector 声明数组的的时候，默认初值为 0，故不用单独初始化

// 状态转移：
// 根据 text1[i] 和 text2[j] 是否相等，分为 2 种情况

// 1、若 text1[i] == text2[j] 即两个字符串的最后一位相等，则可以将这两个字符加到最长公共子序列中，延长公共子序列
// 因此，问题就转化成了求 text1 的 [1 ~ i - 1] 和 text2 的 [1 ~ j - 1] 的最长公共子序列长度再 + 1
// 即 f[i][j] = f[i - 1][j - 1] + 1

// 2、若 text1[i] != text2[j] 即两个字符串的最后一位不等，则 text1 的 [1 ~ i] 和 text2 的 [1 ~ j] 的最长公共子序列长度无法延长
// 可以将这两个字符之一加到最长公共子序列中，因此 f[i][j] 就会继承 f[i - 1][j] 与 f[i][j - 1] 中的最大值
// 即 f[i][j] = max(f[i - 1][j], f[i][j - 1])

// 细节 1：定义的状态 f 和 text 下标均是从 1 开始的，而题目给出的 text 下标是从 0 开始的，为了一一对应，在一开始把两个字符串往后移动一位
// 细节 2：为什么 f 和 text 均定义成下标从 1 开始
// 原因是状态转移方程 f[i][j] = max(f[i - 1][j], f[i][j - 1]) 当我们的 f 数组定义成下标从 1 开始以后，我们就不用对下标越界问题进行特判


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 获取两个字符串的长度
        int m = text1.size();
        int n = text2.size();

        // 为了方便：下标从 1 开始，故将两个字符串都向后移动一位
        text1 = " " + text1;
        text2 = " " + text2;

        // 定义状态数组 + 初始化
        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        // 状态转移
        for (int i = 1; i < m + 1; i ++ ) {
            for (int j = 1; j < n + 1; j ++ ) {
                if (text1[i] == text2[j]) 
                    f[i][j] = f[i - 1][j - 1] + 1;
                else 
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        return f[m][n];
    }
};


// GPT 注释
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 获取字符串 text1 和 text2 的长度
        int m = text1.size();
        int n = text2.size();

        // 在字符串 text1 和 text2 的开头添加一个空格，目的是为了在后续的状态转移中处理边界情况
        text1 = " " + text1;
        text2 = " " + text2;

        // 定义状态数组 f，f[i][j] 表示 text1 前 i 个字符和 text2 前 j 个字符的最长公共子序列的长度
        // 初始化状态数组 f，全部置为 0
        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        // 状态转移过程，通过动态规划求解最长公共子序列的长度
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 如果 text1 的第 i 个字符和 text2 的第 j 个字符相同，则说明可以将它们加入最长公共子序列中
                // 所以当前状态 f[i][j] 等于在不包含这两个字符的情况下的最长公共子序列长度 f[i - 1][j - 1] 再加 1
                if (text1[i] == text2[j]) 
                    f[i][j] = f[i - 1][j - 1] + 1;
                else 
                    // 如果 text1 的第 i 个字符和 text2 的第 j 个字符不相同，则最长公共子序列长度为：
                    // 在不包含 text1 第 i 个字符的情况下，text2 前 j 个字符的最长公共子序列长度 f[i][j - 1]，和
                    // 在不包含 text2 第 j 个字符的情况下，text1 前 i 个字符的最长公共子序列长度 f[i - 1][j]
                    // 取两者的较大值
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }

        // 返回text1和text2的最长公共子序列的长度，即状态数组f的右下角元素值
        return f[m][n];
    }
};


// 二刷
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));

        text1 = " " + text1;
        text2 = " " + text2;

        for (int i = 1; i < m + 1; i ++ ) {
            for (int j = 1; j < n + 1; j ++ ) {
                if (text1[i] == text2[j]) 
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }

        return f[m][n];
    }
};

