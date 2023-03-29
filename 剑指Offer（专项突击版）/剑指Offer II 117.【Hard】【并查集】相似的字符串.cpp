
// 并查集
// 将 strs 中的字符串看成图中的点，两个字符串相似就连一条边，问题就转换成了问图中有多少个连通块
// 用并查集维护连通块的数量即可
// 对于相似的字符串，我们用并查集把他们合并
// 最后，并查集中集合的个数就是答案

class Solution {
public:
    int n; // 字符串的数量
    vector<int> p; // 并查集数组：表示每个集合的父节点

    // 并查集的模板函数：路径压缩
    // 递归找 x 所在集合的根节点，即返回 x 所在集合的编号
    int find(int x) { // x 表示元素下标
        if (p[x] != x) { // 只要 x 不是根节点，就让它的父亲节点 p[x] 指向祖先节点
            p[x] = find(p[x]);
        }
        return p[x];
    }

    // 辅助函数：检查字符串 a 与字符串 b 是否具有相似性
    bool check(string& a, string& b) {
        // 特判：如果两个字符串相同，则肯定具有相似性
        if (a == b) return true;
        // 定义一个数组 diff 来存字符串中不一样字符的下标
        vector<int> q;
        for (int i = 0; i < a.size(); i ++ ) {
            if (a[i] != b[i]) {
                q.push_back(i);
            }
        }
        // 如果不一样字符的数量不是 2 个，则不相似
        if (q.size() != 2) return false;

        // 否则，只有这 2 个下标的字符串不一样，才相似
        int x = q[0]; // 第 1 个不一样字符的下标
        int y = q[1]; // 第 2 个不一样字符的下标
        // 如果 字符串 a 的 x 位 == 字符串 b 的 y 位 && 字符串 a 的 y 位 == 字符串 b 的 x 位，则相似
        return a[x] == b[y] && a[y] == b[x];
    }

    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();

        // 初始化并查集数组
        p.resize(n);
        for (int i = 0; i < n; i ++ ) {
            p[i] = i;
        }

        int res = n;  // 初始时，每个节点都是一个单独的集合，集合数量是 n

        // 枚举节点间的边
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                // 若 str[i] 与 str[j] 之间相似，且 i 与 j 不在同一个集合里，则需要把这两个集合合并
                if (check(strs[i], strs[j]) && find(i) != find(j)) {
                    // 合并集合：将 i 所在集合的根节点指向 j 所在集合的根节点
                    p[find(i)] = find(j); 
                    // 每合并一次，集合的数量就 -1 
                    res -- ; 
                } 
            }
        }
        return res;
    }
};


