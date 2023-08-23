
// 快速幂
// 举例：x^(111010) == x^(2^1 + 2^3 + 2^4 + 2^5) == x^2^1 * x^2^3 * x^2^4 * x^2^5
// 即可以将 n 进行二进制拆分，若 n 的二进制位的第 k 位是 1，则 res 可以乘上 x^2^k

// 如何计算 x^2^k ？只需每次将自身做平方即可，具体如下所示
// x^2^0 == x
// x^2^1 == (x^2^0)^2 == x^2
// x^2^2 == (x^2^1)^2 == x^2^2
// x^2^3 == (x^2^2)^2 == x^2^2^2

// 注意指数 n 为负的情况，以及 n == INT_MIN 时，取绝对值会爆 int，所以要用 long long

class Solution {
public:
    double myPow(double x, int n) {
        // 先判断指数是不是负数
        bool is_minus = false;
        if (n < 0) is_minus = true;

        // 取指数 n 的绝对值 k
        long long k = abs((long long)n);

        double res = 1;

        // 边预处理 x^2^k，边计算结果 res
        while (k > 0) {
            // 如果 k 的二进制表示的个位是 1，则 res 乘上当前的 x^2^k
            if ((k & 1) == 1) res *= x;
            // 否则，预处理 x^2^k，并将 k 右移一位（删掉个位）
            x *= x; // 预处理：每次将 x 变成 x^2
            k >>= 1; // 删掉个位
        }

        if (is_minus == true) res = 1 / res;
        
        return res;
    }
};


// 无注释版本
class Solution {
public:
    double myPow(double x, int n) {
        bool is_minus = false;
        if (n < 0) is_minus = true;

        long long k = abs((long long)n);

        double res = 1;

        while (k > 0) {
            if ((k & 1) == 1) res *= x;
            x *= x;
            k >>= 1;
        }

        if (is_minus == true) res = 1 / res;
        
        return res;
    }
};



// 模板：正整数快速幂：求 x 的 n 次方
int Pow(int x, int n) {
    int res = 1;
    
    while (n > 0) {
        if ((n & 1) == 1)  // 如果 k 的二进制表示的个位是 1
            res *= x;
        x *= x; // 每次将 x 变成 x^2
        n >>= 1; // 删掉个位
    }

    return res;
}



