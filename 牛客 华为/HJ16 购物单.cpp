


// 分组背包 --> 模板题：AcWing 487 金明的预算方案

// https://www.acwing.com/solution/content/3803/
// https://www.acwing.com/solution/content/55745/

// 可以将每个主件及其附件看作一个物品组，记主件为 p，两个附件为 a,b，则最多一共有4种组合：
// p
// p,a
// p,b
// p,a,b

// 附件数为 x，则共有 2^x 种组合
// 这四种组合是互斥的，最多只能从中选一种，因此可以将每种组合看作一个物品，那么问题就变成了分组背包问题


#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

int N = 70;    // 可以购买的物品数的最大值
int M = 32010; // 能花费价格的最大值

vector<PII> master(N); // 主件数组，master[i] 表示第 i 个主件，{物品体积，物品价格}
vector<vector<PII>> servent(N); // 附件数组，servent[i][j] 表示第 i 个主件的第 j 个附件，{物品体积，物品价格}

vector<vector<int>> f(N, vector<int>(M)); // f[i][j] 表示从前 i 组物品中选，总体积不大于 j 的选法中，价值的最大值

int main() {
    // 读入钱数 m 和 物品数 n
    int m, n;
    cin >> m >> n;

    // 遍历 n 行，初始化主件数组 & 附件数组
    for (int i = 1; i <= n; i ++ ) {
        // 读入物品价格 v，重要度 p（1 ~ 5），物品类型 q（0：主件，> 0：附件所属的主件编号）
        int v, p, q;
        cin >> v >> p >> q;
        
        if (q == 0) master[i] = {v, v * p}; // 如果是主件，则加入主件数组
        else servent[q].push_back({v, v * p}); // 否则，如果是附件，则加入附件数组
    }

    // 枚举物品数 1 ~ n
    for (int i = 1; i <= n; i ++ ) {
        // 背包容量 0 ~ m
        for (int j = 0; j <= m; j ++ ) {
            f[i][j] = f[i - 1][j]; // 不选第 i 个主件，则从前 i - 1 个物品里凑体积 j

            for (int k = 0; k < pow(2, servent[i].size()); k ++ ) { // 外层循环遍历所有主件
                int v = master[i].first;  // v 表示第 i 个主件的 体积
                int w = master[i].second; // w 表示第 i 个主件的 价格
                for (int t = 0; t < servent[i].size(); t ++ ) { // 内层循环枚举外层主件的所有附件
                    // 如果 k 的第 t 位是 1，则有附件，选取第 i 个主件的第 t 个物品
                    if ((k >> t) & 1 == 1) {
                        v += servent[i][t].first;
                        w += servent[i][t].second;
                    }
                }
                // 选第 i 个主件，则，则从前 i - 1 个物品里凑体积 j - v，再加上第 i 个主件的价格
                if (j >= v) f[i][j] = max(f[i][j], f[i - 1][j - v] + w);
            }
        }
    }

    cout << f[n][m] << endl;

    return 0;
}




