
// DFS + 回溯

#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> path; // 当前路径
vector<pair<int, int>> res; // 答案路径
int m, n; // 矩阵的行数 & 列数

// 偏移量数组 {上，右，下，左}
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};



// 从当前矩阵的 (x, y) 开始 dfs 遍历
void dfs(vector<vector<int>>& matrix, int x, int y) {
    // 递归出口：如果枚举到了 matrix[m - 1][n - 1]，则将当前路径设为答案
    if (x == m - 1 && y == n - 1 ) {
        res = path;
        return;
    }
    // 向四个方向遍历，新遍历的点为 (a, b)
    for (int i = 0; i < 4; i ++ ) {
        int a = x + dx[i];
        int b = y + dy[i];
        // 如果 (a, b) 未越界，且不是墙壁，则将其加入 path，并标记为墙壁，访问后回溯
        if (a >= 0 && a < m && b >= 0 && b < n && matrix[a][b] == 0 ) {
            // 选择
            path.push_back({a, b});
            matrix[a][b] = 1;
            // dfs
            dfs(matrix, a, b);
            // 撤销选择
            path.pop_back();
            matrix[a][b] = 0;
        }
    }
}

int main() {
    // 读入矩阵的行数 m 和列数 n
    cin >> m >> n;
    // 读入矩阵
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m ; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            cin >> matrix[i][j];
        }
    }
    // 将起点加入当前路径，并标记为墙壁
    path.push_back({0, 0});
    matrix[0][0] = 1;
    
    dfs(matrix, 0, 0); // 从起点开始遍历

    // 遍历结束后，遍历结果路径，按照题目要求格式输出
    for (pair<int, int> x: res) {
        cout << '(' << x.first << ',' << x.second << ')' << endl;
    }
}


