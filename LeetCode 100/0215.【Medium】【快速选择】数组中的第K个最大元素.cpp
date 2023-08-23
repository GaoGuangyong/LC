
// 快速选择算法 模板题 -> 选择第 k 大的数
// 快速选择算法: 在快排的过程中，根据 K 在哪一边，只递归那一边即可（不必像快排一样，两边都递归）
// 把区间 [l, r] 分成两部分，[l, j] 和 [j + 1, r] 则左侧区间的元素个数为 j - l + 1
// 选择第 k 大的数：左侧区间 [l, j] >= x 右侧区间 [j + 1, r] <= x
// 选择第 k 小的数：左侧区间 [l, j] <= x 右侧区间 [j + 1, r] >= x

class Solution {
public:
    // 辅助函数：返回 nums[l ~ r] 中第 k 大的数
    int quick_select(vector<int>& nums, int l, int r, int k) {
        // 递归出口：区间长度为 0 或 0 以下
        if (l >= r) return nums[l];
        // 因为采用的是 do while，所以初始时 i, j 在 l - 1, r + 1
        int i = l - 1;
        int j = r + 1;
        
        // 快速选择算法
        int x = nums[l + r >> 1]; // 获取中间元素
        while (i < j) {
            // 如果 nums[i] > x，则不用交换（等于 x 的要交换到右边），i ++ 
            do i ++ ; while (nums[i] > x);  // 第 k 大，这里就是 > x
            // 如果 nums[j] < x，则不用交换（等于 x 的要交换到左边），j -- 
            do j -- ; while (nums[j] < x);
            // 否则，交换 nums[i] 与 nums[j]
            if (i < j) swap(nums[i], nums[j]);
        }

        // 若 k <= 左侧区间元素的个数，则第 k 大的数一定在左侧区间，递归左侧区间，找左侧区间第 k 大的数
        if (k <= j - l + 1) 
            return quick_select(nums, l, j, k);
        // 否则，第 k 大的数一定在右侧区间，递归右侧区间，找右侧区间 第 k - (j - l + 1) 大的数
        else 
            return quick_select(nums, j + 1, r, k - (j - l + 1));
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, 0, nums.size() - 1, k);
    }
};

// 无注释版本
class Solution {
public:
    int quick_select(vector<int> nums, int l, int r, int k) {
        if (l >= r) return nums[l];
        int i = l - 1;
        int j = r + 1;

        int x = nums[l + r >> 1];
        while (i < j) {
            do i ++ ; while (nums[i] > x);
            do j -- ; while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }

        if (k <= j - l + 1) return quick_select(nums, l, j, k);
        else return quick_select(nums, j + 1, r, k - (j - l + 1));
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quick_select(nums, 0, n - 1, k);
    }
};

