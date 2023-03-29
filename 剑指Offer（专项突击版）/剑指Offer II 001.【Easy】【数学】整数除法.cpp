// 设 x / y

// 1.确定最终符号，将两个数都变成正的，a = abs(x), b = abs(y)
//   把 x / y 转化成 a / b

// 2.先计算 31 个指数项，存到数组 exp 中：
// exp = {b * 2^0, b * 2^1, b * 2^2, ......, b * 2^29, b * 2^30}

// 3.按照从大到小的顺序遍历预处理的数组 exp
//   如果 a >= b * 2^i，则可以用 a 减去 exp[i] (即 b * 2^i ) 再加上 1 << i（即 1 * 2^i）
//   否则 a <  b * 2^i，则不做任何事，跳过

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
        LL a = abs((LL)x);
        LL b = abs((LL)y);

        // 【2】预处理，计算 31 个指数项，存到数组 exp 中
        vector<LL> exp;
        // 每次需要乘 2，但因为不能用乘法，所以 i = i + i（相当于 i *= 2）
        for (LL i = b; i <= a; i = i + i) { 
            exp.push_back(i); // i = b * 2^0, b * 2^1, b * 2^2, ..., b * 2^30
        }

        LL res = 0; // 不含正负号的结果

        // 【3】从大到小的遍历预处理的数组 exp
        for (LL i = exp.size() - 1; i >= 0; i -- ) {
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
        LL a = abs((LL)x);
        LL b = abs((LL)y);

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

