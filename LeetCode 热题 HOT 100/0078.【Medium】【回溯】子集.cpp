// 递归，递归树见笔记
// 设数组 nums =  [1, 2, 3, 4]
// 子集 s = []
// 对于数组 nums 中的每个元素，都有选入子集和不选入子集两种状态


// 组合问题，不包含重复元素
class Solution {
public:
    // 全局变量
    vector<int> path; // 当前方案
    vector<vector<int>> res; // 所有方案

    // dfs 函数：对数组 nums 进行递归遍历，起点下标是 u
    void dfs(vector<int>& nums, int u) {
        res.push_back(path);  // 将上一轮的子集存到 res 中

        for (int i = u; i < nums.size(); i ++ ) {
            // 选择 nums[i]
            path.push_back(nums[i]);
            // dfs
            dfs(nums, i + 1);
            // 撤销选择
            path.pop_back();
        } // 循环结束后，path 存的就是一种子集方案
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0); // 从 nums 数组的下标 0 开始递归
        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int u) {
        res.push_back(path);

        for (int i = u; i < nums.size(); i ++ ) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};



// 扩展：LC 90 子集 II
// 组合问题，不包含重复元素 -> 排序 + 减枝

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int u) {
        res.push_back(path);

        for (int i = u; i < nums.size(); i ++ ) {
            if (i > u && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        dfs(nums, 0);
        return res;
    }
};

