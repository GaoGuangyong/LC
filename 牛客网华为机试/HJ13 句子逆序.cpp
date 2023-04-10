
// 同剑指 Offer 58-I

#include <iostream> 
#include <string>
using namespace std;

int main() {
    string res;

    // 不断读入空格分开的字符串，将当前读入的字符串插入到 res 前面
    string s;
    while (cin >> s) {
        res = s + " " + res;
    }
    cout << res;
    return 0;
}

