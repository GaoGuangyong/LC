
// DP
// 技巧：如果从上往下走的话需要特判两边，所以改成从下往上走，这样就不需要进行特判了

// 状态表示：
// f[i][j] 表示从最后一行走到 (i, j) 的所有路径权值的最小值，则答案为 f[0][0]

// 状态转移：
// (i, j) 可以分为从 (i + 1, j) 向右上方走到 或 从 (i + 1, j + 1) 向左上方走到，取二者的最小值再加上 (i, j) 的权值即可

// 进阶：不使用额外的空间，利用 triangle 递推

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // 从倒数第 2 行开始向上遍历（即最后一行不必要算）
        for (int i = n - 2; i >= 0; i -- ) {
            // i 行的下标范围是 [0 ~ i]
            for (int j = 0; j <= i; j ++ ) {
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};


// 无注释版本
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for (int i = n - 2; i >= 0; i -- ) {
            for (int j = 0; j <= i; j ++ ) {
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};
