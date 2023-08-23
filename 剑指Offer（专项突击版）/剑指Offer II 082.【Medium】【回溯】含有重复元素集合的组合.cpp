// https://www.acwing.com/solution/content/15009/

// 组合问题，不允许重复，原数组没有重复数字
// 排序 + DFS

class Solution {
public:
    vector<int> path; // 当前方案
    vector<vector<int>> res; // 所有方案

    // 递归函数：从 nums 数组的下标 u 开始查找和为 target 的元素
    void dfs(vector<int>& nums, int u, int target) {
        // 递归出口：如果 target 被减到了负数，则不是合法方案
        if (target < 0) return;
        // 如果 target 正好被减到了 0，则将当前方案加入结果数组中
        if (target == 0) {
            res.push_back(path);
            return;
        }

        // 从 u 枚举到 nums.size() - 1
        for (int i = u; i < nums.size(); i ++ ) {
            // 剪枝逻辑：遍历过的数就跳过
            if (i > u && nums[i] == nums[i - 1]) continue;
            // 选择 nums[i]
            path.push_back(nums[i]); // 将当前元素加入路径数组中
            // dfs
            dfs(nums, i + 1, target - nums[i]); // 因为数字不可以重复选择，所以从 i + 1 开始
            // 撤销选择
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 先对原数组进行升序排序
        sort(candidates.begin(), candidates.end());

        // 从 candidates 数组的下标 0 开始查找和为 target 的元素
        dfs(candidates, 0, target);
        return res;
    }
};


// 二刷
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int>& candidates, int u, int target) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = u; i < candidates.size(); i ++ ) {
            if (i > u && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};

