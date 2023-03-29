
// 二分
// 有重复元素的旋转数组可以看成 2 段非递减的数组
// 旋转数组一定要画图分析

class Solution {
public:
    int minArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        // 本题有重复元素，所以第一段的开头和第二段的结尾可能相同，因此先去除第二段结尾处和 nums[l] 相同的元素
        while (r > 0 && nums[r] == nums[0]) r -- ; 
        // 如果此时 nums[r] > nums[l]，则整个区间是非递减的，那么最小值就是第一个元素
        if (nums[r] > nums[0]) return nums[0]; 
        
        // 否则，必然有两段，可以二分（二分的是下标）
        while (l < r) {
            int mid = l + r >> 1;
            // 如果二分的值 nums[mid] < nums[0]，则说明答案在第二段，且答案为 mid 或在 mid 的左边
            if (nums[mid] < nums[0]) 
                r = mid; 
            else 
                l = mid + 1;
        }
        return nums[r];
    }
};


// 无注释版本
class Solution {
public:
    int minArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (r > 0 && nums[r] == nums[0]) r -- ; 
        if (nums[r] > nums[0]) return nums[0]; 

        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0]) 
                r = mid; 
            else 
                l = mid + 1;
        }
        return nums[r];
    }
};

