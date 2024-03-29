

// 题意：能否从从给定的元素中凑出总和的一半

// DP
// 0-1背包
// 【1】计算总和，如果总和为奇数，则无解，如果总和是偶数，则判断集合中选一些数是否能凑得总和的一半。
// 【2】做一遍背包
// 状态表示：
// f[i] 表示是否能凑出体积为 i 的方案（1 表示可以，0 表示不可以），则答案为：f[sum/2]

// 初始化：
// f[0] = 1 表示从所有数中选体积为 0 是一定可以凑出的，其余为 0 即可

// 状态转移：
// f[i] = f[i] | f[i - nums[i]]，分别对应选或者不选第 i 个物品, 只要有一个是 1，f[i] 就是 1 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0); // 求数组中所有元素的和
        if (sum & 1) return false; // 如果和是奇数，则无法划分

        int m = sum / 2; // 目标背包容量 m：总容量的一半

        // 定义状态数组
        vector<int> f(m + 1);

        // 初始化
        f[0] = 1; 
        
        // 状态转移
        // 枚举物品数量（1 ~ n）
        for (int i = 1; i <= n; i ++ ) {
            // 从大到小枚举背包容量（m ~ 0）
            for (int j = m; j >= 0; j -- ) {
                if (j >= nums[i - 1]) {
                    f[j] = f[j] | f[j - nums[i - 1]]; // 只要有一个是 1 就是 1
                }
            }
        }
        return f[m];
    }
};

// 无注释版本
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;

        int m = sum / 2;

        vector<int> f(m + 1);

        f[0] = 1;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = m; j >= 0; j -- ) {
                if (j >= nums[i - 1])
                    f[j] = f[j] | f[j - nums[i - 1]];
            }
        }

        return f[m];
    }
};

