

// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。

// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]



// 二分查找
// 有单调性，考虑二分，因为是要找左右下标，因此就对数组下标进行二分
// 两次二分查找，分别查找左右端点的下标

/*
                     /
                    /
          _________/     target
         /
        /
       /
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 特判：如果数组为空，则返回 {-1, -1}
        if (nums.empty()) return {-1, -1};

        vector<int> res;

        int l, r;

        // 二分找左端点（模板一）
        l = 0;
        r = nums.size() - 1;
        
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) // 如果二分的值 mid >= target，则说明答案可能在 mid 或 mid 左边
                r = mid;
            else
                l = mid + 1;
        }

        res.push_back(l); // 保存左端点的下标

        // 二分找右端点（模板二）
        l = 0;
        r = nums.size() - 1;

        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) // 如果二分的值 mid <= target，则说明答案可能在 mid 或 mid 右边
                l = mid; // l = mid，因此 l + r 后面再 + 1
            else
                r = mid - 1;
        }

        res.push_back(l); // 保存右端点的下标

        // 如果二分完了都找不到答案，则返回 {-1, -1}
        if (nums[l] != target || nums[r] != target) return {-1, -1}; 
        
        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        vector<int> res;

        int l, r;

        l = 0; 
        r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else 
                l = mid + 1;
        }

        res.push_back(l);

        l = 0; 
        r = nums.size() - 1;
        
        while (l < r) {
            int mid = l + r + 1>> 1;
            if (nums[mid] <= target)
                l = mid;
            else 
                r = mid - 1;
        }

        res.push_back(l);

        if (nums[l] != target || nums[r] != target) return {-1, -1}; 
        return res;
    }
};