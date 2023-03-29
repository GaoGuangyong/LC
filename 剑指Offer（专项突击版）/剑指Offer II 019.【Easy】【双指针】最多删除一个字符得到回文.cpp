// 双指针

class Solution {
public:
    // 辅助函数 1：判断字符串 s 的下标 [i, j] 是不是回文串
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i ++ ;
            j -- ;
        }
        return true;
    }
    // 辅助函数 2：判断字符串 s 的下标 [i, j] 是不是回文串
    bool isPalindrome(string s, int i, int j) {
        while (i < j && s[i] == s[j]) {
            i ++ ;
            j -- ;
        }
        return i >= j;
    }

    bool validPalindrome(string s) {
        // 从字符串的两端向中间枚举
        for (int i = 0, j = s.size() - 1; i < j; i ++ , j -- ) {
            if (s[i] != s[j]) { // 当遇到 2 个不相同的字符，就考虑删除其中一个字符，判断剩下的还能否构成回文串
                // 如果删除 s[i] 后 s[i + 1 ~ j] 是回文串 || 删除 s[j] 后 s[i ~ j - 1] 是回文串，则存在解
                if (isPalindrome(s, i + 1, j) == true || isPalindrome(s, i, j - 1) == true) 
                    return true;
                else // 否则无解，继续向中间枚举
                    return false;
            }
        }
        // 如果 s[i] 和 s[j] 一直都相等，则本身就是回文串，不用删
        return true;
    }
};


// 无注释版本
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j && s[i] == s[j]) {
            i ++ ;
            j -- ;
        }
        return i >= j;
    }

    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i ++ , j -- ) {
            if (s[i] != s[j]) {
                if (isPalindrome(s, i + 1, j) == true || isPalindrome(s, i, j - 1) == true) return true;
                return false;
            }
        }
        return true;
    }
};
