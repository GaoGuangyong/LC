
// DP
// 状态表示：
// f[i] 表示组成 i 这个数字最少需要多少个数的平方相加得到，则答案为 f[n]

// 初始化：
// f[0] = 0

// 状态转移：
// 遍历所有 <= i 的完全平方数 j * j，每次从 i 中减去 j * j
// f[i] = min(f[i], f[i - j * j] + 1)
// 解释：f[i - j * j] + 1 中的 1 代表的就是 j 这个数

class Solution {
public:
    int numSquares(int n) {
        // 定义状态数组
        vector<int> f(n + 1, INT_MAX); // 因为每次 f[i] 都要选最小的，所以非 0 下标的 f[i] 要初始为最大值

        // 初始化
        f[0] = 0;

        // 状态转移
        for (int i = 1; i <= n; i ++ ) { // 枚举所有 <= n 的数字 i
            for (int j = 1; j * j <= i; j ++ ) { // 枚举所有 <= i 的完全平方数
                f[i] = min(f[i], f[i - j * j]  + 1);
            }
        }
        return f[n];
    }
};

// 无注释版本
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX);

        f[0] = 0;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j * j <= i; j ++ ) {
                f[i] = min(f[i], f[i - j * j] + 1);
            }
        }

        return f[n];
    }
};