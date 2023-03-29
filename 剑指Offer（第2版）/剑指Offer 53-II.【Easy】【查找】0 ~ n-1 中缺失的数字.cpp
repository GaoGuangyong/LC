// 查找
// 等差数列求和法

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 先求数组的总和
       int sum = 0; // 表示 nums 数组的和
       for (int x : nums) sum += x;

       int n = nums.size();

       // 则不缺数字的连续递增数组为等差数列 [0, 1, 2 ... n]
       int acc_sum = (0 + n) * (n + 1) / 2; // 等差数列求和

       return acc_sum - sum;
    }
};



// 写法二：
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 先求数组的总和
       int sum = accumulate(nums.begin(), nums.end(), 0);

       int n = nums.size();

       // 则不缺数字的连续递增数组为等差数列 [0, 1, 2 ... n]
       int acc_sum = (0 + n) * (n + 1) / 2; // 等差数列求和

       return acc_sum - sum;
    }
};
