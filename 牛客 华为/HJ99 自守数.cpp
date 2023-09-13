

// 题意：
// 自守数是指一个数的平方的尾数等于该数自身的自然数。例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376
// 请求出 n (包括n) 以内的自守数的个数


// 枚举，字符串比较法 -> substr

#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int n;
    cin >> n;

    int res = 1; // 0 属于自守数

    string s;
    string pow;

    // 从 1 枚举到 n
    for (int i = 1; i <= n; i ++ ) {
        s = to_string(i); // 将 当前数字 转换为字符串 
        pow = to_string(i * i); // 将 当前数字的平方 转换为字符串

        // 判断 i * i 的末尾是否等于 i（从 pow[pow.size() - s.size()] 开始截取到结尾）
        if (pow.substr(pow.size() - s.size()) == s) res ++ ;
    }

    cout << res << endl;
    
    return 0;
}


