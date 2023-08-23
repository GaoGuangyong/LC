




// 贪心

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN; // 因为答案可能是负值，所以初始化为负无穷

        int s = 0; // s 代表以当前元素的前一个元素为结尾的连续子数组的最大和

        // 遍历数组，计算 s，更新 res 的最大值
        for (auto x : nums) {
            if (s <= 0) s = x; // 如果 s <= 0, 说明前面的子数组的和是负数 或 0，那么最大和就是当前元素 x
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

