
// DFS -> 经典的 FloodFill 算法
// 做法：遍历二维数组，当遍历到 1 的时候，就 dfs 继续遍历相邻的位置

class Solution {
public:
    int m, n; // 行数，列数
    vector<vector<int>> grid; // 为了想要在 dfs 函数里能够用到 grid，所以声明一个全局变量

    // 偏移量数组 {上，右，下，左}
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // 递归函数：返回 (x, y) 格子所在的连通块中格子的数量
    int dfs(int x, int y) {
        int cnt = 1; // 初始时，当前格子记下来 (数量为 1)
        grid[x][y] = 0; // 把当前格子清空

        // 枚举上，右，下，左四个方向
        for (int i = 0; i < 4; i ++ ) {
            // 当前新走到的格子 (a, b)
            int a = x + dx[i];
            int b = y + dy[i];
            // 如果新搜索到的格子 (a, b) 未越界且 grid[a][b] == 1，则可以走到这个格子
            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 1) {
                cnt += dfs(a, b); // 把新搜到的格子所在的连通块中格子的数量加到总数上
            }
        }

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& _grid) {
        grid = _grid;
        m = grid.size();
        n = grid[0].size();
        int res = 0; // 连通块的最大值

        // 遍历矩阵，不断更新 (i, j) 格子所在的连通块中格子的数量的最大值
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (grid[i][j] == 1) { // 如果当前枚举的格子是 1
                    res = max(res, dfs(i, j)); // 更新连通块的最大值
                }
            }
        }

        return res; // 遍历完后，返回所有连通块数量的最大值
    }
};


// 二刷
class Solution {
public:
    vector<vector<int>> grid;
    int m, n;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int dfs(int x, int y) {
        int cnt = 1;
        grid[x][y] = 0;

        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 1) {
                cnt += dfs(a, b);
            }
        }

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& _grid) {
        grid = _grid;
        m = grid.size();
        n = grid[0].size();

        int res = 0;

        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (grid[i][j] == 1) 
                    res = max(res, dfs(i, j));
            }
        }

        return res;
    }
};
