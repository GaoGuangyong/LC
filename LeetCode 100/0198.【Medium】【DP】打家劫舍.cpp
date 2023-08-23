
// DP
// 状态表示：
// f[i] 表示在前 1 ~ i 个房子中，偷窃第 i 个房子的情况下，所偷窃的最大值
// g[i] 表示在前 1 ~ i 个房子中 不偷窃第 i 个房子的情况下，所偷窃的最大值
// 则答案为 max(f[n], g[n]) 即偷窃第 n 个房子 或 不偷窃第 n 个房子 两种情况种，所偷窃的金额的最大值

// 初始化：
// f[0] = 0
// g[0] = 0

// 状态转移：
// 对于 f[i]：偷窃第 i 个房子，则不能偷窃第 i - 1 个房子， 则所偷窃金额的最大值为：g[i - 1] + 第 i 个房子的金额 nums[i - 1]
// 对于 g[i]：不偷窃第 i 个房子， 则第 i - 1 个房子有 2 种选择：偷窃或者不偷窃都可以
// 如果偷第 i - 1 个房子，则为 f[i - 1]，如果不偷第 i - 1 个房子，则为 g[i - 1]，取二者中的最大值 max(f[i - 1], g[i - 1])

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // 定义状态数组
        vector<int> f(n + 1);
        vector<int> g(n + 1);

        // 初始化
        f[0] = 0;
        g[0] = 0; 

        // 状态转移
        for (int i = 1; i <= n; i ++ ) { 
            f[i] = g[i - 1] + nums[i - 1]; // 注意！！第 i 个房子的下标是 i - 1，和 f 的下标不同
            g[i] = max(f[i - 1], g[i - 1]); 
        }
        
        return max(f[n], g[n]); 
    }
};

// 无注释版本
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> f(n + 1);
        vector<int> g(n + 1);

        f[0] = 0;
        g[0] = 0;

        for (int i = 1; i <= n; i ++ ) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }

        return max(f[n], g[n]);
    }
};


// 扩展：LC 213、打家劫舍 II

// 状态表示：和上题相同
// 初始化：和上题相同
// 状态转移：和上题相同，只不过要分两种情况，分别从第 2 个房子开始做两次状态转移

//【1】不偷第 1 个房子，此时和上一题相同，答案为 max(f[n], g[n])
//【2】偷第 1 个房子，则一定不能偷第 n 个房子，答案为 g[n]
// 最终答案为【1】和【2】的最大值


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // 特判
        if (n == 1) return nums[0];

        // 定义状态数组
        vector<int> f(n + 1);
        vector<int> g(n + 1);

        // 不偷第 1 个房子，则 f[1] 是不合法状态，g[1] = 0
        f[1] = -1;
        g[1] = 0;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        int res1 = max(f[n], g[n]);

        // 偷第 1 个房子，则 g[1] 是不合法状态，f[1] = nums[0]
        f[1] = nums[0];
        g[1] = -1;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        int res2 = g[n];
        
        return max(res1, res2);
    }
};


// 无注释版本
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> f(n + 1);
        vector<int> g(n + 1);

        // 不偷第 1 个房子
        f[1] = -1;
        g[1] = 0;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        int res1 = max(f[n], g[n]);

        // 偷第 1 个房子
        f[1] = nums[0];
        g[1] = -1;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        int res2 = g[n];

        return max(res1, res2);
    }
};

