

// 题意：
// 完全数 x：除自身以外的约数和 == x 
// 输入 n，输出 <= n 的完全数的个数

// 数学 -> LC 507


#include <iostream>
using namespace std;

bool check(int x) {
    // 特判：1 的约数只有本身，不是完美数
    if (x == 1) return false;    

    int sum = 1;

    // 从 2 枚举到 根号 x（后面的因数就是重复的了，如 4 * 7 = 7 * 4）
    for (int i = 2; i * i <= x; i ++ ) {
        // 如果 i 能被 x 整除，则两个因数是 i 和 x / i，注意：如果两个因数相同时，不能重复计算
        if (x % i == 0) {
            sum += i;
            if (i != x / i) sum += x / i;
        }
    }

    return sum == x;
}

int main() {
    int n;
    cin >> n;

    int res = 0;

    for (int i = 1; i <= n; i ++ ) {
        if (check(i) == true) res ++ ;
    }

    cout << res << endl;
}

