

// 题意：
// 输入一个字符串和一个整数 k ，截取字符串的前k个字符并输出

// 库函数 substr()

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    cout << s.substr(0, k) << endl;

    return 0;
}
