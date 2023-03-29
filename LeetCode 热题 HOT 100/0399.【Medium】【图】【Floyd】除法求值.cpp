
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
        // 存顶点
        unordered_set<string> vers; // 每个点是一个字母构成的字符串，用 string
        // 存边
        unordered_map<string, unordered_map<string, double>> d; // key: 顶点 value: 顶点->权值

        // 枚举所有的方程，建立图结构
        for (int i = 0; i < equations.size(); i ++ ) {
            string a = equations[i][0]; // 除数
            string b = equations[i][1]; // 被除数
            double c = values[i];       // a / b 的结果
            d[a][b] = c; 
            d[b][a] = 1 / c;
            vers.insert(a), vers.insert(b); // 将 a, b 加入顶点集合
        }

        // Floyd 算法的应用
        for (string k: vers) // 遍历点 k
            for (string i: vers) // 遍历点 i
                for (string j: vers) // 遍历点 j
                    if (d[i][k] && d[j][k]) // 如果 i -> k 和 k -> j 存在
                        d[i][j] = d[i][k] * d[k][j]; // i -> j 的距离就是 i 到 k 的距离 * k 到 j 的距离
 
        vector<double> res; // 结果数组
        // 遍历查询数组
        for (vector<string> q: queries) {
            string a = q[0];
            string b = q[1];
            if (d[a][b]) // 如果 a -> b 的权值存在，则在结果数组中插入该权值
                res.push_back(d[a][b]);
            else // 如果 a -> b 的权值不存在，则在结果数组中插入 -1 
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
        unordered_map<string, unordered_map<string, double>> d;

        for (int i = 0; i < equations.size(); i ++ ) {
            string a = equations[i][0];
            string b = equations[i][1];
            double c = values[i];
            d[a][b] = c;
            d[b][a] = 1 / c;
            v.insert(a);
            v.insert(b);
        }

        for (string k: v) 
            for (string i: v)
                for (string j: v)
                    if (d[i][k] != 0 && d[j][k] != 0)
                        d[i][j] = d[i][k] * d[k][j];

        vector<double> res;

        for (auto query: queries) {
            string a = query[0];
            string b = query[1];
            if (d[a][b] != 0)
                res.push_back(d[a][b]);
            else   
                res.push_back(-1);
        } 

        return res;
    }
};
