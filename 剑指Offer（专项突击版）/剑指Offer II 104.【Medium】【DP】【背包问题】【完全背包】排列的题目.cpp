// https://leetcode.cn/problems/combination-sum-iv/solution/er-wei-dpyi-wei-dpyou-hua-san-chong-fang-kzim/

// DP
// 背包问题
// 注意：此题不是常规的完全背包
// 一般的背包不考虑顺序，是组合问题，此题考虑顺序，是排列问题

// 如果是求组合：外层物品，内层背包容量
// 如果是求排列：外层背包容量，内层物品

// f[i] 表示装满容量为 target 的背包，有多少种方案
// 求装满背包有几种方法，递推公式一般都为 f[j] += f[j - nums[i - 1]];


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size(); // 物品数量 n
        int m = target; // 背包容量 m

        // 定义状态数组
        vector<unsigned> f(m + 1, 0); // unsigned 是 2^32 - 1, 题目要求保证答案 32 位

        // 初始化
        f[0] = 1;

        // 遍历背包容量（0 ~ m）
        for (int j = 0; j <= m; j ++ ) {
            // 遍历物品数量（1 ~ n）
            for (int i = 1; i <= n; i ++ ) {
                if (j >= nums[i - 1]) {
                    f[j] += f[j - nums[i - 1]];
                }
            }
        }
        return f[m];
    }
};


// 无注释版本
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int m = target;

        vector<unsigned> f(m + 1);

        f[0] = 1;

        for (int j = 0; j <= m; j ++ ) {
            for (int i = 1; i <= n; i ++ ) {
                if (j >= nums[i - 1]) {
                    f[j] += f[j - nums[i - 1]];
                }
            }
        }
        return f[m];
    }
};


