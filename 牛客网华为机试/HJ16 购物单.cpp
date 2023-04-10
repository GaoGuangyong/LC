

// AcWing 487 金明的预算方案
// 分组背包
// https://www.acwing.com/solution/content/3803/
// https://www.acwing.com/solution/content/55745/
// 可以将每个主件及其附件看作一个物品组，记主件为 p，两个附件为 a,b，则最多一共有4种组合：
// p
// p,a
// p,b
// p,a,b
// 这四种组合是互斥的，最多只能从中选一种，因此可以将每种组合看作一个物品，那么问题就变成了分组背包问题

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> PII;

const int N = 70; // 必须写成 const !!!
const int M = 32010;

PII master[N]; // 主件数组
vector<PII> servent[N]; // 附件数组

int f[N][M]; // f[i][j] 表示从前 i 组物品中选，总体积不大于 j 的选法中，价值的最大值

int main() {
    // 读入物品数 n 和钱数 m
    int n, m;
    cin >> m >> n;
    // 遍历 n 个物品
    for (int i = 1; i <= n; i ++ ) {
        // 读入物品价格 v，重要度 p（1 ~ 5），物品类型 q（0：主件，> 0：附件编号）
        int v, p, q;
        cin >> v >> p >> q;
        // 如果是主件，则加入主件数组 {体积，价值}
        if (q == 0) master[i] = {v, v * p};
        // 如果是附件，则加入附件数组 {体积，价值}
        else servent[q].push_back({v, v * p});
    }

    // 枚举物品数 n
    for (int i = 1; i <= n; i ++ ) {
        // 背包容量
        for (int j = 0; j <= m; j ++ ) {
            f[i][j] = f[i - 1][j]; // 这是不选的情况

            for (int k = 0; k < (1 << servent[i].size()); k ++ ) {
                int v = master[i].first; // 体积 v
                int w = master[i].second; // 价值 w

                for (int t = 0; t < servent[i].size(); t ++ ) {
                    if ((k >> t) & 1 != 0) { // 如果选取了主件 i 的附件集合中的第 t 个物品
                        v += servent[i][t].first;
                        w += servent[i][t].second;
                    }
                }
                if (j >= v)     
                    f[i][j] = max(f[i][j], f[i - 1][j - v] + w);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
