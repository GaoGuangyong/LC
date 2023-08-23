
// 位运算
// 由于每个整数都是由 32 位二进制组成，同一个数出现三次，则二进制的第 i 位累加一定是 3 的倍数（0 也算 3 的倍数）
// 即除了只出现一次的数之外，所有数的二进制的第 i 位累加一定是 3 的倍数

// 将每一位相加的结果对 3 取余，再左移 i 位回去，即为答案的第 i 个二进制位
// 将 32 个二进制位相加后的结果就是 res

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0; // 只出现一次的数：初始时，res 的二进制表示的每一位都是 0
        int cnt = 0; // 用于累加 nums 数组中，所有数字的二进制表示的某一位中 1 的个数

        // 枚举 res 的二进制表示的每一位
        for (int i = 0; i < 32; i ++ ) {
            cnt = 0; // 清空 cnt

            // 枚举 nums 数组中的所有数字，求第 i 位的累加和 cnt
            for (int x: nums) {
                cnt += (x >> i & 1); // x >> i & 1 表示当前数字 x 的第 i 位的值（0 或 1） 
            }
            
            res += (cnt % 3) << i; // 将第 i 位的累加和 cnt 对 3 取余的结果通过左移 i 位的方法，放到 res 的第 i 位
        }

        return res;
    }
};

// 无注释版
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int cnt = 0;

        for (int i = 0; i < 32; i ++ ) {
            cnt = 0;
            for (int x: nums) {
                cnt += (x >> i & 1);
            }
            res += (cnt % 3) << i;
        }

        return res;
    }
};

