
// 哈希表 + 枚举
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 定义一个哈希集合：记录出现过的数字
        unordered_set<int> S; 

        // 遍历数组中的数
        for (int x: nums) {
            // 判断：如果 target - x 出现过，就找到了，输出即可
            if (S.count(target - x)) return {target - x, x};

            // 前数字加入哈希集合，代表已经出现过了
            S.insert(x); 
        }

        // 如果无解，返回空数组
        return {}; // 并不会执行
    }
};


// 无注释版本
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> S; 

        for (int x: nums) {
            if (S.count(target - x)) return {target - x, x};

            S.insert(x); 
        }

        return {};
    }
};

