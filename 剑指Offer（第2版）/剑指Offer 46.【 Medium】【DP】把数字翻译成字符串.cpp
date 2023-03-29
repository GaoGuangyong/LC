
// DP

// 状态表示：
// f[i] 表示前 i 个数字一共有多少种不同的翻译方式（下标从 1 开始），则答案为：f[n]

// 初始化：
// f[0] = 1;

// 状态转移：
// 1、将 s[i] 单独看成一个数 x（0 <= x <= 9），则
//    f[i] = f[i - 1]
// 2、将 s[i - 1] 和 s[i] 共同看成一个数 x（10 <= x <= 25），则 
//    f[i] = f[i - 2]
// 二者相加，f[i] = f[i - 1] + f[i - 2]


// 写法一
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num); // 将数字转为字符串
        int n = s.size();
        
        // 定义状态数组
        vector<int> f(n + 1); 
        
        // 初始化
        f[0] = 1; 
        
        // 状态转移
        for (int i = 1; i <= n; i ++ ) {
            f[i] = f[i - 1];
            if (i >= 2) {
                int t = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (t >= 10 && t <= 25) { // 组合的数字范围在 10 ~ 25 之间
                    f[i] += f[i - 2];
                }
            }
        }
        return f[n];
    }
};


// 写法二：把 s 向后移动一位（推荐）
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num); // 将数字转为字符串
        int n = s.size();

        s = ' ' + s;

        // 定义状态数组
        vector<int> f(n + 1); 
        
        // 初始化
        f[0] = 1; 
        
        // 状态转移
        for (int i = 1; i <= n; i ++ ) {
            // 将 s[i] 单独看成一个数
            f[i] = f[i - 1];
            
            // 将 s[i - 1] 和 s[i] 共同看成一个数
            int t = (s[i - 1] - '0') * 10 + (s[i] - '0');

            // 如果 t 的范围在 10 ~ 25 之间
            if (t >= 10 && t <= 25) { 
                f[i] += f[i - 2];
            }
            
        }

        return f[n];
    }
};


// 无注释版本
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        s = ' ' + s;

        vector<int> f(n + 1);
        f[0] = 1;

        for (int i = 1; i <= n; i ++ ) {
            f[i] = f[i - 1];
            int t = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (t >= 10 && t <= 25) {
                f[i] += f[i - 2];
            }
        }

        return f[n];
    }
};


