
// https://www.acwing.com/activity/content/code/content/1410815/

// 前缀和 + DP

// 从 1 到 n 枚举，对于每个当前遍历的位置 i：设这个位置是翻转后第一个 1 的位置
// 求出左边 [1 ~ i - 1] 有多少个 1 以及右边 [i ~ n] 有多少个 0，然后令前面的 1 变成 0，后面的 0 变成 1
// 左边 1 的个数 + 右边 0 的个数，就是当前位置 i 对应的总操作个数
// 枚举之后取最小值即可

// 为了快速求出某个区间内 0 和 1 的个数，可以使用前缀和进行优化
// 设前缀和数组是 f，则 s[i ~ j] 内的元素的和是 f[j] - f[i - 1]
// 则 f[i] 表示 s[1 ~ i] 的和，即前 i 个数中 1 的个数
// s[1 ~ i - 1] 中 1 的个数是：f[i - 1]
// s[i ~ n] 中 0 的个数是：[i ~ n] 的总个数 - [i ~ n] 中 1 的个数：(n - i + 1) - (f[n] - f[i - 1])

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();

        // 定义前缀和数组
        vector<int> f(n + 1);
        // 初始化前缀和数组
        for (int i = 1; i <= n; i ++ ) {
            f[i] = f[i - 1] + (s[i - 1] - '0'); // 将字符型数字转化为整型数字
        }

        // 因为求最少翻转次数，故初始时，给定一个最大翻转次数（s 全是 1，都变成 0 需要转换的次数就是 1 的个数 f[n]）
        int res = f[n];

        // 从前往后枚举
        for (int i = 1; i <= n; i ++ ) {
            int left = f[i - 1]; // 求左侧 [1, i - 1] 中 1 的个数
            int right = (n - i + 1) - (f[n] - f[i - 1]); // 求右侧 [i, n] 中 0 的个数
            
            res = min(res, left + right); // 更新最小翻转次数
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();

        vector<int> f(n + 1);

        for (int i = 1; i <= n; i ++ ) {
            f[i] = f[i - 1] + (s[i - 1] - '0');
        }

        int res = f[n];

        for (int i = 1; i <= n; i ++ ) {
            int left = f[i - 1];
            int right = (n - i + 1) - (f[n] - f[i - 1]);

            res = min(res, left + right);
        }

        return res;
    }
};



