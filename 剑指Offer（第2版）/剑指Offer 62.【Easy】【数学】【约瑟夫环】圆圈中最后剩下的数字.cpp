
// 题意：0 ~ n - 1，共 n 个数构成环，每次删掉第 m 个数字（删除后，从删除数字的下一个数字开始从 0 计数），返回最后剩的数

// 约瑟夫环问题，设 f(n, m) 表示一共有 n 个数排成一个环，每次删除第 m 个数
// 若起始下标为 0，则 f(n, m) = (f(n - 1, m) + m) % n
// 若起始下标为 1，则 f(n, m) = (f(n - 1, m) + m - 1) % n + 1

class Solution {
public:
    int lastRemaining(int n, int m) { 
        // 特判：如果只有一个数 0，那么 0 就是最后剩下的数
        if (n == 1) return 0; 

        // 用下一轮的结果计算上一轮的结果
        return (lastRemaining(n - 1, m) + m) % n ; 
    }
};


