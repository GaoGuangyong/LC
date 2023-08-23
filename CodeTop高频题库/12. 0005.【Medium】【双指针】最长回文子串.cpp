
// 给你一个字符串 s，找到 s 中最长的回文子串。

// 双指针
// 回文串分两种：长度为奇数 && 长度为偶数
// 先枚举中心点，然后用两个指针从中心点往两边枚举，直到枚举到的两个字符不一样或走到边界为止
// 这样就可以找到以这个中心点为中心的最长回文串

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        string res;

        // 枚举中心点
        for (int i = 0; i < n; i ++ ) {
            // 回文串的长度为奇数的情况
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) { // 枚举中心点
                l -- ; 
                r ++ ;
            } // 当循环结束时，l，r 指向的是边界外或第一个不一样的字符，最长回文串就是 [l + 1 ~ r - 1]

            int len = (r - 1) - (l + 1) + 1; // 当前回文字符串长度

            if (res.size() < len) { // 如果之前的回文串长度 < 当前的回文串，则把当前的回文串更新为最长回文串
                res = s.substr(l + 1, len);
            }

            // 回文串的长度为偶数的情况
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l -- ;
                r ++ ;
            } // 当循环结束时，l，r 指向的是边界外或第一个不一样的字符，最长回文串就是 [l + 1 ~ r - 1]

            len = (r - 1) - (l + 1) + 1; // 当前回文字符串长度

            if (res.size() < len) { // 如果之前的回文串长度 < 当前的回文串，则把当前的回文串更新为最长回文串
                res = s.substr(l + 1, len);
            }
        }

        return res;
    }
};


// 二刷
class Solution {
public:
    string longestPalindrome(string s) {
        string res;

        int n = s.size();

        for (int i = 0; i < n; i ++ ) {
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l -- ;
                r ++ ;
            }
            int len = (r - 1) - (l + 1) + 1;
            if (len > res.size()) res = s.substr(l + 1, len);

            l = i;
            r = i + 1;
            while (l >=0 && r < n && s[l] == s[r]) {
                l -- ;
                r ++ ;
            }
            len = (r - 1) - (l + 1) + 1;
            if (len > res.size()) res = s.substr(l + 1, len);
        }

        return res;
    }
};