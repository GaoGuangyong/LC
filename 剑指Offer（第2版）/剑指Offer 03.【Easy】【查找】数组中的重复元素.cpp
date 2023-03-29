// 解法一：计数法 时间复杂度o(n)
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i: nums) {
            m[i] ++ ;
            if (m[i] > 1) //若果m[i]>0，就代表是重复的数字，输出即可
                return i;
        }
        return -1; //若没找到，则返回-1，但本题是一定能找到
    }
};

// 解法二：排序法
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // 扫描去重
        for (int i = 0; i < nums.size(); i ++ ) {
            if (i > 0 && nums[i] == nums[i - 1])
                return nums[i];
        }
        return -1;
    }
};


// 解法三：交换法，鸽巢原理（推荐）
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 从前往后遍历字符串，将 nums[i] 交换到 nums[nums[i]]
        for (int i = 0; i < nums.size(); i ++ ) {
            if (nums[i] == i) continue; // 若 nums[i] == i，说明 nums[i] 已经在正确的位置上了，跳过
            // 否则应该把 nums[i] 交换到正确的位置上，即 nums[nums[i]]
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) return nums[i]; // 如果要交换的两个数相等，那么 nums[i] 就出现了重复，返回即可
                else swap(nums[i], nums[nums[i]]); // 如果要交换的两个数不相等，则把 nums[i] 交换到正确的位置上即可
            }
        }
        return -1;
    }
};

// 无注释版本
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++ ) {
            if (nums[i] == i) continue;
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) return nums[i];
                else swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};