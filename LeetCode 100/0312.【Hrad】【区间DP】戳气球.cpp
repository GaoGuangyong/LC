
// 区间 DP
// 区间DP，先枚举区间长度，从小到大枚举，再枚举起点，从而确定终点，最后在起点终点间状态转移

// 状态表示：
// f[i][j] 表示将区间 [i + 1 ~ j - 1] 的气球打掉，能获得硬币的最大数量，则答案为 f[0][n + 1]
// 这样可以防止最外面两个给打掉，无需特判边界 

// 状态转移：
// 设 k 为 [i + 1 ~ j - 1] 里最后打掉的一个气球，此时 i，j 编号的气球并未被打掉
// 相当于先把 [i + 1 ~ k - 1] 打掉，再把 [k + 1 ~ j - 1] 打掉，最后再打掉 k
// f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // 定义一个 a 数组来辅助，a[1] ~ a[n] 存 nums[0] ~ nums[n - 1]，两边存 1
        vector<int> a(n + 2, 1);
        for (int i = 1; i <= n; i ++ ) {
            a[i] = nums[i - 1];
        }

        // 定义状态数组
        vector<vector<int>> f(n + 2, vector<int>(n + 2));

        // 枚举区间长度
        for (int len = 3; len <= n + 2; len ++ ) { // 区间长度最少为 3
            // 枚举区间起点
            for (int i = 0; i + len - 1 <= n + 1; i ++ ) {
                int j = i + len - 1; // 确定区间终点
                // 枚举中间点
                for (int k = i + 1; k <= j - 1; k ++ ) {
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
                }
            }
        }
        return f[0][n + 1];
    }
};

// 区间 DP 模板

// 定义状态数组
vector<vector<int>> f(n + 2, vector<int>(n + 2));

// 枚举区间长度
for (int len = 1; len <= n; len ++ ) {
    // 枚举区间左端点，从 1 到 n
    for (int i = 1; i + len - 1 <= n; i ++ ) {
        // 计算区间右端点
        int j = i + len - 1;
        f[i][j] = 初始值; // 根据需要，取较大值或较小值，也可以没有这一步
        for (int k = i; k <= j; k ++ ) { // 根据题意， k <= j 或 j - 1
            f[i][j] = 状态计算方程;
        }
    }
}

// 无注释版本
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> a(n + 2);
        a[0] = a[n + 1] = 1;
        for (int i = 1; i <= n; i ++ ) {
            a[i] = nums[i - 1];
        }

        vector<vector<int>> f(n + 2, vector<int>(n + 2));

        for (int len = 3; len <= n + 2; len ++ ) {
            for (int i = 0; i + len - 1 <= n + 1; i ++ ) {
                int j = i + len - 1;
                for (int k = i + 1; k <= j - 1; k ++ ) {
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[j] * a[k]);
                }
            }
        }

        return f[0][n + 1];
    }
};
