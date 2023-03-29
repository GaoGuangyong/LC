// BFS

typedef pair<int, int> PII;

class Solution {
public:
    // 偏移量数组 {上，右，下，左}
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int movingCount(int m, int n, int k) {
        int res = 1; // 最终结果：能到达的格子数，初值为 1（至少能到达起点格子）
        
        vector<vector<bool>> visit(m, vector<bool>(n, false)); // 标记数组，标记这个格子是否已经访问过
        visit[0][0] = true; // 将起点标记为已访问

        queue<PII> q; // BFS 队列，队列中的每个元素都是格子的坐标 {x, y}
        q.push({0, 0}); // 将起始坐标入队

        // BFS 过程
        while (q.size()) { // 只要队列不空，就不断将当前格子的坐标入队
            auto t = q.front(); // 获取队头元素，即当前格子 t，坐标 {t.first, t.second}
            q.pop(); // 队头出队

            // 向 4 个方向遍历
            for (int i = 0; i < 4; i ++ ) {
                // 下一个遍历的格子坐标 (a, b)
                int a = t.first + dx[i];
                int b = t.second + dy[i];

                // 如果新搜索到的格子 (a, b) 超出范围或已经被访问过了，则跳过，继续搜索下一个移动方向
                if (a < 0 || a >= m || b < 0 || b >= n || visit[a][b] == true) continue;

                // 否则，判断一下行列坐标的数位之和是否满足条件
                int sum = 0; // 数位之和
                int temp; // 临时变量，用于分别计算行列坐标的位数之和

                // 先处理行坐标
                temp = a;
                while (temp != 0) { // 只要 temp 不为 0，就一直分割各个位数
                    sum += temp % 10; // 加上个位数
                    temp /= 10; // 去除个位数
                }

                // 再处理列坐标
                temp = b;
                while (temp != 0) { // 只要 temp 不为 0，就一直分割各个位数
                    sum += temp % 10; // 加上个位数
                    temp /= 10; // 去除个位数
                }

                if (sum > k) continue; // 若移动后的那个格子，行坐标和列坐标的数位之和大于 k，则跳过，继续搜索下一个移动方向

                // 否则，移动后个那个格子就是合法的，走到那个格子
                visit[a][b] = true; // 将 {a, b} 标记为 true，代表访问过
                q.push({a, b}); // 将其坐标 {a, b} 入队
                res ++ ; // 能到达的格子数 + 1
            }
        }
        return res;
    }
};


// 无注释版本
typedef pair<int, int> PII;

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int movingCount(int m, int n, int k) {
        int res = 1; 
        
        vector<vector<bool>> visit(m, vector<bool>(n, false)); 
        visit[0][0] = true;

        queue<PII> q;
        q.push({0, 0});

        while (q.size()) { 
            auto t = q.front(); 
            q.pop();

            for (int i = 0; i < 4; i ++ ) {
                int a = t.first + dx[i];
                int b = t.second + dy[i];

                if (a < 0 || a >= m || b < 0 || b >= n || visit[a][b] == true) continue;

                int sum = 0;
                int temp; 

                temp = a;
                while (temp != 0) {
                    sum += temp % 10;
                    temp /= 10;
                }

                temp = b;
                while (temp != 0) { 
                    sum += temp % 10; 
                    temp /= 10; 
                }

                if (sum > k) continue; 

                visit[a][b] = true; 
                q.push({a, b}); 
                res ++ ;
            }
        }
        return res;
    }
};
