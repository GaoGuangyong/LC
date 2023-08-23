// DP

// 状态表示：
// f[i][j] 表示从左上角走到 (i, j) 位置时礼物价值的最大值，则答案为 f[m][n]，（下标从 1 开始）

// 状态转移：
// (i, j) 可以从 (i - 1, j) 向下走来，也可以从 (i, j - 1) 向右走来
// f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i][j];


// 写法一：下标从 1 开始：无需特判

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return f[m][n];
    }
};



// 写法二：下标从 0 开始：需特判

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> f(m, vector<int>(n));

        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (i > 0) f[i][j] = max(f[i][j], f[i - 1][j]);
                if (j > 0) f[i][j] = max(f[i][j], f[i][j - 1]);
                
                f[i][j] += grid[i][j];
            }
        }

        return f[m - 1][n - 1];
    }
};

      


