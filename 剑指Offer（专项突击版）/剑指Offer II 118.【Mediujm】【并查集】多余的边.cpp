
// 并查集
// 题意翻译：在无向图里找环，然后删掉环中的最后出现的那条边

// 在无向图中找环，最简单的方法是用并查集
// 出现环的条件是：加的这条边，边的两个端点原本就是连通的（即在同一个集合里），那么加上了这条边以后就产生了环

// 因此我们在加入每条边的时候需要判断一下边的两个端点是否在一个集合里
// 从前往后枚举所有的边，合并之前如果这条边对应的两个点已经在一个集合里，那么合并之后就必然会形成环，返回这条边即可


class Solution {
public:
    vector<int> p; // 定义并查集数组：表示每个节点的父节点

    // 并查集的模板函数：路径压缩，返回 x 所在集合的根节点
    int find(int x) {
        if (p[x] != x) { // 只要 x 不是根节点，就让它的父亲节点 p[x] 指向根节点
            p[x] = find(p[x]);
        }
        return p[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) { 
        int n = edges.size(); // 节点数量 n = 给定图的边数

        // 初始化并查集数组
        p.resize(n + 1); // 因为节点下标从 1 开始，所以 P 的大小为 n + 1
        for (int i = 1; i <= n; i ++ ) { // 注意：节点是从 1 开始标号的
            p[i] = i;
        }

        // 因为要找的是最后出现的那条边，所以从前往后合并所有的边
        for (auto& e : edges){ 
            int a = find(e[0]); // a 是第一个点的根节点
            int b = find(e[1]); // b 是第二个点的根节点
            if (a != b) p[a] = b; // 若 a != b，即 a 和 b 不属于同一个集合，则合并后不会出现环，将 a 和 b 合并
            else return e; // 否则，若 a 和 b 属于同一个集合，则合并后会出现环，即这条边就是所求
        }
        
        return {}; // 这里不会执行，但必须写上
    }
};


// 二刷
class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        p.resize(n + 1);
        for (int i = 1; i <= n; i ++ ) p[i] = i;

        for (auto e: edges) {
            int a = find(e[0]);
            int b = find(e[1]);
            if (a != b) p[a] = b;
            else return e;
        }

        return {};
    }
};
