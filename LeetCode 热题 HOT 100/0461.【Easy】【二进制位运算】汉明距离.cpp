
// 解法一
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x != 0 || y != 0) { // 当 x 或 y 不为 0 的时候
            // 分别取出 x 的个位和 y 的个位，将二者异或（相同为0，不同为1），如果二者不同，则计数 + 1
            res += (x & 1) ^ (y & 1); 

            // 将 x 和 y 都右移一位
            x >>= 1;  
            y >>= 1;
        }
        return res;
    }
};

// 解法一无注释版本
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;

        while (x != 0 || y != 0) {
            res += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
        }

        return res;
    }
};


// 解法二（推荐）
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        // 遍历 x 和 y 的二进制表示的每一位
        for (int i = 0; i < 32; i ++ ) {
            // 如果 x 的二进制表示的第 i 位 和 y 的二进制表示的第 i 位 不相等
            if ((x >> i & 1) != (y >> i & 1)) 
                res ++ ;
        }

        return res;
    }
};

// 解法二无注释版本
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;

        for (int i = 0; i < 32; i ++ ) {
            if ((x >> i & 1) != (y >> i & 1)) 
                res ++ ;
        }

        return res;
    }
};

