
// 考察异或运算 ^ 的性质
// 将数组中的所有数字异或起来，最终出现偶数次的数字会消去，剩下只出现 1 次的数

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto x: nums) {
            res ^= x; 
        }
        return res;
    }
};


