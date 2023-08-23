// 前缀和

// 前缀和数组 s[i] = a1 + a2 + ... + ai = nums[0] + nums[1] + ... + nums[i - 1]
// 利用前缀和数组求区间和：nums[l] + ... nums[r] = s[r] - s[l - 1]

// 需要寻找一个 < i 的 j，使得 s[i] - s[j] = k，即以 i 为右端点的区间 [j + 1, i] 内的元素和为 k
// 原题就转化成了寻找一共有多少个 j 满足 s[j] = s[i] - k

// 可以用哈希表来存每个前缀和及其出现的次数 -> hash[前缀和] = 个数
// 枚举前缀和数组，前缀和 s[j] 出现的个数（也就是 s[i] - k 出现的次数）

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); // 数组长度
        vector<int> s(n + 1); // 定义前缀和数组

        // 求前缀和数组
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + nums[i - 1];
        }

        // 定义前缀和及其个数
        unordered_map<int, int> hash; // hash[前缀和] = 个数
        hash[0] = 1; // 因为初始化时，s[0] = 0 ， 即前缀和等于 0 的个数为 1

        int res = 0;

        // 枚举前缀和数组，计算对于每一个位置 i，前面有多少个 j 满足要求
        for (int i = 1; i <= n; i ++ ) {
            res += hash[s[i] - k]; // s[j] = s[i] - k
            hash[s[i]] ++ ; // 当前的前缀和 s[i] 出现的次数 + 1
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> s(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + nums[i - 1];
        }

        unordered_map<int, int> hash;
        hash[0] = 1;

        int res = 0;

        for (int i = 1; i <= n; i ++ ) {
            res += hash[s[i] - k];
            hash[s[i]] ++ ;
        }
        
        return res;
    }
};

