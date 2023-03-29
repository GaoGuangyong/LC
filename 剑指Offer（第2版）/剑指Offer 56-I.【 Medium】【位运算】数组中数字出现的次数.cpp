

// 位运算

// 异或：相同为 0，不同为 1
// 异或的重要性质：相同的两个数异或会被消去:
// 设两个只出现一次的数时 x 和 y，则 x^y^z^z^u^u^w^w = x ^ y

// 设 2 个只出现一次的数字是 x 和 y
// x 和 y 的二进制表示中，一定有一个的第 k 位是 0 而另一个的第 k 位是 1（即 x ^ y 的二进制表示，一定有一位是 1）
// 根据 nums 中的数字的二进制表示的第 k 位是 0 还是 1，将所有数分成两个集合 first 和 second
// 分别将这两个集合里的数全部异或起来，即可得到 x 和 y

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 将所有的数异或起来，得到结果 sum = x ^ y
        int sum = 0; 
        for (int i: nums) sum ^= i;

        int k = 0; // 设 x ^ y 的二进制表示中，第一个值为 1 的那一位是第 k 位

        // 找到 x ^ y 的二进制表示中第一个为 1 的位置（即第一个 x 和 y 不同的位置）
        while ((sum >> k & 1) == 0) k ++ ; // 等价于 while ((sum & (1 << k)) == 0) k ++ ; 

        int first = 0; // first 用于保存第一个集合中所有数字的异或结果
        int second = 0; // second 用于保存第二个集合中所有数字的异或结果

        // 遍历 nums 数组中的数，如果第 k 位是 1，则与 first 异或
        for (int x: nums) {
            // 如果第 k 位是 1，则与 first 异或
            if ((x >> k & 1) == 1) first ^= x;
            // 如果第 k 位是 0，则与 second 异或
            else second ^= x;
        } // 异或完之后，first = x，second = y

        return {first, second};
    }
};


// 无注释版本
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0; 
        for (int i: nums) sum ^= i;

        int k = 0;

        while ((sum >> k & 1) == 0) k ++ ;

        int first = 0;
        int second = 0;

        for (int x: nums) {
            if ((x >> k & 1) == 1) first ^= x;
            else second ^= x;
        }

        return {first, second};
    }
};

