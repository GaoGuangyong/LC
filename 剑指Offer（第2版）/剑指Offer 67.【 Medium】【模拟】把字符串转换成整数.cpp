

// 1. 先消除前缀空格
// 2. 判断正负数
// 3. 从左往右扫描，只读取数字字符，一旦读取到非数字字符就可以结束
//    若不在 [INT_MIN, INT_MAX] 范围内，直接返回边界值

class Solution {
public:
    int strToInt(string s) {
        if (s.empty()) return 0; // 如果是空串，返回 0

        // 1、去掉开始的空格，使 k 指向第一个不是空格的位置
        int k = 0;
        while (k < s.size() && s[k] == ' ') k ++ ;

        // 2、确定符号
        int flag = 1; // 正负数的标记（1 代表正数，-1 代表负数）
        if (s[k] == '+') {
            k ++ ;
        }
        else if (s[k] == '-') {
            flag = -1;
            k ++ ;
        }

        long long res = 0;

        // 3、计算数字
        // 当 s[k] 这个字符是数字的话
        while (k < s.size() && isdigit(s[k])) { 
            // 获取 s[k] 对应的数字
            int x = s[k] - '0';
            // 计算总的数字
            res = res * 10 + x; // 比如：原来是 249，现在要加上 5，就需要 249 * 10 + 5 = 2495  

            // 4、溢出判断
            if (res * flag <= INT_MIN) return INT_MIN;
            if (res * flag >= INT_MAX) return INT_MAX;

            // 继续判断下一位
            k ++ ;
        }

        return res * flag;
    }
};


// 无注释版本
class Solution {
public:
    int strToInt(string s) {
        if (s.empty()) return 0;

        int k = 0;
        while (k < s.size() && s[k] == ' ') k ++ ;

        int flag = 1;
        if (s[k] == '+') {
            k ++ ;
        }
        else if (s[k] == '-') {
            flag = -1;
            k ++ ;
        }

        long long res = 0;

        while (k < s.size() && isdigit(s[k])) { 
            int x = s[k] - '0';
            res = res * 10 + x;

            if (res * flag <= INT_MIN) return INT_MIN;
            if (res * flag >= INT_MAX) return INT_MAX;

            k ++ ;
        }

        return res * flag;
    }
};




