

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 读入一个 int 正数
    int i;
    cin >> i;

    // 将其转化成字符串
    string s;
    s = to_string(i);

    // 反转后输出
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}

