
// 偏移量数组
// 先向右走，(0, 1)
// 走到头后向下走，(1, 0)
// 走到头后向左走，(0, -1)
// 走到头后向上走，(-1, 0)
// 走到头后右走，(0, 1)
// 注：走到头的含义：越界 || 已经走过了

// dx[4] = {0, 1, 0, -1}
// dy[4] = {1, 0, -1, 0}


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        // 先特判：如果给定空数组，则输出空数组
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();

        // 偏移量数组，{右，下，左，上}
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        // 标记数组
        vector<vector<bool>> visit(m, vector<bool>(n)); 

        // 起始位置 (0, 0)
        int x = 0, y = 0; 

        // 方向 d = 0, 1, 2, 3 代表 右，下，左，上
        int d = 0; 

        // 枚举 0 ~ m * n - 1
        for (int i = 0; i < m * n; i ++ ) {
            // 将当前遍历的位置 (x, y) 插入结果中，并标记为已访问
            res.push_back(matrix[x][y]); 
            visit[x][y] = true;

            // 求下一个遍历的位置 (a, b)
            int a = x + dx[d];
            int b = y + dy[d];

            // 若下一个位置 (a, b) 越界或已经访问过，则换下一个方向
            if (a < 0 || a >= m || b < 0 || b >= n || visit[a][b] == true) {
                d = (d + 1) % 4; // 注意这种写法：(使 d 在 0 -> 1 -> 2 -> 3 -> 0 间循环)
                a = x + dx[d];
                b = y + dy[d];
            }
            
            // 将 (a, b) 更新为下一个遍历位置 (x, y)
            x = a;
            y = b;
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        vector<vector<bool>> visit(m, vector<bool>(n)); 

        int x = 0, y = 0; 

        int d = 0; 

        for (int i = 0; i < m * n; i ++ ) {
            res.push_back(matrix[x][y]); 
            visit[x][y] = true;

            int a = x + dx[d];
            int b = y + dy[d];

            if (a < 0 || a >= m || b < 0 || b >= n || visit[a][b] == true) {
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


