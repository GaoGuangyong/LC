

// 考察 stoi 函数
// 将 n 进制的字符串转化成十进制的整数
// stoi(字符串, 起始位置, n);

#include <iostream>
#include <string>

using namespace std;
 
int main() {
    string s;
    while (cin >> s) {
        // 将 16 进制的字符串转化成十进制整数
        cout << stoi(s, 0, 16) << endl;
    }
}


