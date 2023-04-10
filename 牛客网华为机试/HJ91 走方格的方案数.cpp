
// DP

#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    // 读入矩阵的行数 n 和列数 m
    int m, n;
    cin >> n >> m;

    // 状态表示：f[i][j] 表示从（0，0）走到（i，j）的路径数
    // 因为是沿着边走，所以 i ∈ [0, n]，j ∈ [0， m]
    vector<vector<int> > f(n + 1, vector<int>(m + 1));
    
    // 初始化
    for (int i = 0; i <= n; i ++ ) f[i][0] = 1; // 最左边的一条边上的点，只能从其上边的点走过来
    for (int j = 0; j <= m; j ++ ) f[0][j] = 1; // 最上边的一条边上的点，只能从其左边的点走过来

    // 状态转移
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) { 
            // 其余的点，既可以从其上边走过来，也可以从其左边走过来
            f[i][j] = f[i][j - 1] + f[i - 1][j];
        }
    }

    // 答案为 f[n][m] 而不是 f[n - 1][m - 1]，因为是沿着边走，而不是沿着格子走
    cout << f[n][m] << endl;
    
    return 0;
}



