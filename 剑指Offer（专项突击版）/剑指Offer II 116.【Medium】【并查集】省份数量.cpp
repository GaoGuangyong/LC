// 并查集

// https://www.acwing.com/solution/content/33345/

// 如果两个城市之间有边，就把这两个城市合并为一个集合，最后集合的数量就是省份的数量

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

    // 主函数
    int findCircleNum(vector<vector<int>>& isConnected) { 
        int n = isConnected.size();

        // 初始化并查集数组
        p.resize(n);
        for (int i = 0; i < n; i ++ ) {
            p[i] = i;
        }
        
        // 答案：省份数量
        int res = n;  // 初始时，每个城市都是独立的，省份数量为 n

        // 枚举 isConnected 矩阵，对于相连的城市进行合并
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                // 若 i 与 j 之间直接相连，且 i 与 j 不在同一个集合里，则把这两个点所在的集合合并
                if (isConnected[i][j] == 1 && find(i) != find(j)) {
                    p[find(i)] = find(j); // 合并集合：将 i 所在集合的根节点指向 j 所在集合的根节点
                    res -- ; // 每合并一次，集合的数量就 -1 
                } 
            }
        }
        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    int findCircleNum(vector<vector<int>>& isConnected) { 
        int n = isConnected.size();
        
        p.resize(n);
        for (int i = 0; i < n; i ++ ) {
            p[i] = i;
        }
        
        int res = n; 

        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (isConnected[i][j] == 1 && find(i) != find(j)) {
                    p[find(i)] = find(j);
                    res --; 
                } 
            }
        }
        return res;
    }
};


