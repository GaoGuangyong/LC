

// 解法一：DP

// 状态表示
// f[i] 表示以 nums[i] 结尾的「连续子数组的最大和」，则答案为 max(f[i])，i ∈ (0, n - 1)

// 初始化
// f[0] = nums[0]，只有 1 个数，一定以 nums[0] 结尾

// 状态转移
// 对于 nums[i]，可以加入 f[i - 1] 对应的那一段 或 单独成为一段
// 这取决于 nums[i] 和 f[i - 1] + nums[i] 哪个更大
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
        for (int i = 1; i < n; i++) {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
            res = max(res, f[i]); // 更新 f[i] 的最大值
        }

        // 答案
        return res;
    }
};


// 解法二：贪心（推荐）

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN; // 因为答案可能是负值，所以初始化为负无穷
        int s = 0; // s 代表以当前元素的前一个元素为结尾的连续子数组的最大和

        // 遍历数组
        for (auto x : nums) {
            if (s <= 0) s = x; // 如果 s <= 0, 说明前面的子数组的和是负数或0，那么最大和就是当前元素 x
            else s += x; // 如果 s > 0, 说明前面的子数组的和是正数，那么最大和就是 s + x
            res = max(res, s); // 将 res 和 s 中更大的数返回给 res
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

        for (int x: nums) {
            if (sum > 0) sum += x;
            else sum = x;

            res = max(res, sum);
        }

        return res;
    }
};

