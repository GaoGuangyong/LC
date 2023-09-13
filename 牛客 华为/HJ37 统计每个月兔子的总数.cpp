


// 题目描述：
// 有一种兔子，从出生后第 3 个月起每个月都生 1 只兔子，小兔子长到第 3 个月后每个月又生 1 只兔子
// 例子：假设 1 只兔子第 3 个月出生，那么它第 5 个月开始会每个月生 1 只兔子
// 一月的时候有 1 只兔子，假如兔子都不死，问第 n 个月的兔子总数为多少 ？

// 输入：n 表述第 n 个月，输出：兔子的总数

// DP
// 斐波那契数列

#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    // 读入月数 n
    int n;
    cin >> n;

    // 状态表示：f[i] 表示第 i 个月时的兔子总数（下标从 1 开始，长度必须是 n + 1）
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


// 二刷
// 递推写法
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f(n + 1);

    f[1] = 1;
    f[2] = 1;

    for (int i = 3; i <= n; i ++ ) {
        f[i] = f[i - 1] + f[i - 2];
    }

    cout << f[n] << endl;

    return 0;
}

// 滚动数组写法（推荐）
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 0; // 第 0 个月的兔子数
    int b = 1; // 第 1 个月的兔子数

    while (n -- ) {
        int c = a + b;
        a = b;
        b = c;
    }
    
    cout << a << endl;

    return 0;
}
