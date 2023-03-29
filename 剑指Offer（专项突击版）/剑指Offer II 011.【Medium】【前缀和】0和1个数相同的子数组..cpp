// 前缀和
// 前缀和数组 s[i] = a1 + a2 + ... + ai = nums[0] + nums[1] + ... + nums[i - 1]
// 将数组中的 0 视作 -1，则求连续相同 0 和 1 个数的子数组就是求连续和为 0 的子数组
// 如果区间 [j + 1, i] 的元素和 s[i] - s[j] = 0，即 s[i] == s[j]，则说明区间 [j + 1, i] 内的 0，1 数量相同，求该区间长度 i - j 即可

// 使用哈希表记录前缀和及其下标（即 hash[s[i]] = i）
// 遍历所有的前缀和，若当前的前缀和 s[i] 在哈希表中出现过，则更新长度的最大值，否则将其值和下标加入哈希表

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        unordered_map<int, int> hash;
        hash[0] = 0; // s[0] = 0，下标初始化为 0 

        // 定义前缀和数组
        vector<int> s(n + 1);

        // 初始化前缀和数组
        for (int i = 1; i <= n; i ++ ) {
            // 当前枚举的数是 nums[i - 1]，如果是 0，则先变成 -1
            if (nums[i - 1] == 0) nums[i - 1] = -1; 
            // 求前缀和
            s[i] = s[i - 1] + nums[i - 1];
        }

        // 枚举所有的前缀和 s[i]
        for (int i = 1; i <= n; i ++ ) {
            // 如果 s[i] 在哈希表中存在，则区间 [hash[s[i], i] 符合要求，计算下标差：i - hash[s[i]]，并更新最大下标差
            if (hash.count(s[i]))
                res = max(res, i - hash[s[i]]);
            // 如果 s[i] 不在哈希表中，更新哈希表对应的值
            else
                hash[s[i]] = i;
        }

        return res;
    }
};


// 无注释版本

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        unordered_map<int, int> hash;
        hash[0] = 0;

        vector<int> s(n + 1);

        for (int i = 1; i <= n; i ++ ) {
            if (nums[i - 1] == 0) nums[i - 1] = -1;
            s[i] = s[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= n; i ++ ) {
            if (hash.count(s[i])) res = max(res, i - hash[s[i]]);
            else hash[s[i]] = i;
        }

        return res;
    }
};
