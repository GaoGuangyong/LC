// 二分查找
// 有单调性，考虑二分
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
        // 特判：如果数组为空，则返回 [-1, -1]
        if (nums.empty()) return {-1, -1}; 

        vector<int> res;

        // 二分找左端点
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) // 如果二分的值 mid >= target，则说明答案可能在 mid 或 mid 左边
                r = mid;
            else
                l = mid + 1;
        }
        res.push_back(l); // 保存左端点的下标

        // 二分找右端点
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

        // 如果二分完了都找不到答案，则返回 [-1, -1]
        if (nums[l] != target || nums[r] != target) {
            return {-1, -1}; 
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1}; 

        vector<int> res;

        // 二分找左端点
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        res.push_back(l);

        // 二分找右端点
        l = 0;
        r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        res.push_back(l); 

        if (nums[l] != target || nums[r] != target) {
            return {-1, -1}; 
        }
        
        return res;
    }
};


