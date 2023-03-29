
// 位运算

// 左移 << 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;

        // 遍历 n 的二进制表示的每一位
        for (int i = 0; i < 32; i ++ ) {
            if ((n & (1 << i)) != 0) // 如果 n 的二进制表示的 i 位是 1，则计数 + 1
                res ++ ;
        }
        return res;
    }
}; 

// 右移 >>
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;

        // 遍历 n 的二进制表示的每一位
        for (int i = 0; i < 32; i ++ ) {
            if ((n >> i & 1) == 1) // 如果 n 的二进制表示的 i 位是 1，则计数 + 1
                res ++ ;
        }
        return res;
    }
}; 



