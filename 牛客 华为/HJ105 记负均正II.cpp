
// 题意：输入 n 个数字，一行一个
// 第一行输出负数个数
// 第二行输出非负数的平均值，保留一位小数，如果没有非负数，则输出 0，结果保留 1 位小数

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int x;
    int sum = 0; // 非负数的和
    int cnt1 = 0; // 非负数的个数
    int cnt2 = 0; // 负数的个数

    while (cin >> x) {
        if (x >= 0) {
            cnt1 ++ ;
            sum += x;
        }
        else cnt2 ++ ;
    }

    cout << cnt2 << endl;

    if (cnt1 == 0) 
        cout << "0.0" << endl;
    else 
        cout << fixed << setprecision(1) << (double)sum / cnt1 << endl; 
        // printf("%.1f",  (double)sum / cnt1);

    return 0;
}

