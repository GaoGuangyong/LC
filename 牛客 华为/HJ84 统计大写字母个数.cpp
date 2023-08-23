

// 考察 isupper 库函数

#include <iostream>
#include <string>
using namespace std;
 
int main() {
    // 读入一行字符串
    string str;
    getline(cin, str);

    int res = 0;

    // 遍历字符串 str，用库函数检查是否是大写字母
    for (int i = 0; i < str.size(); i ++ ) {
        if (isupper(str[i]) != 0) res ++ ;
    }

    cout << res << endl;
    
    return 0;
}


