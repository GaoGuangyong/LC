

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

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        word1 = ' ' + word1;
        word2 = ' ' + word2;

        // 定义状态数组
        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        // 初始化：当某个字符串的长度为 0，则需要操作的次数为另一个字符串的长度
        for (int i = 0; i <= n; i ++ ) f[i][0] = i;
        for (int j = 0; j <= m; j ++ ) f[0][j] = j;

        // 状态转移
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                // 先算前两种情况的最小值
                f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
                // 再算和最后一种情况的最小值
                int t = 1;
                if (word1[i] == word2[j]) t = 0;
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + t);
            }
        }
        return f[n][m];
    }
};


// 无注释版本

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        word1 = " " + word1;
        word2 = " " + word2;

        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i ++ ) f[i][0] = i;
        for (int j = 1; j <= m; j ++ ) f[0][j] = j;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);

                if (word1[i] == word2[j]) 
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                else 
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);    
            }
        }

        return f[n][m];
    }
};
