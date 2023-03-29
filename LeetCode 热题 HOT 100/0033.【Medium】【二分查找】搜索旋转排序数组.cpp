

// 二分
// 先将区间划分成 2 个部分，然后在对应的部分里二分

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + r >> 1;

            // 如果当前二分的点 == 目标，则找到了，返回其下标
            if (nums[mid] == target) return mid;

            // 如果当前二分的点 >= 区间起点，则左半部分 [l ~ mid) 是有序的
            if (nums[mid] >= nums[l]) {
                // 若 target 在左边
                if (target >= nums[l] && target < nums[mid]) 
                    r = mid - 1;
                // 若 target 在右边
                else 
                    l = mid + 1;
            }

            // 如果当前二分的点 < 区间起点，则右半部分 (mid ~ r] 是有序的
            else if (nums[mid] < nums[l]) {
                // 若 target 在右边
                if (target > nums[mid] && target <= nums[r]) 
                    l = mid + 1;
                // 若 target 在左边
                else 
                    r = mid - 1;
            }
        }

        return -1;
    }
};

// 无注释版本
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + r >> 1;

            if (nums[mid] == target) return mid;

            if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target < nums[mid]) 
                    r = mid - 1;
                else 
                    l = mid + 1;
            }

            else if (nums[mid] < nums[l]) {
                if (target > nums[mid] && target <= nums[r]) 
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
        }

        return -1;
    }
};

