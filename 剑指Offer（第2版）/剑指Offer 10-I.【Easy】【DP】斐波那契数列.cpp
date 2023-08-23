
// 斐波那契数列：0，1，1，2，3，5，8，13，21，34，55，89，...
// 滚动数组
// 对于当前要计算的这一项 c，a 是其前面第二项，b 是其前一项


// 滚动数组写法一：
// 最后要返回 b，因为在循环的最后一轮，c 的值最终被赋给了 b
class Solution {
public:
    int fib(int n) {
        int mod = 1e9 + 7;

        // 特判 F(0)
        if (n == 0) return 0; // 因为最后返回的是 b，因此必须特判

        // 初始化 前 2 个数
        int a = 0;
        int b = 1;

        // 循环 n - 1 次 -> 返回 b
        while ( -- n) {
            int c = (a + b) % mod;
            a = b;
            b = c;
        }

        return b;
    }
};


// 滚动数组写法二：
// 最后要返回 a，因为在循环的最后一轮，b 的值最终被赋给了 a
class Solution {
public:
    int fib(int n) {
        int mod = 1e9 + 7;

        // 初始化 前 2 个数
        int a = 0;
        int b = 1;

        // 循环 n 次 -> 返回 a
        while (n -- ) {
            int c = (a + b) % mod;
            a = b;
            b = c;
        }

        return a;
    }
};


// 递推写法
class Solution {
public:
    int fib(int n) {
        int mod = 1e9 + 7;

        // 第 1 个数 单独特判
        if (n == 0) return 0;
        
        vector<int> f(n + 1, 0);

        // 初始化 前 2 个数
        f[0] = 0;
        f[1] = 1;

        // 从第 3 个数开始递推
        for (int i = 2; i <= n; i ++ ) {
            f[i] = (f[i - 1] + f[i - 2]) % mod;
        }

        // 返回第 n 个数
        return f[n];
    }
};


