
// 数学 -> LC 507
// 题意：完全数 x：除自身以外的约数和 == x 

#include <iostream>
using namespace std;

bool check(int num) {
    // 特判：1 的约数只有本身，不是完美数
    if (num == 1) return false;    

    int sum = 1;

    // 从 2 枚举到 根号 num（后面的因数就是重复的了，如 4 * 7 = 7 * 4）
    for (int i = 2; i * i <= num; i ++ ) {
        // 如果 i 能被 num 整除，则两个因数是 i 和 num / i
        if (num % i == 0) {
            sum += i;
            // 注意：如果两个因数相同时，不能重复计算
            if (i != num / i) 
                sum += num / i;
        }
    }
    return sum == num;
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

