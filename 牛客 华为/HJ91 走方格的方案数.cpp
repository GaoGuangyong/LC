

// 题意：
// 请计算 n*m 的棋盘格子，从棋盘左上角出发沿着边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
// 注：沿棋盘格之间的边缘线行走

// 输入两个正整数 n 和 m，用空格隔开
// 输出一行结果

// 输入：
// 2 2

// 输出：
// 6

// DP

#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    // 读入矩阵的行数 n 和列数 m
    int n, m;
    cin >> n >> m;

    // 状态表示：f[i][j] 表示从左上角（0，0）走到（i，j）的路径数
    vector<vector<int> > f(n + 1, vector<int>(m + 1));
    
    // 初始化，因为是沿着边走，所以 i ∈ [0, n]，j ∈ [0， m]
    for (int i = 0; i <= n; i ++ ) f[i][0] = 1; // 最左边的边上的点，只能从其上边的点走过来，方案数均为 1
    for (int j = 0; j <= m; j ++ ) f[0][j] = 1; // 最上边的边上的点，只能从其左边的点走过来，方案数均为 1

    // 状态转移
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            f[i][j] = f[i][j - 1] + f[i - 1][j]; // 其余的点，既可以从其上边走过来，也可以从其左边走过来，将两种情况相加
        }
    }

    // 答案为 f[n][m] 而不是 f[n - 1][m - 1]，因为是沿着边走，而不是沿着格子走
    cout << f[n][m] << endl;
    
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> f(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i ++ ) f[i][0] = 1;
    for (int j = 0; j <= m; j ++ ) f[0][j] = 1;

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            f[i][j] = f[i][j - 1] + f[i - 1][j];
        }
    }

    cout << f[n][m] << endl;

    return 0;
}
