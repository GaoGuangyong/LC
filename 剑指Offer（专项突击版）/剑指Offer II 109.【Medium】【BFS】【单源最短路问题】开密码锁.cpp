
// 单源最短路问题 --> BFS

// 题目翻译：
// 将每个字符串看成一个点，例如：给定起点 0000，和终点 0202
// 每次选择起点中的某一位，+1 或 -1，(注意 0 到 9 是循环排布的，即 9 加 1 是 0，0 减 1 是 9)
// 总共 10^4 个点相互转化 (两个点之间如果可以相互转化的话，就连一条边，某些点不能走到)
// 就变成了对于每条边的权值都相同的无向图，求从起点到终点的最短路径长度，从起点开始 BFS

// 注意与上一题的对比：
// 本题是求边数，剑指Offer II 108 题 是求点数
// 本题给的字符串数组是不能走的点，剑指Offer II 108 题 给的字符串数组是可以走的点

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000"; // 起点

        // 特判：起点 = 终点，则边数为 0
        if (start == target) return 0;

        // 定义哈希集合：存所有不能走的点
        unordered_set<string> S; 
        for (string s: deadends) S.insert(s);

        // 如果起点就不能走，则不可能走到终点，返回 -1
        if (S.count(start)) return -1;  

        // 定义哈希表 dist，存最短路经上的点到起点的距离
        unordered_map<string, int> dist; 
        dist[start] = 0; // 起点的距离为 0

        queue<string> q; // BFS 队列，每个点都是一个 string 单词
        q.push(start); // 将起点加入队列

        // BFS 过程
        while(q.size()) { // 当队列不空的时候，就不断将节点入队
            auto t = q.front(); // 取当前点 t 
            q.pop(); // 当前点出队

            // 枚举当前点的 4 个位置
            for (int i = 0; i < 4; i ++ ) {
                // 枚举当前点 t 的 i 位可能的变化：-1 或 +1 
                for (int j = -1; j <= +1; j += 2) {
                    string point = t; // 由于每次循环都会修改当前的点，所以先保存当前的点
                    // 对点 t 的 i 位进行修改：先 char 转 int +j，再 -1 或 + 1，最后 int 转 char（ 注：+ 10 ) % 10 是为了实现 0 和 9 的转化 ）
                    point[i] = (((point[i] - '0') + j) + 10) % 10 + '0'; 
                    // 如果修改后的点在哈希集合中不存在（说明可以转化成这个点）
                    // 且如果在哈希表中不存在（说明还没被转化过，到起点的距离也就没计算过）
                    if (!S.count(point) && !dist.count(point)) {
                        // 计算当前转换后的点 point 到起点的距离：在点 t 的基础上 +1
                        dist[point] = dist[t] + 1; 
                        // 如果当前已经转换到了终点，则返回当前这条起点到终点的路径的边数
                        if (point == target) { 
                            return dist[point];
                        }
                        // 将新转换的点入队
                        q.push(point); 
                    }
                }
            }
        }
        // 如果走不到终止状态，返回 -1
        return -1; 
    }
};


// 无注释版本

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        if (start == target) return 0;

        unordered_set<string> S;
        for (int i = 0; i < deadends.size(); i ++ ) S.insert(deadends[i]);

        if (S.count(start)) return -1; 

        unordered_map<string, int> dist;
        dist[start] = 0;

        queue<string> q;
        q.push(start);

        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i ++ ) {
                for (int j = -1; j <= +1; j += 2) {
                    string point = t;
                    point[i] = (((point[i] - '0') + j) + 10) % 10 + '0';

                    if (!S.count(point) && !dist.count(point)) {
                        dist[point] = dist[t] + 1;
                        if (point == target) {
                            return dist[point];
                        }
                        q.push(point);
                    }
                }
            }
        }

        return -1;
    }
};


