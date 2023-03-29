
// 本质：斐波那契数列：1，1，2，3，5，8，13，21，34，55，89，...

// 滚动数组
// 对于当前要计算的这一项 c，a 是其前面第二项，b 是其前一项

// 滚动数组写法一：
class Solution {
public:
    int mod = 1e9 + 7;

    int numWays(int n) {
        // 第 1 个数 单独特判  
        if (n == 0) return 1;

        
        int a = 1; // 跳到 0 级台阶有 1 种跳法
        int b = 1; // 跳到 1 级台阶有 1 种跳法

        // 循环 n - 1 次
        for (int i = 2; i <= n; i ++ ) {
            int c = (a + b) % mod;
            a = b;
            b = c;
        }

        // 返回 b
        return b;
    }
};



// 滚动数组写法二：
class Solution {
public:
    int mod = 1e9 + 7;

    int numWays(int n) {
        // 初始化 前 2 个数    
        int a = 1; 
        int b = 1; 

        // 循环 n 次
        while (n -- ) {
            int c = (a + b) % mod;
            a = b;
            b = c;
        }

        // 返回 a
        return a;
    }
};






// 递推
class Solution {
public:
    int mod = 1e9 + 7;

    int numWays(int n) {
        // 第 1 个数 单独特判
        if (n == 0) return 1;
        
        vector<int> f(n + 1, 0);

        // 初始化 前 2 个数
        f[0] = 1;
        f[1] = 1;

        // 从第 3 个数开始递推
        for (int i = 2; i <= n; i ++ ) {
            f[i] = (f[i - 1] + f[i - 2]) % mod;
        }

        // 返回第 n 个数
        return f[n];
    }
};