
// 枚举
// 除了一个数外，其他每个数出现 3 次，则排序之后，出现 1 次的数字的下标有三种情况：
// 第一种：出现在前面 {3，4，4，4，5，5，5}
// 第二种：出现在中间 {3，3，3，4，5，5，5}
// 第三种：出现在最后 {3，3，3，4，4，4，5}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end()); // 先对数组进行排序

        if (n == 1) return nums[0]; // 特判：如果只有一个数，直接返回这个数

        // 如果超过 1 个数，则遍历 nums[0, 3, 6, 9 ... ]
        for (int i = 0; i < n; i += 3) {
            // 如果遍历到了最后一位，说明答案是最后一个数，返回最后一个数
            if (i == n - 1) return nums[n - 1];

            // 如果当前遍历的数是连续三个相同的数的起点，则跳过这三个数
            if (nums[i] == nums[i + 2]) continue; 
            
            // 否则，如果当前遍历的数不是三个相同的数的起点，则这个数就是答案
            else return nums[i];
        }

        return -1;
    }
};


// 无注释版本
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end()); 

        if (n == 1) return nums[0]; 

        for (int i = 0; i < n; i += 3) {
            if (i == n - 1) return nums[n - 1];

            if (nums[i] == nums[i + 2]) continue; 
            
            else return nums[i];
        }

        return -1;
    }
};

