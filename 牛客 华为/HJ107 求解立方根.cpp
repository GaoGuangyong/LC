

// 特殊二分
// 通过二分求 x 的立方根，关键在于边界的确定
// x > 1，     x 的立方根的范围为 [1 ~ x]
// -1 < x < 1，x 的立方根的范围为 [-1 ~ 1]
// x <-1，     x 的立方根的范围为 [x ~ -1]

#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

double cal(double x) { 
    double l, r;

    if (x < -1) {
        l = x;
        r = -1;
    }
    else if (x > 1) {
        l = 1;
        r = x;
    }
    else if (-1 <= x && x <= 1) {
        l = -1;
        r = 1;
    }

    double mid;
    
    // 只要 l 和 r 的差值不小于等于 0.01 就一直循环
    while (abs(r - l) > 0.01) { // 精度值（因为保留 1 位，故取 0.01 即可）
        mid = (l + r) / 2;
        // 如果当前的立方 > x，则缩小 r，搜索区间变为 [l ~ mid]
        if (mid * mid * mid > x)
            r = mid;
        // 如果当前的立方 <= x，则扩大 l，搜索区间变为 [mid ~ r]
        else
            l = mid;
    }

    // 当 l 和 r 的差值 <= 0.01 时，返回结果
    return mid;
}
 
int main() {
    double val;
    cin >> val;
    cout << fixed << setprecision(1) << cal(val);
    // printf("%.1f\n", cal(val)); // 控制小数位输出
    
    return 0;
}