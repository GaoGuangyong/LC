
// DP
// 状态表示：
// f[i] 表示跳到第 i 个台阶的时候需要花费的体力，则答案为：f[n]

// 初始化：
// 初始时，可以从第 0 个台阶 或 第 1 个台阶开始爬，不需要花费体力
// f[0] = 0
// f[1] = 0

// 状态转移：
// 跳到第 i 个台阶有两种可能：从第 i - 2 或 i - 1 个台阶跳过来，故只需要求出这两种情况的值，取 min
// 从第 i - 1 个台阶跳过来，则 f[i] = f[i - 1] + cost[i - 1]
// 从第 i - 2 个台阶跳过来，则 f[i] = f[i - 2] + cost[i - 2]
// 取二者的最小值，f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2])

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // 定义状态数组
        vector<int> f(n + 1);

        // 初始化
        f[0] = 0;
        f[1] = 0;
        
        // 状态转移
        for (int i = 2; i <= n; i ++ ) {
            f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
        }

        return f[n];
    }
};


// 无注释版本
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> f(n + 1);

        f[0] = 0;
        f[1] = 0;

        for (int i = 2; i <= n; i ++ ) {
            f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
        } 

        return f[n];
    }
};