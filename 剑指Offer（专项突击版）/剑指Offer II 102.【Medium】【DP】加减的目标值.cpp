

// 解法一
// DP  背包问题
// 状态表示：f[i] 在数组中选择出总和为 i 的方案数
// 设数组 nums 的总和为 sum, 添加 + 号的元素总和为 sumA, 添加负号的元素总和为 sumB, 则有以下关系
// sumA + sumB = sum
// sumA - sumB = target
// 由上面两个式子推导出 sumA = (sum + target) / 2
// 该题目就转化为：在数组中选出部分元素，给他们加上 + 号，求这些元素的总和为 sumA 的方案数
// 答案：f[sumA]
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) < 0 || (sum + target) & 1) { // 如果 sumA < 0 或是奇数，则无法划分
            return false;
        }

        int sumA = (sum + target) / 2; // 计算目标和
        vector<int> f(sumA + 1); // 定义状态
        f[0] = 1; // 初始化

        // 枚举每个物品
        for (int i = 0; i < n; i ++) {
            // 从大到小枚举每个物品的体积
            for (int j = sumA; j >= 0; j --) {
                if (j >= nums[i]) {
                    f[j] += f[j - nums[i]]; // 按位或，只要有一个是 1 就是 1
                }
            }
        }
        return f[sumA];
    }
};


// 解法二 （推荐）
// DP
// 状态表示：
// f[i][j] 表示前 1 ~ i 个数，总和为 j 的所有方案个数，则答案为：f[n][target]

// 初始化：
// f[0][0] = 1 表示

// 状态转移：
// 将 f[i][j] 按照第 i 个数 nums[i-1] 取正或取负 分成两种情况：
// 取正：f[i][j] = f[i − 1][j − nums[i]]
// 取负：f[i][j] = f[i − 1][j + nums[i]]
// 将二者相加，f[i][j] = f[i − 1][j − nums[i]] + f[i − 1][j + nums[i]]

// 总和 j 的范围为 [-1000, 1000]，有可能是负数，但数组没有负下标 所以给 j 加上偏移量，使其范围变成 [0, 2000]

// 注意：先不要管偏移量的问题，最后统一加偏移量
// 要满足总和 j 的范围在 [-1000，1000]
// 取正时，因为 j <= 1000，而 j 减去正数后不可能 > 1000，故只需判断 j - nums[i - 1] >= -1000
// 取负时，因为 j >= -1000，而 j 减去负数后不可能 < -1000，故只需判断 j + nums[i - 1]  <= 1000

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int Offset = 1000;

        // 定义状态数组
        vector<vector<int>> f(n + 1, vector<int>(2001)); // -1000 <= target <= 1000，最多 2001 个可能
        // 初始化
        f[0][0 + Offset] = 1; // 选 0 个数，总和也是 0 的的方案数为 1（注意加上了一个偏移量 Offset）
        // 状态转移
        for (int i = 1; i <= n; i ++ ) {
            for (int j = -1000; j <= 1000; j ++ ) {
                // nums[i - 1] 取正数
                if (j - nums[i - 1] >= -1000)
                    f[i][j + Offset] += f[i - 1][j - nums[i - 1] + Offset];
                // nums[i - 1] 取负数
                if (j + nums[i - 1] <= 1000)
                    f[i][j + Offset] += f[i - 1][j + nums[i - 1] + Offset];
            }
        }
        return f[n][target + Offset]; // 在前 n 个数里选，总和是 target 的方案数量
    }
};


// 解法二的无注释版本
// 先不管 offset
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> f(n + 1, vector<int>(2001));

        f[0][0] = 1;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = -1000; j <= 1000; j ++ ) {
                if (j - nums[i - 1] >= -1000) f[i][j] += f[i - 1][j - nums[i - 1]];
                if (j + nums[i - 1] <= 1000) f[i][j] += f[i - 1][j + nums[i - 1]];
            }
        }

        return f[n][target];
    }
};

// 再同意给 j 加 offset
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = 1000;

        vector<vector<int>> f(n + 1, vector<int>(2001));

        f[0][0 + offset] = 1;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = -1000; j <= 1000; j ++ ) {
                if (j - nums[i - 1] >= -1000) f[i][j + offset] += f[i - 1][j - nums[i - 1] + offset];
                if (j + nums[i - 1] <= 1000) f[i][j + offset] += f[i - 1][j + nums[i - 1] + offset];
            }
        }

        return f[n][target + offset];
    }
};

