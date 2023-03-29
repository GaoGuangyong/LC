
// 怎么样才能组成一个顺子
// 1. 除 0 以外，不能有两个相同的牌
// 2. 除 0 以外，最大值 - 最小值 <= 4，则一定可以使用 0 进行补位，形成顺子

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        // 先对原数组进行排序，则 0 都会排在前面
        sort(nums.begin(), nums.end()); 

        // 找到第一个非 0 的数 nums[k]
        int k = 0;
        while (nums[k] == 0) k ++ ; 

        // 从第二个非 0 的数开始遍历，不能有两个相同的牌
        for (int i = k + 1; i < nums.size(); i ++ ) {
            if (nums[i] == nums[i - 1]) return false;
        }

        // 如果除 0 以外，最大值 - 最小值  <= 4，则可以成为顺子
        if (nums.back() - nums[k] <= 4) return true;

        // 否则，不可以成为顺子
        return false;
    }
};


// 无注释版本
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 

        int k = 0;
        while (nums[k] == 0) k ++ ; 

        for (int i = k + 1; i < nums.size(); i ++ ) {
            if (nums[i] == nums[i - 1]) return false;
        }

        if (nums.back() - nums[k] <= 4) return true;

        return false;
    }
};

