


// 解法一：从前向后，维护一个最小价格
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int res = 0; // 用来存当前的最大利润
        int minv = nums[0]; // 维护最低价格，初始化为第一天的价格
        // 从前向后遍历数组
        for (int i = 1; i < nums.size(); i++) {
            res = max(res, nums[i] - minv); // 用当前价格 - 最低价格，如果比当前的最大利润还要大，就更新当前的最大利润
            minv = min(minv, nums[i]); // 如果当前的价格比最低价格还小，就更新最低价格
        }

        return res; // 遍历结束后，当前的最大利润就是最终的最大利润
    }
};



// 解法二：从后向前，维护一个最大价格 maxv (√)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxv = prices[n - 1]; // 初始时，最高价格为最后一天的价格

        int res = 0; // 用来存当前的最大利润

        // 从倒数第二天开始向前遍历价格数组，每次看当前价格后面有没有比当前价格大的
        for (int i = n - 2; i >= 0; i -- ) {
            // 每次更新目前为止的最高价格
            maxv = max(maxv, prices[i]);
            // 如果目前为止价格的最大值 > 今天的价格，则意味着在今天之后，存在股票价格比今天的价格高
            if (maxv > prices[i]) {
                res = max(res, maxv - prices[i]); // 比较价格差，更新最大利润
            }
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxv = prices[n - 1];

        int res = 0;

        for (int i = n - 2; i >= 0; i -- ) {
            maxv = max(maxv, prices[i]);
            if (prices[i] < maxv) {
                res = max(res, maxv - prices[i]);
            }
        }

        return res;
    }
};


