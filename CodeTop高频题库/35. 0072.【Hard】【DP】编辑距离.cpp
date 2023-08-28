

// 给你两个单词?word1 和?word2，请返回将?word1?转换成?word2 所使用的最少操作数。你可以对一个单词进行如下三种操作：

// 插入一个字符
// 删除一个字符
// 替换一个字符


// DP
// 状态表示：
// f[i][j] 表示将 word1[1 ~ i] 变成 word2[1 ~ j] 所有按顺序操作的方案里，操作次数的最小值

// 初始化：
// 当某个字符串的长度为 0，则需要操作的次数为另一个字符串的长度

// 状态转移：
// 对于 word1 有三种情况
// 【删】删除 Word1[i] 后 word1 和 word2 相等，说明删之前 word1[1 ~ i - 1] 和 word2[1 ~ j] 已经相等了
//      f[i][j] = f[i - 1][j] + 1
// 【插】在 word1[i] 后插入 Word2[j] 后 word1 和 word2 相等，说明插入之前 word1[1 ~ i] 和 word2[1 ~ j - 1] 已经相等了
//      f[i][j] = f[i][j - 1] + 1
// 【改】修改 Word1[i] 后 word1 和 word2 相等，说明修改之前 word1[1 ~ i - 1] 和 word2[1 ~ j - 1] 已经相等了
//      f[i][j] = f[i - 1][j - 1] + 1 (当 word1[i] != word2[j])
//      f[i][j] = f[i - 1][j - 1] + 0 (当 word1[i] == word2[j]，则不需要修改，操作次数 + 0)
// 最终结果为上述三种情况取 min

// 同理，对于 word2 也有三种情况


// 写法一：（不推荐）
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        word1 = ' ' + word1;
        word2 = ' ' + word2;

        // 定义状态数组
        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        // 初始化：当某个字符串的长度为 0，则需要操作的次数为另一个字符串的长度
        for (int i = 0; i <= m; i ++ ) f[i][0] = i;
        for (int j = 0; j <= n; j ++ ) f[0][j] = j;

        // 状态转移
        for (int i = 1; i <= m; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                // 先算前两种情况的最小值
                f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
                // 再算和最后一种情况的最小值
                int t = word1[i] == word2[j] ? 0 : 1;
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + t);
            }
        }

        return f[m][n];
    }
};


// 写法二：（推荐）
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        word1 = ' ' + word1;
        word2 = ' ' + word2;

        // 定义状态数组
        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        // 初始化：当某个字符串的长度为 0，则需要操作的次数为另一个字符串的长度
        for (int i = 1; i < m + 1; i ++ ) f[i][0] = i;
        for (int j = 1; j < n + 1; j ++ ) f[0][j] = j;

        // 状态转移
        for (int i = 1; i < m + 1; i ++ ) {
            for (int j = 1; j < n + 1; j ++ ) {
                int op1 = f[i - 1][j] + 1; // 删
                int op2 = f[i][j - 1] + 1; // 插
                int op3 = f[i - 1][j - 1]; // 改
                if (word1[i] != word2[j]) op3 ++ ; // 只有不相等才需要修改，操作次数 + 1
                
                f[i][j] = min(min(op1, op2), op3); // 三种操作取最小
            }
        }
        return f[m][n];
    }
};


// 二刷
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        word1 = " " + word1;
        word2 = " " + word2;

        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m + 1; i ++ ) f[i][0] = i;
        for (int j = 0; j < n + 1; j ++ ) f[0][j] = j;

        for (int i = 1; i < m + 1; i ++ ) {
            for (int j = 1; j < n + 1; j ++ ) {
                int op1 = f[i - 1][j] + 1;
                int op2 = f[i][j - 1] + 1;
                int op3 = f[i - 1][j - 1];
                if (word1[i] != word2[j]) op3 ++ ;

                f[i][j] = min(op1, min(op2, op3));
            }
        }

        return f[m][n];
    }
};


