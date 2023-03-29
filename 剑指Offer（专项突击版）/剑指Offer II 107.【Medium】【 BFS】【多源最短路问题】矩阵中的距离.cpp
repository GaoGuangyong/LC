
// 多源最短路问题 --> BFS
// 对于每条边的权值都是相同的无向图，求其他各个点到某个点的最短路径，直接从这个点开始 BFS 就可以了

// 题目翻译：对于每个位置，求离它最近的 0 的距离是多少（注：0 到最近的 0 的距离认为是 0）
// 相当于给我们了一个无向图，图中的 0 就是起点，求每个 1 到所有起点的距离的最小值

// 为方便，定义一个超级起点，到图中各个起点的距离为 1，则原问题就变成了求每个 1 到超级起点的距离的最小值，再 -1 
// 一开始把超级起点加入队列，然后把所有起点（0）加入队列
// 实际上 BFS 的时候不需要真的建立超级起点，仍旧是和单源最短路 BFS 问题一样，最开始把所有起点（0）都加入到队列
// 相当于超级起点到所有起点的距离设置为 0，最后也不需要去减 1 了


typedef pair<int, int> PII;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); // 行数 m
        int n = mat[0].size(); // 列数 n

        // 偏移量数组 {上，右，下，左}
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        // 最短路问题，必用距离数组 dist，dist[i][j] 表示 (i, j) 距离起点的距离
        vector<vector<int>> dist(m, vector<int>(n, -1)); // 距离初始化为非法值即可，如 -1

        queue<PII> q; // BFS 队列，每个点都是一组数对 <i, j>，表示 mat[i][j] 的坐标

        // 先将所有的起点（0）的坐标插入队列
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0; // 起点距离起点的距离为 0
                    q.push({i, j}); // 将 0 入队
                }
            }
        }

        // BFS 过程（按层遍历）
        while (q.size()) { // 只要队列不空，就不断将节点入队
            auto t = q.front(); // 获取队头（ t 对应的坐标为 {t.first, t.second} ）
            q.pop(); // 队头出队

            // 当前位置坐标 (x, y)
            int x = t.first;
            int y = t.second;

            // 新遍历的位置坐标 (a, b)
            for (int i = 0; i < 4; i ++ ) {
                int a = x + dx[i];
                int b = y + dy[i];
                // 如果新遍历的位置坐标 (a, b) 未越界 && 未被遍历过
                if (a >= 0 && a < m && b >= 0 && b < n && dist[a][b] == -1) {
                    // 则更新 (a, b) 距离起点的距离：在 t 的基础上 + 1（因为每条边的权值都为 1）
                    dist[a][b] = dist[x][y] + 1; 
                    // 将新搜索到的节点入队
                    q.push({a, b}); 
                }
            }
        }
        return dist; // 最后返回距离数组即可
    }
};


// 无注释版本
typedef pair<int, int> PII;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        vector<vector<int>> dist(m, vector<int>(n, -1));

        queue<PII> q;

        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (q.size()) {
            auto t = q.front();
            q.pop();

            int x = t.first;
            int y = t.second;

            for (int i = 0; i < 4; i ++ ) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a >= 0 && a < m && b >= 0 && b < n && dist[a][b] == -1) {
                    dist[a][b] = dist[x][y] + 1; 
                    q.push({a, b}); 
                }
            }
        }
        return dist;
    }
};

