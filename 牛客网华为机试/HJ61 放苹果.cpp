
// 题意：求把 m 个苹果放到 n 个盘子里的方案数


// 解法一：DFS
#include <iostream>
using namespace std;

// DFS 函数：返回把 m 个苹果放到 n 个盘子里的方案数
int dfs(int m, int n) {
    // 递归出口
    if (m == 0) return 1; // 如果苹果的数量为 0，则只有一种方案（即盘子全空着）
    if (n == 1) return 1; // 如果盘子的数量为 1，则只有一种方案（即全放进去）

    // DFS 过程
    // 如果苹果数量 < 盘子的数量，则等于 把 m 个苹果放到 m 个盘子的方案数
    if (m < n) return dfs(m, m); 

    // 如果苹果数量 >= 盘子的数量，则等于 空一个盘子的方案数 + 一个盘子都不空的方案数
    // 一个盘子都不空，即先把 n 个苹果放到 n 个盘子里，每个盘子放一个，再把剩下的 m - n 个苹果放到 n 个盘子里
    return dfs(m, n - 1) + dfs(m - n, n);
}

int main() {
    // 读入苹果数量 m 和盘子数量 n
    int m, n;
    cin >> m >> n;

    // 输出摆放方案数
    cout << dfs(m, n) << endl;
    
    return 0;
}


// 解法二：DP
// 例如：m = 5,  n = 2，则有 {0, 5} {1, 4} {2, 3} 共3种方法，即 f[5][2] = 3
// {0, 5} 这种方案即为 f[5][1]
// {1, 4}, {2, 3} 这两种方案等价于 {0, 3}, {1, 2}, 即 f[3][2]
// 故 f[5][2] = f[5][1] + f[3][2]


#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 读入苹果数量 m 和盘子数量 n
    int m, n;
    cin >> m >> n;

    // 状态表示：f[i][j] 表示把 i 个苹果放到 j 个盘子里的方案数
    vector<vector<int>> f(m + 1, vector<int>(n + 1));   

    // 初始化
    for (int i = 1; i <= n; i ++ ) f[0][i] = 1; // 苹果数量为 0 的，方案数为 1
    for (int i = 1; i <= m; i ++ ) f[i][1] = 1; // 盘子数置为 1 的，方案数为 1
    
    // 状态转移
    for (int i = 1; i <= m; i ++ ) { 
        for (int j = 1; j <= n; j++) {
            // 如果苹果数量 < 盘子的数量，则等于 把 i 个苹果放到 i 个盘子的方案数
            if (i < j) f[i][j] = f[i][i];
            // 如果苹果数量 >= 盘子的数量，则等于 空一个盘子的方案数 + 一个盘子都不空的方案数
            // 一个盘子都不空，即先把 i 个苹果放到 i 个盘子里，每个盘子放一个，再把剩下的 i - j 个苹果放到 j 个盘子里
            else f[i][j] = f[i][j - 1] + f[i - j][j];
        }
    }

    cout << f[m][n] << endl;

    return 0;
}

