
// 有序数组 -> 二分
// 设 missed(idx) 表示 nums[0 ~ idx] 中缺失的数字个数 
// 如果 missed(idx - 1) < k <= missed(idx)
// 则说明第 k 个缺失的数字在 nums[idx - 1] 与 nums[idx] 之间，且比 nums[idx - 1] 大 k - missed(idx)

// 如何计算 missed(idx) ？
// num[0 ~ idx] 应该有 nums[idx] - nums[0] + 1 个数，但实际只有 idx + 1 个数
// 因此二者之差即为缺失的数字个数，missed(idx) = nums[idx] - nums[0] - idx  

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();

        int missed = 0; // 缺失的数字个数 

        // 二分数组的下标：找 nums[0 ~ mid] 之间缺失的数字个数  < k 的最后一个位置
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            missed = nums[mid] - nums[0] - mid; // nums[0 ~ mid] 之间缺失的数字个数 
            // 如果 nums[0 ~ mid] 之间缺失的数字个数  < k，说明 mid 可能是答案，或还在更后面
            if (missed < k) // 找到最后一个小于
                l = mid;
            else
                r = mid - 1;
        }

        missed = nums[l] - nums[0] - l; // nums[0 ~ l] 之间缺失的数字个数 
        return nums[l] + k - missed;
    }
};

