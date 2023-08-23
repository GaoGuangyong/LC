// 二分
// 因为题目要求返回任意一个峰值即可，所以考虑二分查找
// 题目保证了 nums[mid] != nums[mid + 1]

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            // 如果二分的值 nums[mid] 比他右边的数大，则答案在 mid 或 mid 左侧
            if (nums[mid] > nums[mid + 1]) 
                r = mid;
            else 
                l = mid + 1;
        }
        return l;
    }
};


// 笔试解法
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        auto it = max_element(nums.begin(), nums.end());
        return it - nums.begin();
    }
};

