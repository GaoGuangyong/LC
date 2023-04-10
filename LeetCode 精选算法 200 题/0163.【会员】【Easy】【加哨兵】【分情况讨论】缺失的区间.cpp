
// 预处理 + 分情况模拟
// 预处理：将 lower - 1  和 upper + 1 插入到数组两侧

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        nums.insert(nums.begin(), lower - 1);
        nums.insert(nums.end(), upper + 1); // nums.push_back(upper + 1);

        vector<string> res;
        for (int i = 1; i < nums.size(); i ++ ) {
            if (nums[i] - nums[i - 1] == 1) 
                continue;
            else if (nums[i] - nums[i - 1] == 2) 
                res.push_back(to_string(nums[i] - 1));
            else if (nums[i] - nums[i - 1] > 2) 
                res.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
        }
        return res;
    }
};


