

//快速排序
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r) {
        // 当数组为空时，l = 0, r = -1, 会出现 l > r 的情况
        // 除了一开始需要判断 l > r 之外, 以后 只需要 判断 l == r 即可
        if (l >= r) return; // 递归出口：区间为空或只有一个元素，不需要排序，直接返回

        int x = nums[l + r >> 1]; // 选择中间元素作为基准值 x

        int i = l - 1; // 左指针 i 初始化为第一个元素的前一个位置
        int j = r + 1; // 右指针 j 初始化为最后一个元素的后一个位置

        while (i < j) {
            do i ++ ; while (nums[i] < x); // 当 nums[i] < x，则不管，i 继续向后走，直到第一个大于等于 x 的元素的位置
            do j -- ; while (nums[j] > x); // 当 nums[j] > x，则不管，j 继续向前走，直到第一个小于等于 x 的元素的位置
            if (i < j) swap(nums[i], nums[j]); // 若 i 在 j 左侧，则交换二者，保证大于x的在右侧，小于x的在左侧
        }

        quick_sort(nums, l, j); // 递归排序左侧区间，左侧区间为[l, j]
        quick_sort(nums, j + 1, r); // 递归排序右侧区间，右侧区间为[j + 1, r]
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};


// 二刷

class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int x = nums[(l + r) >> 1];

        int i = l - 1;
        int j = r + 1;

        while (i < j) {
            do i ++ ; while (nums[i] < x);
            do j -- ; while (nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }

        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};