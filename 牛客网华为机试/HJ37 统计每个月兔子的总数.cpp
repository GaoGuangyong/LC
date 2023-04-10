




// DP
// 斐波那契数列

#include<iostream>
#include<vector>
using namespace std;
 
int main() {
    // 读入月数 n
    int n;
    cin >> n;

    // 状态表示：f[i] 表示第 i 个月时的兔子总数
    vector<int> f(n + 1);

    // 初始化：前 2 个月都只有 1 只兔子
    f[1] = 1;
    f[2] = 1;
    
    // 从第 3 个月开始，后面的每个月由前面的累加
    for (int i = 3; i <= n; i ++ ) { 
        f[i] = f[i - 1] + f[i - 2];
    }

    cout << f[n] << endl;
    
    return 0;
}

