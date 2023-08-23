
// 我们先使用一遍扫描找到左边保持升序的最后一个点的位置 l，和从右向左看保持降序的最后一个点的位置 r
// 如果已经这时候 l == r 说明已经排好序了，无需调整。
// 接下来我们从 l + 1 向右扫描
// 如果遇到有比 nums[l] 小的元素，说明最起码 nums[l] 不在正确位置上，那么 l --
// 同样的，我们从 r - 1 向左扫描
// 如果遇到有比 nums[r] 大的元素，说明最起码 nums[r] 不在正确的位置上，那么 r ++
// [l + 1 ~ r - 1] 就是需要重新排序的元素，长度为 r - l - 1。

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        // 从最左边开始，当两个数已经升序，则 l ++
        while (l < r && nums[l] <= nums[l + 1]) 
            l ++ ;
        // 从最右边开始，当两个数已经升序，则 r --
        while (r > l && nums[r] >= nums[r - 1]) 
            r -- ;

        // 如果此时 l == r，则整个数组原本就已经升序了，无需调整
        if (l == r) return 0;

        // 从 l + 1 向右扫描，如果遇到有比 nums[l] 小的元素，说明最起码 nums[l] 不在正确位置上，那么 l --
        for (int i = l + 1 ; i < n ; i ++ ) {
            while (l >= 0 && nums[i] < nums[l])
                l -- ;
        }
        // 从 r - 1 向左扫描，如果遇到有比 nums[r]大的元素，说明最起码 nums[r] 不在正确的位置上，那么 r ++
        for (int i = r - 1 ; i >= 0 ; i -- ) {
            while (r <= n - 1 && nums[i] > nums[r])
                r ++ ;
        }

        return r - l - 1;
    }
};


// 二刷
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

        for (int j = r - 1; j >= 0; j -- ) {
            while (r < n && nums[j] > nums[r]) r ++ ;
        }

        return r - l + 1 - 2;
    }
};
