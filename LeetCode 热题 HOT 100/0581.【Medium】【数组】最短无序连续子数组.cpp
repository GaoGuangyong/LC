
// 我们先使用一遍扫描找到左边保持升序的最后一个点的位置 left，和从右向左看保持降序的最后一个点的位置 right
// 如果已经这时候 left == right 说明已经排好序了，无需调整。
// 接下来我们从 left + 1 向右扫描
// 如果遇到有比 nums[left] 小的元素，说明最起码 nums[left] 不在正确位置上，那么 left --
// 同样的，我们从 right - 1 向左扫描
// 如果遇到有比 nums[right] 大的元素，说明最起码 nums[right] 不在正确的位置上，那么 right ++
// 最后，left 和 right 之间的元素就是需要重新排序的元素，长度为 right - left - 1。

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        // 从最左边开始，当两个数已经升序，则 left ++
        while (left < right && nums[left] <= nums[left + 1]) 
            left ++ ;
        // 从最右边开始，当两个数已经升序，则 right --
        while (right > left && nums[right] >= nums[right - 1]) 
            right -- ;
        // 如果此时 left == right，则整个数组原本就已经升序了，无需调整
        if (left == right) return 0;

        // 从 left + 1 向右扫描
        // 如果遇到有比 nums[left] 小的元素，说明最起码 nums[left] 不在正确位置上，那么 left --
        for (int i = left + 1 ; i < n ; i ++ ) {
            while (left >= 0 && nums[i] < nums[left])
                left --;
        }
        // 从 right - 1 向左扫描
        // 如果遇到有比 nums[right]大的元素，说明最起码 nums[right] 不在正确的位置上，那么 right ++
        for (int i = right - 1 ; i >= 0 ; i -- ) {
            while (right <= n - 1 && nums[i] > nums[right])
                right ++;
        }

        return right - left - 1;
    }
};

// 无注释版
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while (l < r && nums[l] <= nums[l + 1]) l ++ ;
        while (l < r && nums[r] >= nums[r - 1]) r -- ;
        if (l == r) return 0;

        for (int i = l + 1; i < n; i ++ ) {
            while (l >= 0 && nums[i] < nums[l]) l -- ;
        }
        for (int i = r - 1; i >= 0; i -- ) {
            while (r < n && nums[i] > nums[r]) r ++ ;
        }

        return r - l - 1;
    }
};

