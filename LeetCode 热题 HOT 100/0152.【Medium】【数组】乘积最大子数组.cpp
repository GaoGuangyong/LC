// 解法一：（推荐）
// DP
// f[i] 表示以 i 位置结尾的连续子数组中的乘积最大值
// g[i] 表示以 i 位置结尾的连续子数组中的乘积最小值

// f[i] 的计算可以分成两种情况（取 max ）：
// 这一段只有自己，f[i] = nums[i]
// 这一段长度至少是 2，那么
// 如果 nums[i] >= 0 ，f[i] = nums[i] × f[i − 1]，即大于 0 的数 × 越大的数 = 越大
// 如果 nums[i] < 0 ，f[i] = nums[i] × g[i − 1]，即小于 0 的数 × 越小的数 = 越大

// 同理 g[i] 的计算也是类似的（取 min ）：
// 这一段只有自己，g[i] = nums[i]
// 这一段长度至少是 2，那么
// 如果 nums[i] >= 0 ，g[i] = nums[i] × g[i − 1]，即大于 0 的数 × 越小的数 = 越小
// 如果 nums[i] < 0 ，g[i] = nums[i] × f[i − 1]，即小于 0 的数 × 越大的数 = 越小

// 对所有的 f[i] 取 max 即可

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // 定义状态数组
        vector<int> f(n);
        vector<int> g(n);
        // 初始化
        f[0] = nums[0];
        g[0] = nums[0];
        // 状态转移
        int res = f[0];
        for (int i = 1; i < n; i ++ ) {
            f[i] = max(nums[i], max(nums[i] * f[i - 1], nums[i] * g[i - 1]));
            g[i] = min(nums[i], min(nums[i] * f[i - 1], nums[i] * g[i - 1]));
            // 更新 res 为 f[i] 的最大值
            res = max(res, f[i]);
        }

        return res;
    }
};


// 解法二：
// 贪心
// 还是 剑指Offer 42 连续子数组的最大和 这个题的思路，贪心算法
// 如果遇到负数，那么当前的最大值变成最小值，最小值会变成最大值
// 我们可以同时求子数组的最大值 Max 和最小值 Min，当遍历到负数 nums[i] 时，交换最大最小值，不断更新答案

// 这里分为三种情况：
// Max > 0 && Min > 0：乘以 nums[i] 后 Max 与 Min 都变成比 nums[i] 更小的负数，这时最大值应取 nums[i]
// Max > 0 && Min < 0：乘以 nums[i] 后 Max 变成负数，Min 变成正数
// Max < 0 && Min < 0：乘以 nums[i] 后 Max 与 Min 都变成比 nums[i] 更大的正数，这时最小值应取 nums[i]

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int Max = 1;
        int Min = 1;

        for (int i = 0; i < nums.size(); i ++ ) {
            // 遇到负数是交换最大值与最小值
            if (nums[i] < 0) {
                swap(Max, Min);
            }

            Max = max(Max * nums[i], nums[i]);    // 考虑到情况 1
            Min = min(Min * nums[i], nums[i]);    // 考虑到情况 3

            res = max(res, Max);           // 每个循环更新最大值
        }
        return res;
    }
};



