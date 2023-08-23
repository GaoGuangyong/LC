
// DFS
// 题目翻译：给定有向图，输出从节点 0 到节点 n - 1 的所有路径

class Solution {
public:
    // 全局变量
    int n; // 节点个数
    vector<vector<int>> graph; // 表示图的邻接表，为了方便 DFS，将 graph 定义成全局变量
    vector<int> path; // 当前路径
    vector<vector<int>> res; // 所有路径

    // DFS 函数：从节点 u 开始递归遍历，在遍历过程中，将合法路径加入 res
    void dfs(int u) {
        // 选择 u
        path.push_back(u);
        
        if (u == n - 1) res.push_back(path); // 如果已经搜索到了终点，就将当前路径加入最终结果数组

        // DFS 所有 u 指向的节点 v
        for (int v: graph[u]) dfs(v);

        // 撤销选择
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& _graph) {
        graph = _graph;
        n = graph.size();

        dfs(0);
        return res;
    }
};


// 二刷
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> path;
    vector<vector<int>> res;
    int n;

    void dfs(int u) {
        path.push_back(u);
        if (u == n - 1) res.push_back(path);

        for (int v: graph[u]) dfs(v);

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& _graph) {
        graph = _graph;
        n = graph.size();

        dfs(0);
        return res;
    }
};