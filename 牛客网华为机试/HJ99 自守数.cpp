

// 枚举，字符串比较法

#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int n;
    cin >> n;

    int res = 1; // 0 属于自守数

    string s;
    string pow_s;

    // 从 1 枚举到 n
    for (int i = 1; i <= n; i ++ ) {
        s = to_string(i); // 将当前数字转换为字符串 
        pow_s = to_string(i * i); // 将当前数字的平方转换为字符串

        // 判断 i * i 的末尾是否等于 i
        if (pow_s.substr(pow_s.size() - s.size()) == s) 
            res ++ ;
    }
    cout << res << endl;
    
    return 0;
}


