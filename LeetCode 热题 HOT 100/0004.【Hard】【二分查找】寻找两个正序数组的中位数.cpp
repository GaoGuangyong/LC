// 递归 + 子问题

class Solution {
public:
    // 辅助函数：从 nums1[i, nums1.size() - 1] 和 nums2[j, nums2.size() - 1] 合并后的数组里面查找第 k 个元素
    int findKthNumber(vector<int>& nums1, int i, vector<int> nums2, int j, int k) {
        // 为了方便，默认 nums1 的长度 <= nums2 的长度，如果不是就交换 nums1 和 nums2
        if (nums1.size() - 1 - i + 1 > nums2.size() - 1 - j  + 1)
            return findKthNumber(nums2, j, nums1, i, k);
        // 现在，nums1是较短的数组
        
        // 递归出口：如果 nums1 已经是空的了，那么直接在 nums2 里找第 k 个数就行了
        if (nums1.size() - 1 - i + 1 == 0)
            return nums2[j + k - 1];

        // 递归出口：如果 k 是 1，即找合并后的第一个数，那么只要在 nums1 和 nums2 的第一个数里找最小的那个数
        if (k == 1) return min(nums1[i], nums2[j]);

        // 下面要进行递归，要分别取两个数组中第 k/2 个数进行比较
        // 因为 nums1 是比较短的，所以 si 有可能越界，所以要取 min
        int si = min(i + k / 2 - 1, int(nums1.size() - 1)); // nums1 中第 k/2 个数的下标
        int sj = j + k / 2 - 1; // nums2 中第 k/2 个数的下标

        // 比较两个数组中第 k/2 个数的大小，将小的数前面的部分都删去，即从下一个位置开始是剩下的数组
        // 注意 k 表示找第几个数，是从 1 开始的
        if (nums1[si] < nums2[sj]) // 将 nums1[0 ~ si] 删去
            return findKthNumber(nums1, si + 1, nums2, j, k - (si - i + 1)); // k 减掉的数就是删去的数字个数
        else // 将 nums2[0 ~ sj] 删去
            return findKthNumber(nums1, i, nums2, sj + 1, k - (sj - j + 1)); // k 减掉的数就是删去的数字个数
    }

    // 设合并后数组的第 k 个数就是中位数
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); // nums1 的长度
        int m = nums2.size(); // nums2 的长度
        int t = m + n; // 总长度

        // 取合并后数组的第 k1 个数 left 和第 k2 个数 right，则第 k 个数 1.0 * res = (left + right) / 2
        int k1 = (t + 1) / 2;
        int k2 = (t + 2) / 2;

        int left = findKthNumber(nums1, 0, nums2, 0, k1); // 查找数组 nums1 和 nums2 的第 k1 个数 left
        int right = findKthNumber(nums1, 0, nums2, 0, k2); // 查找数组 nums1 和 nums2 的第 k2 个数 right

        double res = 1.0 * (left + right) / 2;
        return res;

    }
};

