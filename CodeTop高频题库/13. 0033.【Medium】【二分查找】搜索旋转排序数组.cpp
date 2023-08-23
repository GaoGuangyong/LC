
// https://leetcode.cn/problems/search-in-rotated-sorted-array/solution/yi-tu-jie-shi-by-pennx-1le4/

/*
         /
        /
       /
              / 
             /
            /   
*/



// 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1
// 数组中的值 互不相同 

// 输入：nums = [4,5,6,7,0,1,2], target = 0
// 输出：4


// 二分
// 先将区间划分成 2 个部分，然后在有序的区间里二分，画图理解

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分 nums 的下标
        int l = 0; // 下标起点
        int r = nums.size() - 1; // 下标终点

        // 采用第三种二分模板，即循环条件为 l <= r
        while (l <= r) {
            int mid = l + r >> 1; // 循环的第一步就是计算 mid

            // 如果当前二分的下标对应的值 == 目标，则找到了，返回其下标
            if (nums[mid] == target) return mid;

            // 如果当前二分的下标 mid 对应的值 >= 区间起点，则左半部分 [l ~ mid) 是升序的
            if (nums[mid] >= nums[l]) {
                // 若目标 target 在 mid 左边
                if (target >= nums[l] && target < nums[mid]) // 注意不要写错范围
                    r = mid - 1;
                // 若目标 target 在 mid 右边
                else 
                    l = mid + 1;
            }

            // 如果当前二分的下标 mid 对应的值 < 区间起点，则右半部分 (mid ~ r] 是升序的
            else if (nums[mid] < nums[l]) { // 注意 ！！！！！此处不能写成 if (nums[mid] < nums[l])，因为不是独立的判断条件
                // 若 target 在 mid 右边
                if (target > nums[mid] && target <= nums[r]) 
                    l = mid + 1;
                // 若 target 在 mid 左边
                else 
                    r = mid - 1;
            }
        }

        return -1;
    }
};

// 解法二：库函数
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        if (it != nums.end()) 
            return it - nums.begin();
        return -1;
    }
};


// 二刷
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + r >> 1;

            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            }
            else if (nums[mid] < nums[l]) {
                if (target > nums[mid] && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }

        return -1;
    }
};
