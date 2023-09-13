

// 题意：
// 输入一个二维矩阵，其中，1 表示墙壁，0 表示空地，只能横竖走，要求找出一条从左上角到右下角的路径
// 输出该路径，要求按照该路径，每行输出一个坐标 (i, j)


// DFS + 回溯

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> path; // 当前路径
vector<pair<int, int>> res; // 答案路径
int m, n; // 矩阵的行数 & 列数

// 偏移量数组 {上，右，下，左}
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// ！！！  技巧：对于矩阵遍历的 DFS 函数来说，参数往往就这样设置，表示从当前矩阵的 (x, y) 开始 dfs 遍历
void dfs(vector<vector<int>>& matrix, int x, int y) {
    // 递归出口：如果枚举到了 matrix[m - 1][n - 1]，则找到了一条路径，故将当前路径设为答案路径
    if (x == m - 1 && y == n - 1 ) {
        res = path;
        return;
    }
    // 向四个方向遍历，新遍历的点为 (a, b)
    for (int i = 0; i < 4; i ++ ) {
        int a = x + dx[i];
        int b = y + dy[i];
        // 如果 (a, b) 未越界，且不是墙壁，则将其加入 path，并标记为墙壁，访问后回溯
        if (a >= 0 && a < m && b >= 0 && b < n && matrix[a][b] != 1) {
            // 选择
            path.push_back({a, b});
            matrix[a][b] = 1;
            // dfs
            dfs(matrix, a, b);
            // 撤销选择
            matrix[a][b] = 0;
            path.pop_back();
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

    path.push_back({0, 0});  // 将起点加入当前路径
    matrix[0][0] = 1; // 将起点标记为墙壁
    
    dfs(matrix, 0, 0); // 从起点开始遍历

    // 遍历结束后，遍历结果路径，按照题目要求格式输出
    for (auto x: res) {
        cout << '(' << x.first << ',' << x.second << ')' << endl;
    }
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int m, n;

vector<pair<int, int>> path;
vector<pair<int, int>> res; 

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(vector<vector<int>>& matrix, int x, int y) {
    if (x == m - 1 && y == n - 1 ) {
        res = path;
        return;
    }
    
    for (int i = 0; i < 4; i ++ ) {
        int a = x + dx[i];
        int b = y + dy[i];
        
        if (a >= 0 && a < m && b >= 0 && b < n && matrix[a][b] != 1) {
            path.push_back({a, b});
            matrix[a][b] = 1;

            dfs(matrix, a, b);
            
            matrix[a][b] = 0;
            path.pop_back();
        }
    }
}

int main() {
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m ; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            cin >> matrix[i][j];
        }
    }

    path.push_back({0, 0});
    matrix[0][0] = 1;

    dfs(matrix, 0, 0);

    for (auto [x, y]: res) { // 注意这种遍历数组的方法
        cout << '(' << x << ',' << y << ')' << endl;
    }

    return 0;
}

