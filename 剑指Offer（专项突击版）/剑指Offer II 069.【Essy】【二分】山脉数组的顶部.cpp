// 二分

// 山顶数组的性质：
// 山顶数 && 山顶数之前的数 都满足 arr[i - 1] < arr[i]
// 而山顶数右边都不满足这个性质，所以可以二分，山顶数就是边界

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // 山顶数可能的下标范围：[1 ~ n - 2]
        int l = 1;
        int r = arr.size() - 2;
        
        while (l < r) {
            int mid = l + r + 1 >> 1;
            // 如果当前数字 > 前一个数，说明山顶数在当前数字右边，或者就是当前数字
            if (arr[mid] > arr[mid - 1]) 
                l = mid;
            else 
                r = mid - 1;
        }

        return r;
    }
};

