

// 题意：给定字符串，返回其中最长的回文子串的长度
// 双指针 -> LC 5

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int res = 0;

    // 枚举中心点
    for (int i = 1; i < s.size(); i ++ ) {
        // 计算以 i 为中心的奇数长度的回文子串长度
        int l = i - 1;
        int r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l -- ;
            r ++ ;
        } // 当循环结束时，l，r 指向的是边界外或第一个不一样的字符，最长回文串就是 [l + 1 ~ r - 1]
        res = max(res, (r - 1) - (l + 1) + 1);

        // 计算以 i 和 i + 1 为中心的偶数长度的回文子串长度
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


