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
    int search(vector<int>& nums, int target) {
        // 特判：如果数组为空，则返回 0
        if (nums.empty()) return 0;

        // 二分找 target 的左端点
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) // 如果二分的值 mid >= target，则说明答案可能在 mid 或 mid 左边
                r = mid;
            else
                l = mid + 1;
        }
        
        // 记下当前找到的 target 的左端点
        int left = l;

        // 二分找 target 的右端点
        l = 0;
        r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) // 如果二分的值 mid <= target，则说明答案可能在 mid 或 mid 右边
                l = mid;
            else
                r = mid - 1;
        }

        // 记下当前找到的 target 的右端点
        int right = r;

        // 如果循环结束后，没有找到 target, 则返回 0 个 (注：改成 r 也一样)
        if (nums[l] != target || nums[r] != target) return 0;

        // [left, right]之间的元素个数为 right - left + 1
        return right - left + 1;
    }
};



// 无注释版本
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        // 二分找 target 的左端点
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) 
                r = mid;
            else
                l = mid + 1;
        }
        
        int left = l;

        // 二分找 target 的右端点
        l = 0;
        r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) 
                l = mid;
            else
                r = mid - 1;
        }

        int right = r;

        if (nums[l] != target || nums[r] != target) return 0;

        return right - left + 1;
    }
};



