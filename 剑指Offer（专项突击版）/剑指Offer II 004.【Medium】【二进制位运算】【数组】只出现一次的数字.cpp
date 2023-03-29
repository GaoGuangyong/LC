
// 位运算
// 由于每个整数都是由 32 位二进制组成，同一个数出现三次，则第 i 位二进制 1 或 0 累加一定是 3 的倍数（0 也算 3 的倍数）
// 即除了只出现一次的数之外，所有数的第 i 位的二进制的 1 或 0 的个数一定是 3 的倍数

// 将每一位相加的结果对 3 取余，再左移 i 位回去，即为答案的第 i 个二进制位

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0; // 答案（只出现一次的数）：初始时，res 的二进制表示的每一位都是 0
        int cnt = 0; // 用于累加 nums 数组中，所有数字的二进制表示的某一位

        // 枚举二进制的每一位
        for (int i = 0; i < 32; i ++ ) {
            cnt = 0; 
            // 枚举 nums 数组中的所有数字
            for (auto x : nums) {
                cnt += x >> i & 1; // 将当前数字的第 i 位累加到 cnt 
            }
            
            res += (cnt % 3) << i; // 将答案的二进制表示的 第 i 位对 3 取余的结果放回原来的位置（左移 i 位）
        }
        return res;
    }
};

// 无注释版
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < 32; i ++ ) {
            int cnt = 0;
            for (int x: nums) {
                cnt += x >> i & 1;    
            }
            res += (cnt % 3) << i;
        }

        return res;       
    }
};

