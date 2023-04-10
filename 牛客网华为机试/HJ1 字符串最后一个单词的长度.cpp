

// 解法一：
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    // 输入有效则继续循环输入，遇到结束符、输入无效或者流异常，则退出循环
    while (cin >> s) { 
    
    } // 循环结束时，s 存的就是最后一个单词 

    cout << s.size();
    return 0;
}

// 解法二：
#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    // 读入一行字符串
    string s;
    getline(cin, s);
    
    int res = 0;
    
    // 从后往前枚举 s，当遇到非空格，长度就 + 1，直到遇到空格
    for (int i = s.size() - 1; i >= 0; i -- ) {
        if (s[i] != ' ') res ++ ;
        else break;
    }

    cout << res;
    return 0;
}

