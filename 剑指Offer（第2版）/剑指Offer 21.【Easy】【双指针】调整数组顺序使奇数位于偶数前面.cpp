
// 双指针

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        // 用 l 从前往后遍历，用 r 从后往前遍历
        int l = 0;
        int r = nums.size() - 1;

        // 只要还没相遇，就循环
        while (l < r) {
            while (l < r && nums[l] % 2 == 1) l ++ ; // 如果 l 遇到奇数，则跳过
            while (l < r && nums[r] % 2 == 0) r -- ; // 如果 r 遇到偶数，则跳过
            if (l < r) swap(nums[l], nums[r]); // 如果 l 遇到偶数，r 遇到奇数，则交换二者
        }

        return nums;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            while (l < r && nums[l] % 2 == 1) l ++ ;
            while (l < r && nums[r] % 2 == 0) r -- ;
            if (l < r) swap(nums[l], nums[r]);
        }

        return nums;
    }
};


