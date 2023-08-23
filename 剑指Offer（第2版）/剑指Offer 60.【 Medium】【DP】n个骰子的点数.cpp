
// 抛 n 个骰子，给出各个点数和出现的概率
// 点数和 j 出现的概率 = 点数和为 j 的方案数 / 总的方案数

// DP
// 抛 i 个 <=> 抛 i - 1 个，再抛 1 个

// 状态表示：
// f[i][j] 表示抛前 i 个骰子，点数和为 j 的方案数
// 共 n 个骰子，点数和的最大值为 6*n

// 初始化：
// 抛 1 个骰子的时候，点数和 i 出现的方案数都是 1
// for (int i = 1; i <= 6; i ++ ) f[1][i] = 1

// 状态转移：
// 设 k 为第 i 个骰子抛出的点数 (1 <= k <= 6)
// 抛第 i 个骰子点数和为 j 的方案数 = 抛第 i - 1 个骰子点数和为 j - k 的方案数的和（六种情况的方案数相加）
// f[i][j] = f[i - 1][j - 1] + f[i - 1][j - 2] + f[i - 1][j - 3] + f[i - 1][j - 4] + f[i - 1][j - 5] + f[i - 1][j - 6]


class Solution {
public:
    vector<double> dicesProbability(int n) {
        // 状态表示：
        vector<vector<int>> f(n + 1, vector<int>(6 * n + 1));

        // 初始化：抛 1 个骰子时，点数为 i 的方案数是 1
        for (int i = 1; i <= 6; i ++ ) {
            f[1][i] = 1;
        }

        // 状态计算：
        for (int i = 2; i <= n; i ++ ) { // 从第 2 个骰子开始，最多抛 n 个，所以抛骰子的范围为 [2 ~ n]
            for (int j = i; j <= 6 * i; j ++ ) { // 抛第 i 个骰子后，点数和 j 的范围为 [i ~ 6 * i]
                for (int k = 1; k <= 6; k ++ ) { // 枚举第 i 个骰子的点数
                    if (j >= k) f[i][j] += f[i - 1][j - k];
                }
            }
        }

        vector<double> res; // 结果数组
        int sum = pow(6, n); // 抛 n 个骰子，总方案数：6 ^ n

        for (int j = n; j <= 6 * n; j ++ ) { // 抛 n 个骰子，点数和 j 的取值范围是 [n ~ 6 * n]
            res.push_back(f[n][j] * 1.0 / sum); // 点数和为 j 的方案数 / 总的方案数 = 该点数出现的概率
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> f(n + 1, vector<int>(6*n + 1));

        for (int i = 1; i <= 6; i ++ ) {
            f[1][i] = 1;
        }

        for (int i = 2; i <= n; i ++ ) {
            for (int j = i; j <= 6 * i; j ++ ) {
                for (int k = 1; k <= 6; k ++ ) {
                    if (j >= k) f[i][j] += f[i - 1][j - k];
                }
            }
        }

        vector<double> res;
        int sum = pow(6, n);

        for (int j = n; j <= 6 * n; j ++ ) {
            res.push_back(f[n][j] * 1.0 / sum);
        }

        return res;
    }
};

