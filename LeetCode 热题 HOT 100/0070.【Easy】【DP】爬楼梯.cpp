



// 滚动数组 1

typedef long long LL;

class Solution {
public:
    int climbStairs(int n) {

        int a = 1; // 爬到 0 阶台阶有 1 种方法
        int b = 1; // 爬到 1 阶台阶有 1 种方法

        while (n -- ) {
            LL c = (LL)a + b;
            a = b;
            b = c;
        }
        return a;
    }
};

// DP 1

class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n + 1, 0); // 注意从 0 阶开始到 n 阶，共 n + 1 个数
        f[0] = 1;
        f[1] = 1;

        for (int i = 2; i <= n; i ++ ) {
            f[i] = f[i - 1] + f[i - 2];
        }

        return f[n];
    }
};


// 滚动数组 2

typedef long long LL;

class Solution {
public:
    int climbStairs(int n) {

        int a = 1; // 爬到 1 阶台阶有 1 种方法
        int b = 2; // 爬到 2 阶台阶有 2 种方法

        while ( -- n) {
            LL c = (LL)a + b;
            a = b;
            b = c;
        }
        return a;
    }
};

// DP 2

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

