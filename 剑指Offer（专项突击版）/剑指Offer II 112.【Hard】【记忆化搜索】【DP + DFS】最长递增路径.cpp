
// DP + DFS：即计算状态数组 f 的过程中要依靠 dfs

// 由于此题的状态依赖关系比较复杂，不容易用循环来求每个状态的值，所以用记忆化搜索来做：
// 如果某个状态还没计算过，先递归计算某个点周围的点的状态，然后用周围四个点状态 +1 中取最大值来更新当前状态

// 状态表示：
// f[x][y]: 表示以 (x, y) 为起点的上升路径的最大长度
// 状态转移：
// 用偏移量数组向四个方向搜索，如果合法就走过去，长度 +1
// 即如果新遍历到的格子 (a, b) 比当前的格子 (x ,y) 的数值大，则更新最大长度：f[x][y] = max(f[x][y], dfs(a, b) + 1)
// 最终再返回所有递增路径中，最长的那个

class Solution {
public:
    // 全局变量
    int m, n;
    int res;
    vector<vector<int>> f; // 状态数组
    vector<vector<int>> matrix; // 输入矩阵

    // 偏移量数组
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // DFS 函数：递归计算当前格子 (x, y) 的状态 f[x][y]
    int dfs(int x, int y) {
        // 如果该点的状态计算过了，则直接调用，无需重复计算
        if (f[x][y] != -1) return f[x][y];
        // 否则，需要计算该点的状态
        f[x][y] = 1; // 当前只有 (x, y) 这一个点，初始路径长度就是 1
        // 向四个方向搜索
        for (int i = 0; i < 4; i ++ ) {
            // 当前新走到的格子 (a, b)
            int a = x + dx[i];
            int b = y + dy[i];
            // 如果新搜索到的格子 (a, b) 未越界 && 满足上升条件：(a, b) > (x, y)
            if (a >= 0 && a < m && b >= 0 && b < n && matrix[a][b] > matrix[x][y])
                f[x][y] = max(f[x][y], dfs(a, b) + 1); // 利用周围四个点状态 +1 中取最大值来更新当前状态
        }
        return f[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& _matrix) {
        matrix = _matrix;
        
        m = matrix.size(); // 行数
        n = matrix[0].size(); // 列数

        // 初始化每个节点的状态值为 -1，代表没计算过
        f = vector<vector<int>>(m, vector<int>(n, -1)); 
        
        // 遍历二维数组，更新最长的上升路径的长度
        res = 0;
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                res = max(res, dfs(i, j));
            }
        }
        
        return res;
    }
};


// 无注释版本
class Solution {
public:
    int m, n;
    int res;
    vector<vector<int>> f;
    vector<vector<int>> matrix;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int dfs(int x, int y) {
        if (f[x][y] != -1) return f[x][y];

        f[x][y] = 1;
        
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && matrix[a][b] > matrix[x][y])
                f[x][y] = max(f[x][y], dfs(a, b) + 1);
        }
        return f[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& _matrix) {
        matrix = _matrix;
        
        m = matrix.size();
        n = matrix[0].size();

        f = vector<vector<int>>(m, vector<int>(n, -1)); 
        
        res = 0;
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                res = max(res, dfs(i, j));
            }
        }
        
        return res;
    }
};


