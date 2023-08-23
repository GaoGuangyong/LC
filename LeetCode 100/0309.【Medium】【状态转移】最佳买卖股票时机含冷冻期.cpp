
// 状态转移的 DP，具体的状态转移参考笔记

// 状态转移 DP

// 状态表示：
// 用 f[i] 表示第 i 天结束之后的钱数（下标从 0 开始）
// f[i][0] 目前不持有任何股票，且处于冷冻期
// f[i][1] 目前持有 1 支股票
// f[i][2] 目前不持有任何股票，且今天卖出
// 则答案为 f[n - 1][0]、f[n - 1][1]、f[n - 1][2] 的最大值

// 初始化：
// 第 0 天时，如果持有股票，那么只能是在第 0 天买入的，则初始钱数为 −prices[0]
// f[0][1] = -prices[0]
// 第 0 天时，如果不持有股票，则初始钱数为 0
// f[0][0] = 0

// 状态转移：
// 第 i 天不持有股票，则可能前一天就不持有股票 或 前一天卖出股票：
// f[i][0] = max(f[i-1][0], f[i-1][2])
// 第 i 天持有股票，则可能前一天就持有股票 或 前一天处于冷冻期，今天买入股票：
// f[i][1] = max(f[i-1][1], f[i-1][0] - prices[i])
// 第 i 天卖出股票，则只可能前一天持有股票，今天卖出：
// f[i][2] = f[i-1][1] + prices[i]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); // 天数 n (0 ~ n - 1)
        
        // 定义状态数组
        vector<vector<int>> f(n, vector<int>(3, -1)); // 每天都有 3 种状态，状态值初始化为一个负数
        
        // 初始化
        f[0][0] = 0;
        f[0][1] = -prices[0];

        // 状态转移
        for (int i = 1; i < n; i ++ ) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i]);
            f[i][2] = f[i-1][1] + prices[i];
        }
        return max(f[n - 1][0], max(f[n - 1][1], f[n - 1][2])); // 返回第 n - 1 天，三种状态的最大值
    }
};

// 无注释版本
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> f(n, vector<int>(3, -1));

        f[0][1] = -prices[0]; 
        f[0][0] = 0; 

        for (int i = 1; i < n; i ++ ) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i]);
            f[i][2] = f[i - 1][1] + prices[i];
        }
        return max(f[n - 1][0], max(f[n - 1][1], f[n - 1][2]));
    }
};

// 二刷
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> f(n, vector<int>(3, -1));

        f[0][0] = 0;
        f[0][1] = -prices[0];

        for (int i = 1; i < n; i ++ ) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2]);
            f[i][1] = max(f[i - 1][0] - prices[i], f[i - 1][1]);
            f[i][2] = f[i - 1][1] + prices[i];
        }

        return max(f[n - 1][0], max(f[n - 1][1], f[n - 1][2]));
    }
};
