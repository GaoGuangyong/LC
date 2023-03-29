
// AcWing 算法基础课模板题 860

// 染色法判定二分图
// 二分图 当且仅当 图中不含奇数环（奇数环：一个环的边数为奇数）
// 通过染色法我们可以判断一个无向图是否是二分图：
// 初始时，所有的图都是为染色状态（-1）
// 遍历整个图, 将相邻的节点染成不同的颜色（0 或 1）, 如果可以完成这个遍历 (即染色过程没有冲突), 说明是二分图
// 用 dfs 来实现, 根据当前节点的颜色设定下一个节点的颜色， 如果下一个节点已经被染成了相同的颜色, 说明发生了冲突

class Solution {
public:
    // 全局变量
    vector<int> color; // 颜色数组
    vector<vector<int>> graph; // 邻接表

    // DFS 函数：将当前节点 u，染色成 c
    bool dfs(int u, int c) {
        color[u] = c; // 将当前节点染成 c 颜色

        // 遍历与当前节点 v 相邻的所有节点
        for (int v: graph[u])
            // 若相邻节点已染色
            if (color[v] != -1) {
                // 若相邻节点的颜色和当前节点的颜色相同，则冲突，染色失败
                if (color[v] == c) {
                    return false;
                }
            }
            // 若相邻节点未染色，则将相邻节点染成和当前节点不同的颜色：c ^ 1: 0 变 1，1 变 0
            // 如果染色相邻节点时出现冲突，则染色失败，说明不是二分图
            else if (dfs(v, c ^ 1) == false) {
                return false;
            }
        return true;
    }

    bool isBipartite(vector<vector<int>>& _graph) { 
        graph = _graph; // graph[i] 表示图中与节点 i 相连的所有节点
        color = vector<int>(graph.size(), -1); // 先都初始化成 -1 表示未染色

        // 枚举所有的点
        for (int i = 0; i < graph.size(); i ++ ) {
            // 如果当前节点未染色，就 dfs 将其染色成 0
            if (color[i] == -1) {
                // 如果 dfs 染色时出现冲突，则染色失败，说明不是二分图
                if (dfs(i, 0) == false) {
                    return false;
                }
            }
        }
        // 如果枚举完了所有的节点，均未出现染色冲突，则染色成功，说明是二分图
        return true;
    }
};



