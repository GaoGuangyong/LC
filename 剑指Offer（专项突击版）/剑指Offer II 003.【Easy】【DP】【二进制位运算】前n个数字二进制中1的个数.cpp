// DP
// 状态： f[i] 表示 i 的二进制表示中 1 的个数
// 状态转移：f[i] 可以由 f[i / 2] 转移过来（注：i / 2 等价于 i >> 1）

// i 的二进制表示和 i 右移一位的二进制表示除了最后一位都一样
// 所以先求出 f[i >> 1]，再判断个位是 0 是 1，即 f[i] = f[i >> 1] + (i & 1)

// 举例说明：
//      i = 110101101，
// i >> 1 =  11010110 (去掉个位)

// i & 1  =
//          110101101
//       &  000000001
//        =         1（个位数是 1 就得 1，个位数是 0 就得 0）

class Solution {
public:
    vector<int> countBits(int n) {
        // 定义状态数组：
        vector<int> f(n + 1);
        // 初始化：
        f[0] = 0; // 0 的二进制表示中没有 1
        // 状态转移：
        for (int i = 1; i <= n; i ++ ) 
            f[i] = f[i >> 1] + (i & 1);

        return f;
    }
};


// 无注释版
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> f(n + 1);

        f[0] = 0;

        for (int i = 1; i <= n; i ++ ) {
            f[i] = f[i >> 1] + (i & 1);
        }
        
        return f;
    }
};

