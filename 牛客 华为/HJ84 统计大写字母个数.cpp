

// 考察 isupper 库函数

#include <iostream>
#include <string>
using namespace std;
 
int main() {
    // 读入一行字符串
    string s;
    getline(cin, s);

    int res = 0;

    // 遍历字符串 s，用库函数检查是否是大写字母
    for (int i = 0; i < s.size(); i ++ ) {
        if (isupper(s[i])) res ++ ;
    }

    cout << res << endl;
    
    return 0;
}


