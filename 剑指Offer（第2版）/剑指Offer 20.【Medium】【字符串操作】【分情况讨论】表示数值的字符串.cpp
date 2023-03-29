// 字符串操作 + 分情况讨论

// 注：包含 e 的合法数字：
// e 只能有 1 个
// 在 e 的前后都要有数字
// 在 e 后不能有小数点
// 在 e 前可以有小数点，但不能只有小数点，如 .e
// 在 e 后可以有正负号，但不能只有正负号，如 e+

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();

        // 先删除开头和结尾的空格
        int i = 0;
        int j = n - 1;
        while (i < n && s[i] == ' ') i ++ ;
        while (j >= 0 && s[j] == ' ') j -- ;
        s = s.substr(i, j - i + 1); // 得到去除前后空格后的子串 s[i ~ j]
        // 如果删完空格后，字符串为空了，则表示 s 只由一堆空格构成，不合法
        if (i > j) return false; 
        
        // 如果字符串是以正负号开头，则不影响判断，直接忽略
        if (s[0] == '-' || s[0] == '+') s = s.substr(1); 
        // 如果删完正负号后，字符串为空或字符串只有小数点，则不合法
        if (s.empty() || n == 1 && s[0] == '.') return false; 

        int dot = 0; // 统计小数点个数
        int e = 0; // 统计 e 的个数

        // 遍历字符串，逐个判断，逐个去除不合法情况
        for (int i = 0; i < n; i ++ ) {
            // 如果是数字的话，跳过
            if (s[i] >= '0' && s[i] <= '9') continue;

            // 如果是小数点的话，判断：如果小数点的个数 > 1 个，或者小数点前有 e 的话，则不合法
            else if (s[i] == '.') {
                dot ++ ; // 小数点个数 + 1
                if (dot > 1 || e > 0) return false; 
            }

            // 如果是 e 的话，
            else if (s[i] == 'e' || s[i] == 'E') {
                e ++ ; // e 个数 + 1
                // 如果 e 的前面为空，或者 e 的后面为空，或者 e 的个数大于 1，或者是 ".e" 这种情况，都不合法
                if (i == 0 || i + 1 == n || e > 1 || i == 1 && s[0] == '.') return false;
                // 如果 e 后面紧跟着正负号，
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    // 如果正负号后面为空，则不合法
                    if (i + 2 == n) return false; 
                    // 如果正负号后面不为空，则跳过正负号
                    else i ++ ; 
                }
            }

            // 如果有其他字符（如：空格 / 其他字母），则不合法
            else return false;
        }

        // 除了上述情况外，都是合法字符串
        return true;
    }
};


// 无注释版本
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();

        // 先删除开头和结尾的空格
        int i = 0;
        int j = n - 1;
        while (i < n && s[i] == ' ') i ++ ;
        while (j >= 0 && s[j] == ' ') j -- ;
        s = s.substr(i, j - i + 1); 
        if (i > j) return false; 
        
        if (s[0] == '-' || s[0] == '+') s = s.substr(1); 
        if (s.empty() || n == 1 && s[0] == '.') return false; 

        int dot = 0; 
        int e = 0;

        // 遍历字符串，逐个判断，逐个去除不合法情况
        for (int i = 0; i < n; i ++ ) {
            // 如果是数字的话
            if (s[i] >= '0' && s[i] <= '9') continue;
            // 如果是小数点的话
            else if (s[i] == '.') {
                dot ++ ;
                if (dot > 1 || e > 0) return false; 
            }
            // 如果是 e / E 的话
            else if (s[i] == 'e' || s[i] == 'E') {
                e ++ ;
                if (i == 0 || i + 1 == n || e > 1 || i == 1 && s[0] == '.') return false;
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 2 == n) return false; 
                    else i ++ ; 
                }
            }
            // 如果是其他字符的话
            else return false;
        }

        return true;
    }
};




