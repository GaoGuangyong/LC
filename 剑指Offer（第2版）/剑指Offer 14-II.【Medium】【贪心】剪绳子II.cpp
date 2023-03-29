
// 贪心
// 思路：选用尽量多的 3，直到剩下 2 或者 4 时，用 2
// 特判：题目要求至少分为两段，n = 2 时, 最大乘积为 1 × 1 = 1, n = 3 时, 最大乘积为 1 × 2 = 2

// 相比上一题，结果 res 可能爆 int，要用 long long 存，并对结果取 mod = 1e9 + 7

class Solution {
public:
    int mod = 1e9 + 7;

    int cuttingRope(int n) {
        long long res = 1; // 结果：被分成的绳子长度的乘积

        if (n == 2 || n == 3)  return n - 1;
        
        while (n > 4) {
            n = n - 3; // 尽可能地多剪长度为 3 的绳子
            res = (res * 3) % mod; // 按照要求，取模         
        } 
        // 循环结束时，还剩下一段长度为 n 的绳子没有乘到 res 上，因此最后乘上
        res = (res * n) % mod; 

        return res; 
    }
};


// 无注释版本
class Solution {
public:
    int mod = 1e9 + 7;

    int cuttingRope(int n) {
        long long res = 1; 

        if (n == 2 || n == 3)  return n - 1;
        
        while (n > 4) {
            n = n - 3; 
            res = (res * 3) % mod;       
        } 

        res = (res * n) % mod; 

        return res; 
    }
};