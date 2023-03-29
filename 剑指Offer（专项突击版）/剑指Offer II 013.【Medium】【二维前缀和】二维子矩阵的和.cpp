// 二维前缀和

class NumMatrix {
public:
    vector<vector<int>> s; // 定义前缀和矩阵 s

    // 给定整数矩阵 matrix 进行初始化
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return; // 特判：如果矩阵为空，直接返回
        int m = matrix.size();
        int n = matrix[0].size();

        // 初始化二维前缀和数组 s[i][j]
        s = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i ++ )
            for (int j = 1; j <= n; j ++ )
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
    }

    // 求以 matrix[row1][col1] 为左上角，以 matrix[row2][col2] 为右下角的子矩阵的元素和
    int sumRegion(int x1, int y1, int x2, int y2) {
        x1 ++, y1 ++, x2 ++, y2 ++; // 因为 a 的下标是从 0 开始的，所以先都 + 1
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    }
};


// 无注释版本
class NumMatrix {
public:

    vector<vector<int>> s;

    // 给定整数矩阵 matrix 进行初始化
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        s = vector<vector<int>>(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    // 求以 matrix[row1][col1] 为左上角，以 matrix[row2][col2] 为右下角的子矩阵的元素和
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 ++ , col1 ++, row2 ++ , col2 ++ ;
        return s[row2][col2] - s[row1 - 1][col2] - s[row2][col1 - 1] + s[row1 - 1][col1 - 1];
    }
};
