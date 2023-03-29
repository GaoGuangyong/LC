// https://leetcode.cn/problems/ur2n8P/solution/tuo-bu-pai-xu-by-linke66-n-ml2n/

// 拓扑排序 + BFS
// 拓扑排序思路：
// [1] 统计所有点的入度 d[]
// [2] 将所有入度为 0 的点 d[i] 加入队列（队列维护的就是所有入度为 0 的点）
// [3] 用一个宽搜的框架，每次从队头取一个点
// [4] 将这个点指向的点的入度-1，如果某个节点在 -1 后，入度变成了 0，则这个节点可以加入队列
// [5] 宽搜结束后，判断一下是不是所有的点都被遍历过？即是不是所有的节点都入队了？如果是，则说明是有向无环图，存在拓扑序，原问题有解

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();

        vector<int> res;

        // 定义邻接表
        vector<vector<int>> graph(n); // n * n
        // 存入度的数组
        vector<int> d(n); 

        // 构建邻接表：将所有的边插入邻接表
        for (auto& e: sequences) {
            // 边数组 e 的长度 ≥ 2，因此需要全部枚举
            for (int i = 0; i < e.size() - 1; i ++ ) {
                // 因为 nums 中元素的取值范围为 [1 ~ n]，为方便将其转化到 [0 ~ n - 1]
                int a = e[i] - 1; // 起点
                int b = e[i + 1] - 1; // 终点 
                graph[a].push_back(b); // 向第 a 行的数组中 插入 b，代表 a -> b 的边
                d[b] ++ ; // b 的入度 + 1
            }
        }

        queue<int> q; // BFS 队列

        // 遍历 0 ~ n - 1，将所有入度为 0 的点加入队列
        for (int i = 0; i < n; i ++ ) {
            if (d[i] == 0) q.push(i);  // 如果当前点的入度为 0，则加入队列
        }

        // BFS 过程
        while (q.size()) { // 只要队列不空，就不断将节点入队
            // 若队列的大小 不是 1，即存在多个入度为 0 的点，则会有多个超序列，直接返回 false
            if (q.size() != 1) return false; 

            // 若队列的大小 是 1，取出队头节点（唯一的入度为 0 的点）
            auto t = q.front();
            q.pop();
            // 将队头节点插入 res 中，注意要 + 1（因为建图的时候 - 1 了）
            res.push_back(t + 1);

            // 枚举当前节点的所有后继节点，将每条边删去，即后继节点的入度 -1，如果入度降为 0，再加入队列
            for (int i: graph[t]) {
                // 将后继节点 i 的入度 -1
                d[i] --; 
                // 如果入度降为 0，再加入队列
                if (d[i] == 0) q.push(i);
            }
        }

        return res == nums;
    }
};


// 无注释版本
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();

        vector<int> res;

        vector<vector<int>> graph(n);
        vector<int> d(n); 

        for (auto& e: sequences) {
            for (int i = 0; i < e.size() - 1; i ++ ) {
                int a = e[i] - 1;
                int b = e[i + 1] - 1;
                graph[a].push_back(b);
                d[b] ++ ;
            }
        }

        queue<int> q; 

        for (int i = 0; i < n; i ++ ) {
            if (d[i] == 0) q.push(i);
        }
        
        while (q.size()) { 
            if (q.size() != 1) return false; 

            auto t = q.front();
            q.pop();
            res.push_back(t + 1);
            
            for (int i: graph[t]) {
                d[i] --; 
                if (d[i] == 0) q.push(i);
            }
        }

        return res == nums;
    }
};

