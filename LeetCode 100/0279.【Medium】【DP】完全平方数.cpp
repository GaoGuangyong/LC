
// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量


// DP
// 状态表示：
// f[i] 表示数字 i 最少可以由多少个完全平方数相加构成，则答案为 f[n]

// 初始化：
// f[0] = 0; // 表示数字 0 由 0 个完全平方数组成

// 状态转移：
// 先枚举 1 ~ n 的数字 i，再枚举所有 <= i 的完全平方数 j * j，每次从 i 中减去 j * j，取 f[i] 和 f[i - j * j] + 1 的最小值
// f[i] = min(f[i], f[i - j * j] + 1)
// 解释：f[i - j * j] + 1 中的 1 代表的就是 j 这个数

// 找到 n 前面最大的一个完全平方数 k * k，那么 还剩 n - k * k
// 也就是说只要将 n - k * k 的解 f[n - k * k] 加上 1，就是 n 的解，这就是最短的

class Solution {
public:
    int numSquares(int n) {
        // 定义状态数组
        vector<int> f(n + 1, INT_MAX); // 因为每次 f[i] 都要选最小的，所以非 0 下标的 f[i] 要初始为最大值

        // 初始化
        f[0] = 0;

        // 状态转移
        for (int i = 1; i <= n; i ++ ) { // 枚举 1 ~ n 的数字 i
            for (int j = 1; j * j <= i; j ++ ) { // 枚举所有 <= i 的完全平方数 j * j
                f[i] = min(f[i], f[i - j * j]  + 1);
            }
        }

        return f[n];
    }
};


// 解法二：完全背包（推荐）
// 题意：给定物品 1, 4, 9, 16, 25, ... 来装满容量为 n 的背包，求最少需要的物品数量

// 本题求得最少的物品数量，则和物品的顺序没关系，属于组合问题，遍历顺序无所谓
// 通常选择先遍历物品，再遍历背包容量

// 版本一：先遍历物品体积，再遍历背包容量（推荐）
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX); // 求最少物品数量，因此初始化为最大值

        f[0] = 0; // 表示背包容量为 0 时，物品体积也是 0

        for (int i = 1; i * i <= n; i ++ ) { // 遍历物品体积：1 ~ i * i
            for (int j = 0; j <= n; j ++ ) { // 遍历背包容量：0 ~ n
                if (j - i * i  >= 0 && f[j - i * i] != INT_MAX) {
                    f[j] = min(f[j], f[j - i * i ] + 1);
                }
            }
        }

        return f[n];
    }
};

// 无注释版
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX);

        f[0] = 0;

        for (int i = 1; i * i <= n; i ++ ) {
            for (int j = 0; j <= n; j ++ ) {
                if (j - i * i >= 0 && f[j - i * i] != INT_MAX) {
                    f[j] = min(f[j], f[j - i * i] + 1);
                }
            }
        }

        return f[n];
    }
};


// 版本二：先遍历背包容量，再遍历物品
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX); // 求最少物品数量，因此初始化为最大值

        f[0] = 0; // 表示背包容量为 0 时，物品体积也是 0

        for (int j = 0; j <= n; j ++ ) { // 遍历背包容量：0 ~ n
            for (int i = 1; i * i <= j; i ++ ) { // 遍历物品体积：1 ~ i * i
                f[j] = min(f[j], f[j - i * i] + 1);
            }
        }

        return f[n];
    }
};





