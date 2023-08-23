

// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。


// 解法一：递归 + 子问题
class Solution {
public:
    // 辅助函数：从 nums1[i, nums1.size() - 1] 和 nums2[j, nums2.size() - 1] 合并后的数组里面查找第 k 个元素
    int findKthNumber(vector<int>& nums1, int i, vector<int> nums2, int j, int k) {
        // 为了方便，默认 nums1 是较短的数组，如果不是就交换 nums1 和 nums2
        if (nums1.size() - 1 - i + 1 > nums2.size() - 1 - j  + 1) return findKthNumber(nums2, j, nums1, i, k);
        
        // 递归出口：
        // 如果 nums1 已经是空的了，那么直接在 nums2 里找第 k 个数就行了
        if (nums1.size() - 1 - i + 1 == 0) return nums2[j + k - 1];
        // 如果 k 是 1，即找合并后的第一个数，那么只要在 nums1 和 nums2 的第一个数里找最小的那个数
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

    // 主函数：设合并后数组的第 k 个数就是中位数
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




// 解法二：双指针
class Solution {
public:
    // 求两个有序数组的中位数
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size(); // 计算两个数组总长度

        // 无论奇偶数，返回的两个数的下标都是 (len - 1) / 2 和 len / 2
        // 如果是奇数，则两个下标相等，偶数就是一左一右
        int k = len / 2; // 计算中位数的下标 

        int i = 0; // 数组 nums1 的索引
        int j = 0; // 数组 nums2 的索引

        int left = 0; // 左侧的数
        int right = 0; // 右侧的数
        
        // 在两个数组的末尾加上 INT_MAX，确保每次取数时一定能取到一个数
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);

        // 循环直到处理完 k 个元素
        while (i + j <= k) {
            // 先将 right 赋给 left，因为当前 right 是最新的中位数右边的元素
            left = right;
            // 取两个数组当前下标所指向的元素中更小的元素 作为当前中位数的值
            if (nums1[i] < nums2[j]) {
                right = nums1[i];
                i ++ ;
            }
            else {
                right = nums2[j];
                j ++ ;
            }
        }

        // 根据数组的总长度是奇数还是偶数来计算中位数
        if ((len % 2) == 0) 
            return (left + right) / 2.0;
        else 
            return right;
    }
};


// 解法三：STL 的 insert 函数 + 排序（笔试推荐）
// 题意：nums1 和 nums2 分别是两个已排序的整数数组，返回它们的中位数
// 使用 STL 的 insert 函数将 num2 拼接到 nums1 后面，对合并后的数组进行排序
// 如果两个数组长度之和为偶数，则返回中间两个元素的平均数作为中位数；否则返回中间的元素

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size(); // 计算两个数组的总长度
        nums1.insert(nums1.end(), nums2.begin(), nums2.end()); // 将 nums2 拼接到 nums1 后（该技巧在循环数组中也有应用：LC 503）
        sort(nums1.begin(), nums1.end()); // 对拼接后的数组进行排序

        // 如果长度为奇数，则返回中间一个数，如果长度是偶数，则返回中间两个数的平均值
        if (len % 2 == 1) 
            return nums1[len / 2];
        else 
            return (nums1[len / 2] + nums1[(len/ 2) - 1]) / 2.0;
    }
};

