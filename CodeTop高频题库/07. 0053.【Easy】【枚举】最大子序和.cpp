
// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 扩展 LC 918

// 解法一：DP

// 状态表示
// f[i] 表示以 nums[i] 结尾的「连续子数组的最大和」，则答案为 max(f[i])，i ∈ (0, n - 1)

// 初始化
// f[0] = nums[0]，只有 1 个数，一定以 nums[0] 结尾

// 状态转移
// 对于 nums[i]，可以加入 f[i - 1] 对应的那一段 或 单独成为一段，这取决于 nums[i] 和 f[i - 1] + nums[i] 哪个更大
// 如果 f[i - 1] > 0，则 f[i] = f[i - 1] + nums[i]
// 如果 f[i - 1] <= 0，则 f[i] = nums[i]
// 即 f[i] = max(f[i - 1] + nums[i], nums[i])

// 最后，所有的 f[i] 取 max 即可

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // 定义状态数组
        vector<int> f(n + 1);

        // 初始化
        f[0] = nums[0];

        // 状态转移
        int res = f[0];
        for (int i = 1; i < n; i ++ ) {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
            res = max(res, f[i]); // 更新 f[i] 的最大值
        }

        // 答案
        return res;
    }
};

// 二刷
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;

        int n = nums.size();

        vector<int> f(n);

        f[0] = nums[0];

        for (int i = 1; i < n; i ++ ) {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
        }

        for (int i = 0; i < n; i ++ ) res = max(res, f[i]);
        
        return res;
    }
};


// 解法二：贪心（笔试推荐）

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN; // 最大子数组和，因为答案可能是负值，所以初始化为负无穷

        int sum = 0; // sum 代表以当前元素的前一个元素为结尾的连续子数组的最大和

        // 遍历数组
        for (auto x: nums) {
            if (sum > 0) sum += x; // 如果 sum > 0, 说明前面的子数组的和是正数，那么最大和就是 sum + x
            else sum = x; // 如果 sum <= 0, 说明前面的子数组的和是负数或 0，那么最大和就是当前元素 x

            res = max(res, sum); // 每次更新最大子数组和
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        
        int sum = 0;

        for (int i = 0; i < nums.size(); i ++ ) {
            if (sum > 0) sum += nums[i];
            else sum = nums[i];

            res = max(res, sum);            
        }

        return res;
    }
};

