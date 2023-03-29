// DP
/* 到每个格子的方案数如下图所示
—————————————————————
| 1 | 1 | 1 | 1 | 1 | 
—————————————————————                   
| 1 | 2 | 3 | 4 | 5 | 
————————————————————— 
| 1 | 3 | 6 |10 |15 |  
—————————————————————
*/
// 状态表示：
// f[i][j] 表示从（0，0）走到（i，j）的路径数，答案为 f[m-1][n-1]

// 初始化：
// 起点的路径数记为 1：f[0][0] = 1

// 状态转移：
// 如果 i > 0，则可以从上面过来, f[i][j] += f[i - 1][j]
// 如果 j > 0，则可以从左边过来, f[i][j] += f[i][j - 1]


// 写法一：将初始化和状态转移写到一起
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 定义状态数组
        vector<vector<int>> f(m, vector<int>(n));

        // 初始化 + 状态转移
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                // i == 0 且 j == 0
                if (i == 0 && j == 0) f[i][j] = 1; // 初始化起点
                // i != 0 或 j != 0 
                else {
                    // 如果 i > 0，则可以从上面过来
                    if (i > 0) f[i][j] += f[i - 1][j];
                    // 如果 j > 0，则可以从左边过来
                    if (j > 0) f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};


// 写法二：将初始化和状态转移分开（推荐）
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 定义状态数组
        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        // 初始化
        for (int i = 0; i < m; i ++ ) f[i][0] = 1;
        for (int j = 0; j < n; j ++ ) f[0][j] = 1;

        // 状态转移
        for (int i = 1; i < m; i ++ ) {
            for (int j = 1; j < n; j ++ ) {
                f[i][j] += f[i - 1][j];
                f[i][j] += f[i][j - 1];
            }
        }

        // 答案
        return f[m - 1][n - 1];
    }
};


// 无注释版
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m; i ++ ) f[i][0] = 1;
        for (int j = 0; j < n; j ++ ) f[0][j] = 1;

        for (int i = 1; i < m; i ++ ) {
            for (int j = 1; j < n; j ++ ) {
                f[i][j] += f[i - 1][j];
                f[i][j] += f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};