
// 预处理 + 枚举

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<int> row(501); // row[i] 表示第 i 行的像素数量
        vector<int> col(501); // col[i] 表示第 j 行的像素数量
        
        int n = picture.size(); // 行数
        int m = picture[0].size(); // 列数

        // 预处理 row 数组和 col 数组
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                if (picture[i][j] =='B') {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }

        int res = 0;

        // 先枚举矩阵的每行
        for (int i = 0; i < n; i ++ ) {
            // 如果当前行只有 1 个黑色像素，则枚举当前行的每个像素
            if (row[i] == 1) {
                for (int j = 0; j < m; j ++ ) {
                    // 如果枚举到了黑色像素，判断当前列是否也只有 1 个黑色像素 
                    if (picture[i][j] == 'B') {
                        if (col[j] == 1) res += 1;
                    }
                }
            }
        }

        return res;
    }
};

