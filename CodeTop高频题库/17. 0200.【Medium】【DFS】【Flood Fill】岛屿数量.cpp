
// DFS
// 本题属于经典的 flood fill 问题
// 遍历二维数组，如果 grid(i, j) 未遍历且值为 1，则遍历
// 然后递归遍历上下左右四个方向

class Solution {
public:
    vector<vector<char>> grid; // 为了方便在 dfs 函数中使用 grid，声明成全局变量
    int m, n;

    // 偏移量数组（上，右，下，左）
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // DFS 函数：将与当前位置连通的所有陆地标记为'#'
    void dfs(int x, int y) {
        // 将当前遍历的格子置为特殊值，代表已经遍历过了
        grid[x][y] = '#'; 

        // 向四个方向搜索
        for (int i = 0; i < 4; i ++ ) {
            // 当前新走到的格子 (a, b)
            int a = x + dx[i];
            int b = y + dy[i];
            // 如果 a 和 b 没有越界，且 grid[a][b] 是陆地的话
            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == '1') {
                dfs(a, b); // 递归搜索
            }
        }
    }

    // 主函数：计算岛屿数量
    int numIslands(vector<vector<char>>& _grid) {
        grid = _grid;

        m = grid.size(); // 行数
        n = grid[0].size(); // 列数

        int res = 0; // 岛屿的个数
        
        // 遍历二维数组
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (grid[i][j] == '1') { // 如果当前遍历的是陆地的话
                    dfs(i, j); // 递归搜索
                    res ++ ; // 每搜一个，岛屿的个数 + 1
                }
            }
        }
        return res; // 返回岛屿的个数
    }
};


// 二刷
class Solution {
public:
    vector<vector<char>> grid;
    int m, n;
    int res = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int x, int y) {
        grid[x][y] = '#';

        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == '1') {
                dfs(a, b);
            }
        }
    }

    int numIslands(vector<vector<char>>& _grid) {
        grid = _grid;

        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    res ++ ;
                }
            }
        }

        return res;
    }
};