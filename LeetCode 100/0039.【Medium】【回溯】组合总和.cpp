

// 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。
// candidates 中的 同一个 数字可以 无限制重复被选取 


// 组合问题的要点：
// 每一个位置不能放已经放过的数字, 所以指针 i 从 u 开始枚举，dfs 时，下标为 i + 1（不可重复选择）或 i（可重复选择）
// 不需要状态数组


// 数组无重复元素 + 每个数字在每个组合中可以无限次使用

class Solution {
public:
    vector<int> path; // 当前方案
    vector<vector<int>> res; // 所有方案

    // DFS 函数：从 nums 数组的下标 u 开始查找和为 target 的元素
    void dfs(vector<int>& nums, int u, int target) {
        // 递归出口：
        // 如果 target 被减到了负数，则不是合法方案
        if (target < 0) return;
        // 如果 target 正好被减到了 0，则将当前方案加入结果数组中
        if (target == 0) {
            res.push_back(path);
            return;
        }

        // 从 u 开始枚举
        for (int i = u; i < nums.size(); i ++ ) {
            // 选择 nums[i]
            path.push_back(nums[i]);
            // dfs：因为数字可以重复选择，所以还是从 i 开始
            dfs(nums, i, target - nums[i]);
            // 撤销选择
            path.pop_back();
        }
    }

    // 主函数
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 从 candidates 数组的下标 0 开始查找和为 target 的元素
        dfs(candidates, 0, target);
        return res;
    }
};



// 扩展：LC 40 组合总和 II 
// 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用 一次 。


// 数组有重复元素 + 每个数字在每个组合中只能使用一次 

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int u, int target) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = u; i < nums.size(); i ++ ) {
            // 剪枝：如果是重复数字就跳过
            if (i > u && nums[i] == nums[i - 1]) continue;

            // 选择
            path.push_back(nums[i]);
            // dfs：因为数字不可以重复选择，所以从 i + 1 开始
            dfs(nums, i + 1, target - nums[i]); 
            // 撤销选择
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 先对原数组进行升序排序
        sort(candidates.begin(), candidates.end());

        dfs(candidates, 0, target);
        return res;
    }
};

