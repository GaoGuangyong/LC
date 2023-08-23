// 模拟
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // k 表示当前要确定的元素的下标，从数组的首位开始确定
        int k = 0;

        // 遍历数组，把非 0 的数字放到数组的前面
        for (int x: nums) {
            // 如果当前数字不是0
            if (x != 0) {
                nums[k] = x; // 把当前的非 0 数字放到 k 的位置
                k ++; // k 后移一位
            }
        } // 循环结束时，k 指向数组中最后一个非 0 数字的下一位

        // 把 k ~ nums.size() 的位置补上 0
        while (k < nums.size()) {
            nums[k] = 0;
            k ++;
        }
    }
};

// 无注释版本
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;

        for (int x: nums) {
            if (x != 0) {
                nums[k] = x;
                k ++ ;
            }
        }

        while (k < nums.size()) {
            nums[k] = 0;
            k ++ ;
        }
    }
};


// 二刷
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int x: nums) {
            if (x != 0) nums[k ++ ] = x;
        }

        while (k < nums.size()) nums[k ++ ] = 0;
    }
};