

// 递归

#include <iostream>
#include <string>
using namespace std;

// 辅助函数：将真分数 x/y 转化为若干埃及分数的和
void calculate(long long x, long long y) {
    // 递归出口 1：如果分子为 1，则直接输出
    if (x == 1) {
        cout << 1 << "/" << y << endl;
        return;
    }
    // 递归出口 2：如果能约分，则直接约分
    if (y % x == 0) {
        cout << 1 << "/" << y / x << endl;
        return;
    }
    // 如果不能约分
    int z = y / x; // 商
    int w = y % x; // 余数
    cout << 1 << "/" << z + 1 << "+";
    calculate(x - w, y * (z + 1)); // 更新 x 和 y 的值，递归计算
}

int main() {
    char ch;
    long long x, y;
    // 读入若干行：形如 x / y 的真分数
    while (cin >> x >> ch >> y) {
        calculate(x, y);
    }
}

