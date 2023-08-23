// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// 数学
// 调用 1 次 Rand7() 可以生成 [1 ~ 7] 的数
// 调用 2 次 Rand7() 生成 [1 ~ 49] 的数，方法如下：
// rand7() * 7 可以生成 [7 ~ 49] 的数
// rand7() * 7 + rand7() 可以生成 [8 ~ 56] 的数
// rand7() * 7 + rand7() - 7 可以生成 [1 ~ 49] 的数

// 如果生成的是 [41 ~ 49] 的数，则重新进行 Rand10() 操作
// 如果生成的是 [1 ~ 40] 的数，通过 % 10 的结果分为 10 组，每组有 4 个数
// 如果 % 10 = 1，则对应数字 1
// 如果 % 10 = 2，则对应数字 2
// ...
// 如果 % 10 = 9，则对应数字 9
// 如果 % 10 = 0，则对应数字 10

class Solution {
public:
    int rand10() {
        int t = rand7() * 7 + rand7() - 7 ; // 技巧
        if (t > 40) return rand10();
        // 只有 1 到 40 保留下来
        int m = t % 10; // 看在第几组
        return m == 0 ? 10 : m;
    }
};

