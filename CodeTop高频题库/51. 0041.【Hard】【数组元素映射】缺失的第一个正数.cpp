

// 答案一定在 [1, n + 1] 当且仅当 nums 里包括 1 ~ n 才能取到最大值 n + 1，否则一定会出现 1 ~ n 的空隙，而使得答案在 [1, n]
// 所以答案只和值为 1 ~ n 的元素有关，其他元素包括重复的元素都可以不管
// 所以我们可以把值为 i 的元素交换到 nums[i]，如果第 i 个元素 nums[i] 不是 i，说明没有 i 这个元素，则答案是 i


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0); // 在原数组的开头插入一个 0，把原数组中的所有元素向后移动 1 位

        // 从下标 1 开始预处理 nums 数组
        for (int i = 1; i <= n; i ++ ) {
            // 当 nums[i] 属于 [1 ~ n] 且 不在正确的位置上 且 要交换的两个数字不同
            while(nums[i] > 0 && nums[i] <= n && nums[i] != i && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }

        for (int i = 1; i <= n; i ++ ) {
            if (nums[i] != i) return i;
        }

        // 否则。答案为 n + 1
        return n + 1;
    }
};

