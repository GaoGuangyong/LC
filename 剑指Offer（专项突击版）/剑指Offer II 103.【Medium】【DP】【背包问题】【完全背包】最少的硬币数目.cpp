
// 解法一
// DP
// 完全背包
// 题目抽象：将硬币看成物品，硬币金额看成体积
// 相当于有 n 种物品（硬币），每种物品的体积是 coins[i]，每种物品可用无限次，问装满容量为 amount 的背包，所需要的最少物品数量
// 状态表示：
// f[i][j] 表示从前 1 ~ i 种物品中选，装满容量为 j 的背包，所需要的最少物品数量
// 答案为：f[n][amount] 就表示从前 n 种物品中选，且总金额为 amount 的所需要的最少硬币数

// 初始化:
// for (int i = 0; i < n + 1; i ++ ) f[i][0] = 0
// 表示从前 i 件物品中选出总容量 0，所需的物品个数为 0

// 状态转移：（背下来）
// 注：第 i 件物品的体积是 coins[i - 1]
// 若不选第 i 件物品，f[i][j] = f[i - 1][j]
// 若选择第 i 件物品，f[i][j] = f[i][j - coins[i - 1]] + 1
// 取二者得最小值即可

class Solution {
public:
    int INF = 1e5; // 定义一个满足题意得最大值 INF

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;
        // 定义状态数组
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INF));

        // 初始化
        for (int i = 0; i <= n; i ++ ) { // 物品数量可以是：0 ~ n
            f[i][0] = 0; // 注意本题是求最少物品数，不是方案数，所以这里是 0 而不是 1
        }

        // 状态计算
        // 枚举物品数量
        for (int i = 1; i <= n; i ++ ) {
            // 枚举背包容量
            for (int j = 0; j <= m; j ++ ) {
                // 状态计算
                f[i][j] = f[i - 1][j]; // 先计算不选的情况
                if (j >= coins[i - 1])
                    f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1); // 再和选的情况比较，取min
            }
         }
        if (f[n][m] == INF) // 如果最后还是初值，则无解
            f[n][m] = -1;
        return f[n][m];
    }
};

// 模板
vector<vector<int>> f(n + 1, vector<int>(m + 1, INF));

for (int i = 0; i <= n; i ++ ) {
    f[i][0] = 0;
}

// 枚举物品数量
for (int i = 1; i <= n; i ++ ) {
    // 枚举背包容量
    for (int j = 0; j <= m; j ++ ) {
        // 若不选第 i 件物品
        f[i][j] = f[i - 1][j];
        // 若选第 i 件物品
        if (j >= coins[i - 1]) 
            f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1);
    }
}

return f[n][m];


// 无注释版本

// 写法一：
class Solution {
public:
    int INF = 1e5;

    int coinChange(vector<int>& coins, int m) {
        int n = coins.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INF));

        for (int i = 0; i <= n; i ++ ) {
            f[i][0] = 0;
        }
        
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 0; j <= m; j ++ ) {
                f[i][j] = f[i - 1][j];
                if (j >= coins[i - 1])
                    f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1); 
            }
        }

        if (f[n][m] == INF) f[n][m] = -1;

        return f[n][m];
    }
};

// 写法二：
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;

        int INF = 1e5;
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INF));

        for (int i = 0; i <= n; i ++ ) f[i][0] = 0;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 0; j <= m; j ++ ) {
                if (j < coins[i - 1])
                    f[i][j] = f[i - 1][j];
                else
                    f[i][j] = min(f[i - 1][j], f[i][j - coins[i - 1]] + 1);
            }
        } 

        if (f[n][m] == INF) return -1;
        return f[n][m];
    }
};








// 解法二
// 参考此链接的一维优化代码 https://leetcode.cn/problems/coin-change/solution/er-wei-zhuan-yi-wei-dpzui-jian-ji-yi-don-3pfv/
// 完全背包问题：DP
// 求装满背包有几种方法，外层遍历背包，内层遍历物品
// 状态：f[i] 表示凑总金额 i 所需的硬币数量的最小值；答案 f[amount]
// 因为要求最小值，所以 f[i] = min(f[i], f[i - coins[j]] + 1)
// 物品体积：硬币面值
// 物品价值：1
// 背包容量：总金额

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INF = 1e9;
        int m = amount;

        vector<int> f(m + 1, INF); // 初始时赋一个特殊值用于特判（用 1e8 当作正无穷）
        // 定义容量初值
        f[0] = 0; // 初始时背包为空，容量为 0
        
        // 遍历背包（总金额）
        for (int i = 1; i <= m; i ++) { // 总金额 j 能由哪些硬币组成            
            // 遍历物品（硬币数量）
            for (int j = 0; j < coins.size(); j ++) { // 从 1 块钱遍历到 amount 块钱
                if (i >= coins[j]) { // 只有当 总金额 j >= 当前硬币面值 coins[j]，才考虑将它加入
                    f[i] = min(f[i], f[i - coins[j]] + 1); // 取最小值（不选该硬币，选该硬币）（ + 1 表示再算上选的这枚硬币数量 1 的贡献）
                }
            }
        }
        if (f[m] == INF) f[m] = -1; // 如果 f[m] 还是初值，则无解
        return f[m];
    }
};

