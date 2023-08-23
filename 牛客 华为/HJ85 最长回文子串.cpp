

// 类似 LC 5

#include <iostream>
#include <string>
using namespace std;

int main() {
    // 读入字符串 s
    string s;
    cin >> s;

    int maxLen = 0;

    // 枚举中心点
    for (int i = 0; i < s.size(); i ++ ) {
        // 回文串的长度为奇数的情况（中心点为 i）
        int l = i - 1;
        int r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l -- ; 
            r ++ ;
        } // 当循环结束时，l，r 指向的是边界外或第一个不一样的字符，最长回文串就是 [l + 1 ~ r - 1]

        int len = (r - 1) - (l + 1) + 1; // 当前回文字符串长度

        maxLen = max(maxLen, len); // 更新最长回文子串的长度

        // 回文串的长度为偶数的情况（中心点为 i，i + 1）
        l = i;
        r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l -- ;
            r ++ ;
        } // 当循环结束时，l，r 指向的是边界外或第一个不一样的字符，最长回文串就是 [l + 1 ~ r - 1]

        len = (r - 1) - (l + 1) + 1; // 当前回文字符串长度

        maxLen = max(maxLen, len); // 更新最长回文子串的长度
    }

    cout << maxLen << endl;

    return 0;
}
