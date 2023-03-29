// 在 LC 207题 的基础上进行更改，不仅要判断能否完成课程，还要给出完成课程的先后顺序
// 拓扑排序 + BFS
// 对每对课程, 都连一条有向边：先修课程 -> 后修课程，则原问题有解 等价于 该有向图没有环（即存在拓扑序）
// 拓扑排序思路：
// [1] 统计所有点的入度 d[i]
// [2] 将所有入度为 0 的点 d[i] 加入队列（队列维护的就是所有入度为 0 的点）
// [3] 用一个 BFS 框架，每次从队头取一个点（这个点的入度已经是0了，说明这门课的先修课已经修完了），可以修这门课了
// [4] 将这个点指向的点的入度-1，如果某个节点在 -1 后，入度变成了 0，则这个节点可以加入队列，代表门课指向的课可以修了
// [5] 宽搜结束后，判断一下是不是所有的点都被遍历过？即是不是所有的节点都入队了？
//     如果是，则说明是有向无环图，存在拓扑序，原问题有解，即可以完成所有课程的学习

class Solution {
public:
    vector<int> findOrder(int numCourses , vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int> res; // 结果数组

        // 定义邻接表
        vector<vector<int>> graph(n);  // n * n
        // 入度数组
        vector<int> d(n); 

        // 实现邻接表：将所有的边插入邻接表
        for (auto& e: prerequisites) {
            int a = e[1]; // 起点 e[1]
            int b = e[0]; // 终点 e[0]
            graph[a].push_back(b); // 向第 a 行的数组中 插入 b，代表 a -> b 的边
            d[b] ++ ; // b 的入度 + 1
        }

        queue<int> q; // BFS 队列

        // 遍历课程 0 ~ n - 1，将所有入度为 0（没有先修课程）的点加入队列
        for (int i = 0; i < n; i ++ ) {
            if (d[i] == 0) q.push(i);
        }

        // BFS 过程
        while (q.size()) { // 当队列不空的时候
            auto t = q.front(); // 获取队头元素：当前节点 t
            q.pop();

            res.push_back(t); // 将当前节点 t 插入结果数组

            // 枚举当前节点 t 的所有后继节点，将每条边删去，即后继节点的入度 -1，如果入度降为 0，再加入队列
            for (int i: graph[t]) {
                // 将后继节点 i 的入度 -1 
                d[i] -- ;
                // 如果入度降为 0，再加入队列
                if (d[i] == 0) q.push(i);
            }
        }

        // 如果循环结束后 res 中的节点的个数与 图中节点的个数相同，则说明是有向无环图，可以进行拓扑排序, 返回 res
        if (res.size() == n)
            return res;
        else return {}; // 否则不可以拓扑排序，返回空数组 {}

    }
};


// 无注释版本
class Solution {
public:
    vector<int> findOrder(int numCourses , vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int> res;

        vector<vector<int>> graph(n);
        vector<int> d(n); 

        for (auto& e: prerequisites) {
            int a = e[1]; 
            int b = e[0];
            graph[a].push_back(b);
            d[b] ++ ;
        }

        queue<int> q;

        for (int i = 0; i < n; i ++ ) {
            if (d[i] == 0) q.push(i);
        }

        while (q.size()) {
            auto t = q.front();
            q.pop();

            res.push_back(t); 
            for (int i: graph[t]) {
                d[i] -- ;
                if (d[i] == 0) q.push(i);
            }
        }

        if (res.size() == n)
            return res;
        else return {};
    }
};
