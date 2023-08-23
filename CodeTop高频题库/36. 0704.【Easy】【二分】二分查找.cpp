
// 二分模板

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            // 如果二分的值 >= 目标，则答案在 mid 或 mid 左边
            if (nums[mid] >= target) 
                r = mid;
            else 
                l = mid + 1;
        }
        if (nums[r] != target) return -1; // 也可以是 nums[l] 
        return r;
    }
};

