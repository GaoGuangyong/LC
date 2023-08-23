
// DP
// 给两个整数数组 nums1 和 nums2 ，返回 两个数组的 最长公共子数组 的长度
// 子数组：要求连续

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // 状态表示：f[i][j] 表示 nums1[1 ~ i] 和 nums2[1 ~ j] 的 最长公共子数组的长度，则答案为所有的 f[i][j] 取 max
        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        // 初始化：长度最少为 0，可以省略不写
        
        // 状态转移：
        int res = 0;
        for (int i = 1; i <= m; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                // 只有在 nums1[i - 1] 和 nums2[j - 1] 相等时，最长公共子数组的长度可以在之前的基础上加一
                if (nums1[i - 1] == nums2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    res = max(res, f[i][j]); // 更新最长公共子数组的长度
                }
            }
        }

        return res;
    }
};

