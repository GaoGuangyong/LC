

// 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。

// DP
// 利用 剑指Offer II 98 题思想

// 状态表示：
// f[i][j] 表示从 (0, 0) 走到 (i, j) 的所有路径中和的数字总和的最小值

// 初始化：
// 起点的路径和为起点本身的值，f[0][0] = grid[i][j]

// 状态转移：
// 走到 (i, j) 有两条路径
// 若是从 (i - 1, j) 向下走到 (i, j)，则 f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j])
// 若是从 (i, j - 1) 向右走到 (i, j)，则 f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j])


// 写法一：初始化 和 状态转移 写在一起
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 定义状态数组：因为要求最小值，这里可以初始化为正无穷
        vector<vector<int>> f(m, vector<int>(n, INT_MAX));

        // 初始化 + 状态转移
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                // i == 0 且 j == 0
                if (i == 0 && j == 0) f[i][j] = grid[i][j]; // 初始化起点
                // i != 0 或 j != 0
                else {
                    // 如果 i > 0，则可以从上面过来
                    if (i > 0) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                    // 如果 j > 0，则可以从左边过来
                    if (j > 0) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
                }
            }
        }

        return f[m - 1][n - 1];
    }
};

// 写法二：初始化 和 状态转移 分开写（推荐）
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 定义状态数组：因为要求最小值，这里可以初始化为正无穷
        vector<vector<int>> f(m, vector<int>(n, INT_MAX));

        // 初始化
        f[0][0] = grid[0][0];

        // 状态转移
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                // 如果 i > 0，则可以从上面过来
                if (i > 0) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                // 如果 j > 0，则可以从左边过来
                if (j > 0) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
            }
        }

        return f[m - 1][n - 1];
    }
};


// 无注释版本
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> f(m, vector<int>(n, INT_MAX));

        f[0][0] = grid[0][0];

        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (i > 0) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                if (j > 0) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
            }
        }

        return f[m - 1][n - 1];
    }
};



