
// 偏移量数组做法 {右，下，左，上}
// 先向右走，(0, 1)
// 走到头后向下走，(1, 0)
// 走到头后向左走，(0, -1)
// 走到头后向上走，(-1, 0)
// 走到头后右走，(0, 1)
// 因此，dx[4] = {0, 1, 0, -1}，dy[4] = {1, 0, -1, 0}
// 注：走到头的含义：越界 || 已经走过了

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int m = matrix.size();
        int n = matrix[0].size();

        // 偏移量数组，{右，下，左，上}
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        vector<vector<bool>> visit(m, vector<bool>(n)); // 标记数组

        int x = 0, y = 0; // 起始位置 (0, 0)
        int d = 0; // 方向: 0, 1, 2, 3

        // 遍历当前位置 (x, y)
        for (int i = 0; i < m * n; i ++ ) { // 0 ~ m * n - 1
            res.push_back(matrix[x][y]); // 将当前遍历的位置插入结果中
            visit[x][y] = true; // 并标记为已访问

            // 求下一个遍历的位置 (a, b)
            int a = x + dx[d];
            int b = y + dy[d];

            // 若下一个位置 (a, b) 越界或已经走过了，则换下一个方向
            if (a < 0 || a >= m || b < 0 || b >= n || visit[a][b] == true) { 
                d = (d + 1) % 4; // 注意这种写法：(使 d 在 0->1->2->3->0 间循环)
                a = x + dx[d];
                b = y + dy[d];
            }
            // 否则，可以走到 (a, b)，故将 (a, b) 更新为下一个遍历位置 (x, y)
            x = a;
            y = b;
        }
        return res;
    }
};


// 二刷
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        vector<vector<bool>> visit(m, vector<bool>(n, false));

        int x = 0, y = 0, d = 0;

        for (int i = 0; i < m * n; i ++ ) {
            res.push_back(matrix[x][y]);
            visit[x][y] = true;

            int a = x + dx[d];
            int b = y + dy[d];

            if (a < 0 || a >= m || b < 0 || b >= n || visit[a][b] == true) { // 注意是 if 不是 while
                d = (d + 1) % 4;
                a = x + dx[d];
                b = y + dy[d];
            }

            x = a;
            y = b;
        }

        return res;
    }
};