
// 枚举
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0); // 先计算整个数组的元素和

        int s = 0; // s 表示 nums[i] 前的元素和

        // 从前往后枚举，nums[i] 前的和为 s, nums[i] 后的和为 sum - s - nums[i]
        for (int i = 0; i < nums.size(); i ++ ) {
            // 如果当前元素的前后和相等，则找到了中心下标，就是当前元素的下标
            if (s == sum - s - nums[i]) {
                return i;
            }
            s += nums[i]; // 把当前元素加到 s 上，继续下一轮枚举
        }

        // 如果无解，返回 - 1
        return -1;
    }
};


// 无注释版本
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int s = 0;

        for (int i = 0; i < nums.size(); i ++ ) {
            if (s == sum - nums[i] - s) return i;
            s += nums[i];
        }

        return -1;
    }
};

