

// DP，证明思路见笔记
// f[i][j] 表示以 (i, j) 为右下角的最大正方形的边长 

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();     // m 行
        int n = matrix[0].size();  // n 列

        // 状态表示
        vector<vector<int>> f(m + 1, vector<int>(n + 1)); 

        // 状态转移
        int res = 0; // 维护最大边长
        
        for (int i = 1; i <= m; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                // 如果当前的格子的值为 1
                if (matrix[i - 1][j - 1] == '1') { 
                    f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
                    res = max(res, f[i][j]); // 每次把 res 和 f[i][j] 取 max，更新最大边长
                }
            }
        }

        return res * res; // 最终的面积为边长的平方
    }
};

// 无注释版
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        int res = 0;
        for (int i = 1; i <= m; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                if (matrix[i - 1][j - 1] == '1') {
                    f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
                    res = max(res, f[i][j]);
                }
            }
        }
        return res * res;
    }
};

