

// 考察字符串的 substr 和 resize 函数

#include <iostream>
#include <string>
using namespace std;

int main() {
    // 读入字符串 s
    string s;
    cin >> s;

    // 当字符串的长度超过 8 时，不断的输出前 8 位，再截取剩余部分
    while (s.size() > 8) {
        cout << s.substr(0, 8) << endl;
        s = s.substr(8);
    } // 循环结束时， s 的长度就 <= 8 了

    // 将 s 的现有元素个数调至 8 个，多则删，少则补，其值为 '0'
    s.resize(8, '0');
    
    cout << s << endl;    
    return 0;
}


