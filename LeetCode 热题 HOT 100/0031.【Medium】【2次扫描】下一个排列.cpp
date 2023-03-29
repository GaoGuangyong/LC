
//
// 本题考查自己实现库函数 next_permutation：可以产生按字典序的下一个排列
// 应该尽可能保证高位不变，所以从后往前找
// 画折线图分析

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // 从后往前找到要变动的位置 k - 1
        int k = n - 1;
        // 只要前一个元素 >= 当前元素，就继续往前，直到前一个元素 < 当前元素
        while (k > 0 && nums[k - 1] >= nums[k]) { 
            k -- ;
        } // 循环结束时，nums[k - 1] < nums[k] 或 k == 0
        
        // 如果此时 k = 0，则说明整个数组是从大到小排列的，下一个排列就变回字典序的第一个数
        if (k == 0) reverse(nums.begin(), nums.end());
        // 否则，在 nums[k ~ n - 1] 从后往前找第一个 > nums[k - 1] 的元素 nums[t]，和 nums[k - 1] 交换
        else {
            int t = n - 1;
            // 只要 nums[t] 不大于 nums[k - 1] 就一直往左找
            while (t > 0 && nums[t] <= nums[k - 1]) { 
                t -- ;
            }
            swap(nums[t], nums[k - 1]);

            // 交换好了之后，要把 nums[k ~ n - 1] 变成升序，现在还是降序，所以直接 reverse
            reverse(nums.begin() + k, nums.end());
        }
    }
};


// 无注释版本
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int k = n - 1;
        while (k > 0 && nums[k - 1] >= nums[k]) {
            k -- ;
        }
        
        if (k == 0) reverse(nums.begin(), nums.end());
        else {
            int t = n - 1;
            while (t > 0 && nums[t] <= nums[k - 1]) {
                t -- ;
            }
            swap(nums[t], nums[k - 1]);
            reverse(nums.begin() + k, nums.end());
        }
    }
};

