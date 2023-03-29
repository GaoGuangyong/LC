// https://leetcode.cn/problems/longest-common-subsequence/solution/zui-chang-gong-gong-zi-xu-lie-tu-jie-dpz-6mvz/

// DP
// 状态表示：
// f[i][j] 表示 text1 的 [1 ~ i] 和 text2 的 [1 ~ j] 的最长公共子序列长度（下标从 1 开始），则答案为 f[n][m]

// 初始化：
// 空字符串与任意有长度的字符串的最长公共子序列长度肯定为 0
// 使用 vector 声明数组的的时候，默认初值为 0，故不用单独初始化

// 状态转移：
// 根据 text1[i] 和 text2[j] 是否相等，分为 2 种情况

// 1、若 text1[i] == text2[j] 即两个字符串的最后一位相等，则同时删掉这两个字符
// 则问题就转化成了 text1 的 [1 ~ j - 1] 和 text2 的 [1 ~ j - 1] 的最长公共子序列长度再 + 1
// 即 f[i][j] = f[i - 1][j - 1] + 1

// 2、若 text1[i] != text2[j] 即两个字符串的最后一位不等，则删掉这两个字符之一，取最大值
// 则 text1 的 [1 ~ i] 和 text2 的 [1 ~ j] 的最长公共子序列长度无法延长
// 因此 f[i][j] 就会继承 f[i - 1][j] 与 f[i][j - 1] 中的最大值
// 即 f[i][j] = max(f[i - 1][j], f[i][j - 1])

// 细节 1：定义的状态 f 和 text 下标均是从 1 开始的，而题目给出的 text 下标是从 0 开始的，为了一一对应，在一开始把两个字符串往后移动一位
// 细节 2：为什么 f 和 text 均定义成下标从 1 开始
// 原因是状态转移方程 f[i][j] = max(f[i - 1][j], f[i][j - 1]) 当我们的 f 数组定义成下标从 1 开始以后，我们就不用对下标越界问题做出额外判断

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 获取两个字符串的长度
        int n = text1.size();
        int m = text2.size();

        // 为了方便：下标从 1 开始，故将两个字符串都向后移动一位
        text1 = " " + text1;
        text2 = " " + text2;

        // 定义状态数组 + 初始化
        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        // 状态转移
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                if (text1[i] == text2[j]) 
                    f[i][j] = f[i - 1][j - 1] + 1;
                else 
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        return f[n][m];
    }
};


// 无注释版本
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        text1 = " " + text1;
        text2 = " " + text2;

        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                if (text1[i] == text2[j]) 
                    f[i][j] = f[i - 1][j - 1] + 1;
                else 
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        return f[n][m];
    }
};

