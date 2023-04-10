

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    // 读入字符串 s
    string s;
    cin >> s;

    // 反转后输出
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}

