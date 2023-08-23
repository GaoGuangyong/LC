
// Floyd 算法
// 将原问题转化成求有向图中任意两点间的距离的问题，具体图参考笔记
// a / b = 2
// b / c = 3
// a 有一条指向 b 的边，权值为 2
// b 有一条指向 a 的边，权值为 1/2
// b 有一条指向 c 的边，权值为 3
// c 有一条指向 b 的边，权值为 1/3
// 则 a / c = 2 * 3 = 6
// 采用 Floyd 算法计算两点间的最短距离

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 定义集合：存顶点，每个点是一个字母构成的字符串，用 string
        unordered_set<string> v;
        // 定义哈希表：存边，例如 <顶点1 -> <顶点2 -> 权值>> 就用 e[顶点1][顶点2] = 权值 来表示
        unordered_map<string, unordered_map<string, double>> e; 

        // 枚举所有的方程，建立图结构
        for (int i = 0; i < equations.size(); i ++ ) {
            string a = equations[i][0]; // 分子 a：除数
            string b = equations[i][1]; // 分母 b：被除数
            double c = values[i];  // a / b 的结果
            e[a][b] = c;       // 记录 a / b 的结果
            e[b][a] = 1 / c;   // 记录 b / a 的结果
            v.insert(a); // 将 a 加入顶点集合
            v.insert(b); // 将 b 加入顶点集合
        }

        // 使用 Floyd 算法计算出所有点之间的距离
        for (string k: v) // 遍历中点 k
            for (string i: v) // 遍历左端点 i
                for (string j: v) // 遍历右端点 j
                    if (e[i][k] != 0 && e[j][k] != 0) // 如果 i -> k 和 k -> j 存在，则更新 i -> j 
                        e[i][j] = e[i][k] * e[k][j]; // i -> j 的距离就是 i 到 k 的距离 * k 到 j 的距离
 
        vector<double> res; // 结果数组

        // 遍历查询数组
        for (auto q: queries) {
            string a = q[0];  // 查询的分子
            string b = q[1];  // 查询的分母
            if (e[a][b] != 0) // 如果 a / b 的结果存在，则在结果数组中插入该权值
                res.push_back(e[a][b]);
            // 否则，如果 a / b 的结果不存在，则在结果数组中插入 -1 
            res.push_back(-1);
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> v;
        unordered_map<string, unordered_map<string, double>> e;

        for (int i = 0; i < equations.size(); i ++ ) {
            string a = equations[i][0];
            string b = equations[i][1];
            double c = values[i];
            e[a][b] = c;
            e[b][a] = 1 / c;
            v.insert(a);
            v.insert(b);
        }

        for (string k: v)
            for (string i: v)
                for (string j: v)
                    if (e[i][k] != 0 && e[j][k] != 0)
                        e[i][j] = e[i][k] * e[k][j];

        vector<double> res;

        for (auto q: queries) {
            string a = q[0];
            string b = q[1];
            
            if (e[a][b] != 0) res.push_back(e[a][b]);
            else res.push_back(-1);
        } 

        return res;
    }
};

