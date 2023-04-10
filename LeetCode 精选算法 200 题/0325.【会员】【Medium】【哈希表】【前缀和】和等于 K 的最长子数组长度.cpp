
// 对于这种问题，常用的思路是先确定一个端点，然后再考虑对另一个端点的优化：优化方式尽量往二分查找和哈希表上面靠

// 使用前缀和数组进行优化：nums[j ~ i] 的和为 k 即 s[i] - s[j - 1] = k
// 从前往后枚举左端点 j，当枚举到 s[j] 的时候，判断 s[i] = k + s[j - 1] 是否存在
// 如果存在，i = hash[k + s[j - 1]]，用该区间长度 i - j + 1 更新最大长度
// 为了快速找到 k + s[j - 1]，将前缀和数组的元素预先存到哈希表中

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        // 定义并实现前缀和数组
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + nums[i - 1];
        }

        // 定义一个哈希表，存前缀和 s[i] 及其最后出现的下标 i
        unordered_map<int, int> hash;
        for (int i = 1; i <= n; i ++ ) hash[s[i]] = i;
        
        // 枚举子数组的左端点 j
        int res = 0;
        for (int j = 1; j <= n; j ++ ) {
            if (hash.count(k + s[j - 1])) {
                int i = hash[k + s[j - 1]];
                res = max(res, i - j + 1);
            }
        }

        return res;
    }
};


// 写法二：有误，暂未想到
// 对于这种问题，常用的思路是先确定一个端点，然后再考虑对另一个端点的优化：优化方式尽量往二分查找和哈希表上面靠

// 使用前缀和数组进行优化：nums[j ~ i] 的和为 k 即 s[i] - s[j - 1] = k
// 从前往后枚举右端点 i，当枚举到 s[i] 的时候，判断 s[j - 1] = s[i] - k 是否存在
// 如果存在，j = hash[s[i] - k] + 1，用该区间长度 i - j + 1 更新最大长度
// 为了快速找到 s[i] - k，将前缀和数组的元素预先存到哈希表中

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        // 定义并实现前缀和数组
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + nums[i - 1];
        }

        // 定义一个哈希表，存前缀和 s[i] 及其最先出现的下标 i
        unordered_map<int, int> hash;
        for (int i = n; i >= 1; i -- ) hash[s[i]] = i;
        
        // 枚举子数组的右端点 i
        int res = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (hash.count(s[i] - k)) {
                int j = hash[s[i] - k] + 1;
                res = max(res, i - j + 1);
            }
        }

        return res;
    }
};
