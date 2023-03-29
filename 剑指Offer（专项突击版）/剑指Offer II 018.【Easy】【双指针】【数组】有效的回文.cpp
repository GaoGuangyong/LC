// 双指针
class Solution {
public:
    // 自定义 check 函数，判断字符 c 是不是大小写字母或数字
    bool check(char c) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') return true;
        else return false;
    }

    bool isPalindrome(string s) {
        // 指针 i 从前向后枚举，指针 j 从后向前枚举
        for (int i = 0, j = s.size() - 1; i < j; i ++, j -- ) {
            // 当枚举到非字母，非数字时，跳过
            while (i < j && check(s[i]) == false) i ++ ; 
            while (i < j && check(s[j]) == false) j -- ;
            // 因为可以忽略大小写，所以先都转化成小写，注意：tolower函数只转化大写字符，其他字符保持不变
            if (i < j && tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};


// 无注释版本
class Solution {
public:
    bool check(char c) {
        if (isdigit(c) || isalpha(c)) return true;
        return false;
    }

    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i ++ , j -- ) {
            while (i < j && check(s[i]) == false) i ++ ;
            while (i < j && check(s[j]) == false) j -- ;

            if (i < j && tolower(s[i]) != tolower(s[j])) return false;
        }

        return true;
    }
};

