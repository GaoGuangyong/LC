// 解法一：DP
// https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/di-zeng-zi-xu-lie-by-kino-58-ixhb/
// https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/

// DP 相似题目：673、674

// 状态表示
// f[i] 表示以 nums[i] 结尾的最长上升子序列的长度

// 初始化
// 每个元素都至少可以单独成为子序列，长度至少为 1

// 状态转移
// 对于每一个遍历的位置 i，都在其前面找一个 j
// 当 nums[j] >= nums[i] 时：nums[i] 无法接在 nums[j] 之后，此情况上升子序列不成立，跳过
// 当 nums[j] < nums[i]  时：nums[i] 可以接在 nums[j] 之后，此情况下最长上升子序列长度为 f[j] + 1
// 每次更新该序列长度的最大值，即：if (nums [j] < nums[i]) f[i] = max(f[i], f[i] + 1)


// 写法一（推荐）
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;

        int n = nums.size();

        // 定义状态数组
        vector<int> f(n + 1);

        // 初始化 + 状态转移
        // 对于每一个遍历的位置 i，都在其前面找一个 j
        for (int i = 0; i < n; i ++ ) {
            f[i] = 1; // nums[i] 自身可以视为长度为 1 的递增子序列
            for (int j = 0; j < i; j ++ ) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1); // 每次更新 f[i] 为目前为止的最大值
                }
            }
            // 当每个 f[i] 计算完后，更新结果
            res = max(res, f[i]);
        }
        return res;
    }
};

// 二刷
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        vector<int> f(n + 1);

        for (int i = 0; i < n; i ++ ) {
            f[i] = 1;
            for (int j = 0; j < i; j ++ ) {
                if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }

        return res;
    }
};


// 写法二
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> f(n + 1);

        for (int i = 0; i < n; i ++ ) {
            f[i] = 1;
            for (int j = 0; j < i; j ++ ) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i ++ ) res = max(res, f[i]);

        return res;
    }
};




// 解法二
// 二分，过程见笔记
// 维护一个数组 q，q[k] 表示长度为 k+1 的递增子序列中，结尾的最小值
// 维护数组 q 的过程：
// 遍历 a 数组，假设当前遍历到的是 a[i]，先二分找到 < a[i] 的最后一个元素（q[k-1]），把 a[i] 放到其后面 (q[k])

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> q;

        // 从前往后枚举每一个元素
        for (auto x: nums) {
            // 如果当前元素比数组 q 的最后一个元素都大，那么就可以接到最后一个元素后面，这个时候说明产生了一个更长的序列，结尾元素就是x
            if (q.empty() || x > q.back()) q.push_back(x);
            // 如果当前元素不超过数组 q 的第一个元素，那么 x 不可能接入到任何元素后面，更新长度为 1 的递增子序列结尾最小值为 x
            else if (x <= q[0]) q[0] = x;
            // 否则， 二分，找到 < x 的最后一个元素，看 x 最大能接入到哪个元素的后面
            else {
                int l = 0;
                int r = q.size() - 1;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (q[mid] < x) l = mid; // 如果 q[mid] < x，则答案可能是 mid 或在 mid 右边
                    else r = mid - 1;
                }
                // 将找到的位置的下一个位置更新为x，语义是 “该长度的最长上升子序列结尾的最小值是x”
                q[l + 1] = x;
            }
        }
        return q.size();
    }
};



