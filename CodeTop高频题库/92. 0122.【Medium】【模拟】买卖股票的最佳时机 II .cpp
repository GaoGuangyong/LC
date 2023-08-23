

// 模拟
// 与121题差别：
// 121：只能买卖一次
// 122：可以多次买卖，但在买入股票前，手中的股票必须卖出
// 特点：
// prices[i] 买入，prices[j] 卖出
// 等价于 prices[i] 买入，prices[i+1] 卖出，prices[i+1] 买入，prices[i+2] 卖出
// ...... prices[j-1] 卖出，prices[j-1] 买入，prices[j] 卖出

// 即可以把任何一种购买方式拆成一天一天的买入再卖出
// 即利润的最大值为，将所有 (prices[i + 1] - prices[i]) > 0 的相加

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0; // 利润，最开始利润为 0
        for (int i = 0; i + 1 < prices.size(); i ++ ) {
            int t = prices[i + 1] - prices[i]; // 当天买入第二天再卖出的利润
            if (t > 0) res += t;
        }
        return res;
    }
};

