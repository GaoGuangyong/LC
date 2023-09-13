


// 题意：
// 首先输入要输入的整数个数 n，然后输入 n 个整数。输出为 n 个整数中负数的个数，和所有正整数的平均值，结果保留一位小数
// 如果没有正数，则平均值为 0

// 输入：
// 11 
// 1 2 3 4 5 6 7 8 9 0 -1

// 输出：
// 1 5.0


// 枚举

#include <iostream>
using namespace std;

int main() {
    // 读入数字个数 n
    int n;
    cin >> n;

    int cnt1 = 0; // 负数个数
    int cnt2 = 0; // 正数个数
    int sum = 0; // 正数的和

    // 读入 n 个数
    while (n -- ) {
        int x;
        cin >> x;

        if (x < 0) cnt1 ++ ;
        
        else if (x > 0) {
            sum += x; //正数
            cnt2 ++ ;
        }
    }

    // 输出答案
    if (cnt2 == 0)
        printf("%d %.1f", cnt1, 0);
    else 
        printf("%d %.1f", cnt1, (double)sum / cnt2);

    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int negative = 0;
    int positive = 0;
    int sum = 0;

    while (n -- ) {
        int x;
        cin >> x;

        if (x < 0) negative ++ ;
        else if (x > 0) {
            positive ++ ;
            sum += x;
        }
    }

    if (positive == 0) 
        printf("%d %.1f", negative, 0);
    else 
        printf("%d %.1f", negative, (double)sum / positive);

    return 0;
}
