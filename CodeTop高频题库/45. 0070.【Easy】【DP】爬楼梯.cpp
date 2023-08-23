

// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 斐波那契数列：0，1，1，2，3，5，8，13，21，34，55，89，...
// 本题：          1，1，2，3，5，8，13，21，34，55，89，...

// 和 剑指 Offer 10 -II 一样，只不过不需要 mod，而需要用 long long 存

// 滚动数组 1 
typedef long long LL;

class Solution {
public:
    int climbStairs(int n) {

        int a = 1; // 爬到 1 阶台阶有 1 种方法
        int b = 1; // 爬到 2 阶台阶有 1 种方法

        // 循环 n - 1 次 -> 返回 b
        while ( -- n) {
            LL c = (LL)a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

// 滚动数组 2 
typedef long long LL;

class Solution {
public:
    int climbStairs(int n) {

        int a = 1; // 爬到 1 阶台阶有 1 种方法
        int b = 1; // 爬到 2 阶台阶有 1 种方法

        // 循环 n 次 -> 返回 a
        while (n -- ) {
            LL c = (LL)a + b;
            a = b;
            b = c;
        }

        return a;
    }
};


// 递推
class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n + 2, 0);
        f[1] = 1;
        f[2] = 2;

        for (int i = 3; i <= n; i ++ ) {
            f[i] = f[i - 1] + f[i - 2];
        }

        return f[n];
    }
};


