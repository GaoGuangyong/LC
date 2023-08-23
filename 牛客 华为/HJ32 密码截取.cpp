

// 题意：给定字符串，返回其中最长的回文子串的长度

// 输入描述：
// 输入一个字符串（字符串的长度不超过2500）

// 输出描述：
// 返回有效密码串的最大长度



// 回文字符串问题 -> 双指针 -> LC 5

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
    string s;
    cin >> s;

    int res = 0; // 最长回文子串的长度

    // 枚举中心点 i
    for (int i = 0; i < s.size(); i ++ ) {
        // 计算以 i 为中心点的长度为奇数的回文子串长度
        int l = i - 1;
        int r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l -- ;
            r ++ ;
        } // 当循环结束时，l，r 指向的是边界外或第一个不一样的字符，最长回文串就是 [l + 1 ~ r - 1]
        
        res = max(res, (r - 1) - (l + 1) + 1);

        // 计算以 i 和 i + 1 为中心的长度为偶数的回文子串长度
        l = i;
        r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l -- ;
            r ++ ;
        }
        res = max(res, (r - 1) - (l + 1) + 1); 
    }

    cout << res << endl;
    
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int res = 0;

    int n = s.size();

    for (int i = 0; i < n; i ++ ) {
        int l = i - 1;
        int r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l -- ;
            r ++ ;
        }
        res = max(res, (r - 1) - (l + 1) + 1);

        l = i;
        r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l -- ;
            r ++ ;
        }
        res = max(res, (r - 1) - (l + 1) + 1);
    }

    cout << res << endl;

    return 0;
}