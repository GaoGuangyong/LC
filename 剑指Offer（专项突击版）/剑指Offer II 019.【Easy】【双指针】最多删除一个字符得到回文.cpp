// 双指针

class Solution {
public:
    // 辅助函数 1：判断字符串 s[l ~ r] 是不是回文串
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l ++ ;
            r -- ;
        }
        return true;
    }
    // 辅助函数 2：判断字符串 s[l ~ r] 是不是回文串
    bool isPalindrome(string s, int l, int r) {
        while (l < r && s[l] == s[r]) {
            l ++ ;
            r -- ;
        }
        return l >= r;
    }

    bool validPalindrome(string s) {
        // 从字符串的两端向中间枚举
        for (int l = 0, r = s.size() - 1; l < r; l ++ , r -- ) {
            if (s[l] != s[r]) { // 当遇到 2 个不相同的字符，就考虑删除其中一个字符，判断剩下的还能否构成回文串
                // 如果删除 s[l] 后 s[l + 1 ~ r] 是回文串 or 删除 s[r] 后 s[l ~ r - 1] 是回文串，则存在答案，返回 false
                if (isPalindrome(s, l + 1, r) == true || isPalindrome(s, l, r - 1) == true) 
                    return true;
                return false; // 否则无法通过删除一个字符构成回文串，不存在答案，返回 false
            }
        }
        // 如果 s[l] 和 s[r] 一直都相等，则本身就是回文串，不用删
        return true;
    }
};


// 无注释版本
class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while (l < r && s[l] == s[r]) {
            l ++ ;
            r -- ;
        }
        return l >= r;
    }

    bool validPalindrome(string s) {
        for (int l = 0, r = s.size() - 1; l < r; l ++ , r -- ) {
            if (s[l] != s[r]) {
                if (isPalindrome(s, l + 1, r) == true || isPalindrome(s, l, r - 1) == true) 
                    return true;
                return false;
            }
        }
        return true;
    }
};


// 二刷

class Solution {
public:
    bool check(string s, int l, int r) {
        while (l < r && s[l] == s[r]) {
            l ++ ;
            r -- ;
        }

        return l >= r;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                if (check(s, l + 1, r) == true || check(s, l, r - 1) == true) return true;
                return false;
            }
            l ++ ;
            r -- ;
        }
        
        return true;
    }
};