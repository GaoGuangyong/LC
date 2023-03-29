// https://leetcode.cn/problems/JEj789/solution/dong-tai-gui-hua-si-lu-by-casperwnb-r698/

// DP
// 状态表示:
// f[i][0] 表示到第 i 间房子时, i 用 0 号颜色的花费
// f[i][1] 表示到第 i 间房子时, i 用 1 号颜色的花费
// f[i][2] 表示到第 i 间房子时, i 用 2 号颜色的花费
// 则答案为：min(f[n][0], min(f[n][1], f[n][2]))

// 初始化：
// 初始时，还未选择房子，三种颜色的花费都为 0
// f[0][0] = 0
// f[0][1] = 0
// f[0][2] = 0

// 状态转移:
// 第 i 间房子如果用 0 号颜色, 则前面的第 i - 1 间房子只能是用 1 或 2 号颜色
// 第 i 间房子如果用 1 号颜色, 则前面的第 i - 1 间房子只能是用 0 或 2 号颜色
// 第 i 间房子如果用 2 号颜色, 则前面的第 i - 1 间房子只能是用 0 或 1 号颜色
// 因此
// f[i][0] = min(f[i - 1][1], f[i - 1][2]) + costs[i][0];
// f[i][1] = min(f[i - 1][0], f[i - 1][2]) + costs[i][0];
// f[i][2] = min(f[i - 1][0], f[i - 1][1]) + costs[i][0];


class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(); // 一共 n 间房子
        costs.insert(costs.begin(), {0, 0, 0});  // 将原始数组往后挪动一位, 方便处理（妙）

        // 定义状态数组
        vector<vector<int>> f(n + 1, vector<int>(3, INT_MAX)); // 因为求 min 所以初始花费定为正无穷

        // 初始化
        f[0][0] = 0;
        f[0][1] = 0;
        f[0][2] = 0;

        // 状态转移
        for (int i = 1; i <= n; i ++ ) {
            f[i][0] = min(f[i - 1][1], f[i - 1][2]) + costs[i][0];
            f[i][1] = min(f[i - 1][0], f[i - 1][2]) + costs[i][1];
            f[i][2] = min(f[i - 1][0], f[i - 1][1]) + costs[i][2];
        }
        return min(f[n][0], min(f[n][1], f[n][2]));
    }
};


// 无注释版本
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        costs.insert(costs.begin(), {0, 0, 0});

        vector<vector<int>> f(n + 1, vector<int>(3, INT_MAX)); 

        f[0][0] = 0;
        f[0][1] = 0;
        f[0][2] = 0;

        for (int i = 1; i <= n; i ++ ) {
            f[i][0] = min(f[i - 1][1], f[i - 1][2]) + costs[i][0];
            f[i][1] = min(f[i - 1][0], f[i - 1][2]) + costs[i][1];
            f[i][2] = min(f[i - 1][0], f[i - 1][1]) + costs[i][2];
        }
        return min(f[n][0], min(f[n][1], f[n][2]));
    }
};

