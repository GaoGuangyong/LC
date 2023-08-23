

// 二分查找
// 和 LC 33题很像, LC 33题是在旋转数组中找一个数，本题是在旋转数组中找最小值
// 旋转数组的二分，要根据第一个数分，要特判一下整个数组是有序（没做旋转）的情况

/* 旋转后的数组示意图，我们要找的就是最小的那个数，即第二段的第一个数，或者就是第一个数
          /                   /
         /                   /
        /          或       /
              /            /
             /            /
            /            /
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        // 二分数组下标
        int l = 0; // 下标起点
        int r = nums.size() - 1; // 下标终点

        // 特判一下旋转后，数组没有改变的情况，即最后一个数比第一个数大
        if (nums[l] < nums[r]) return nums[0];
        
        while (l < r) {
            int mid = l + r >> 1;
            // 如果二分的数 < 第一个数，则答案在 mid 左边，或就是 mid
            if (nums[mid] < nums[0])
                r = mid;
            else 
                l = mid + 1;
        }

        return nums[l];
    }
};

