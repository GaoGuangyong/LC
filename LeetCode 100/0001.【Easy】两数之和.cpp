//               i  = {0, 1,  2,  3}
//          nums[i] = {2, 7, 11, 15}
// target - nums[i] = {7, 2, -2, -6}
//         hash.key = {7, 2, -2, -6}
//       hash.value = {0, 1,  2,  3} 
// 目标：返回 {hash[nums[i]], i}

// 写法一：
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash; // {target - nums[i], i}

        // 从头到尾遍历给定数组
        for (int i = 0; i < nums.size(); i ++ ) {
            if (hash.count(nums[i])) { // 如果当前元素在哈希表中存在，就意味着找到了，返回即可
                return {hash[nums[i]], i};
            }
            hash[target - nums[i]] = i; // 否则记录 target - nums[i] 的下标
        }

        return {}; // 返回一个空的数组
    }
};


// 无注释版本
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i ++ ) {
            if (hash.count(nums[i])) return {hash[nums[i]],  i};
            hash[target - nums[i]] = i;
        }
        
        return {};
    }
};


// 写法二：推荐
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash; // {nums[i], i}

        for (int i = 0; i < nums.size(); i ++ ) {
            if (hash.count(target - nums[i])) return {i, hash[target - nums[i]]};
            
            hash[nums[i]] = i;
        }

        return {};
    }
};
