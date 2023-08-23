// 数学

// 设要计算的是 a / b

// 1.确定最终符号，将两个数都变成正的，x = abs(a), y = abs(b)
// 把求 a / b 转化成 x / y，然后如果是负数，则再乘上 -1 

// 2.先计算 31 个指数项，存到数组 exp 中：
// exp = { y * 2^0, y * 2^1, y * 2^2, ......, y * 2^29, y * 2^30 }

// 3.按照从大到小的顺序遍历预处理的数组 exp
//   如果 x >= y * 2^i，则可以用 x 减去 exp[i] (即 y * 2^i ) 再加上 1 << i（即 1 * 2^i ）
//   否则 x <  y * 2^i，则跳过

// 举例说明算法的过程
// 60 / 3 = 20 = 10100 (二进制) = 2^2 + 2^4
// 60 = 3 * 20
//    = 3 * 2^4 + 3 * 2^2
//    = exp[4] + exp[2]

// 20 = 1 * 2^2 + 1 * 2^4
//    = 1 << 2 + 1 << 4

// 20 = 60 - 3 * 2^4 + 1 * 2^4 - 3 * 2^2 + 1 * 2^2
//    = 60 - 3 * 2^4 + 1 << 4  - 3 * 2^2 + 1 << 2
//    = a  - exp[4]  + 1 << 4  - exp[2]  + 1 << 2
//    =                1 << 4            + 1 << 2

typedef long long LL;

class Solution {
public:
    int divide(int x, int y) {
        //【1】先确定最终符号，并将 x / y 转化成正数 a / b
        bool is_minus = false;
        if (x < 0 && y > 0 || x > 0 && y < 0) is_minus = true;

        // x, y 最小取 -2^31，取绝对值为 2^31，会爆 int
        LL a = abs(x);
        LL b = abs(y);

        // 【2】预处理，计算 31 个指数项，存到数组 exp 中
        vector<LL> exp;
        // 每次需要乘 2，但因为不能用乘法，所以 i = i + i（相当于 i *= 2）
        for (LL i = b; i <= a; i = i + i) { 
            exp.push_back(i); // i = b * 2^0, b * 2^1, b * 2^2, ..., b * 2^30
        }

        LL res = 0; // 不含正负号的结果，注意：必须初始化 ！！！！！！

        // 【3】从大到小的遍历预处理的数组 exp
        for (int i = exp.size() - 1; i >= 0; i -- ) {
            // 如果 a >= b * 2^i (即 b * 2^i )
            if (a >= exp[i]) { 
                a -= exp[i]; // 则可以用 a 减去 exp[i]
                res += 1ll << i; // 再加上 1 << i
            }
        }

        // 如果最终结果是负数的话，K 取相反数
        if (is_minus == true) res = -res;

        // 如果除法结果溢出，则返回 2^31 − 1
        if (res > INT_MAX || res < INT_MIN) res = INT_MAX; // INT_MAX = 2^31 - 1

        return res;
    }
};


// 无注释版
typedef long long LL;

class Solution {
public:
    int divide(int x, int y) {
        bool is_minus = false;
        if (x < 0 && y > 0 || x > 0 && y < 0) is_minus = true;
        LL a = abs(x);
        LL b = abs(y);

        vector<LL> exp;
        for (LL i = b; i <= a; i = i + i) {
            exp.push_back(i);
        } 

        LL res = 0;

        for (int i = exp.size() - 1; i >= 0; i -- ) {
            if (a >= exp[i]) {
                a -= exp[i];
                res += 1ll << i;
            }
        }

        if (is_minus == true) res = -res;
        if (res > INT_MAX || res < INT_MIN) res = INT_MAX;

        return res;

    }
};


// 二刷
typedef long long LL;

class Solution {
public:
    int divide(int a, int b) {
        bool flag = false;
        if (a < 0 && b > 0 || a > 0 && b < 0) flag = true;

        LL x = abs(a);
        LL y = abs(b);

        vector<LL> e;
        for (LL i = y; i <= x; i = i + i) e.push_back(i);

        LL res = 0;

        for (int i = e.size() - 1; i >= 0; i -- ) {
            if (x >= e[i]) {
                x -= e[i];
                res += 1ll << i;
            }
        }

        if (flag == true) res = -res;

        if (res > INT_MAX || res < INT_MIN) res = INT_MAX;

        return res;
    }
};

