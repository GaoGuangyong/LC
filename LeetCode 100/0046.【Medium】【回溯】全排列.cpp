
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。


// 排列问题的要点：
// 每一个位置可以放数组中的任意一个数, 所以指针 i 从 0 开始枚举，dfs 时，下标为 u + 1（不可重复选择）或 u（可重复选择）
// 另外需要一个 状态数组 辅助记录当前哪些数字已经用过了


// 不包含重复元素的 排列 问题
class Solution {
public:
    vector<int> path; // 当前方案
    vector<vector<int>> res; // 所有方案
    vector<bool> visit; // 标记数组，visit[i] = true 表示被使用了

    // DFS 函数：从 nums 数组的下标 u 开始枚举每个位置填什么数
    void dfs(vector<int>& nums, int u) {
        // 递归出口：如果 当前枚举的下标 == 数组长度
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        // 从 0 开始枚举
        for (int i = 0; i < nums.size(); i ++ ) {
            if (visit[i] == false) { // 如果当前的数字 nums[i] 没有被用到过
                // 选择 nums[i]
                path.push_back(nums[i]);
                visit[i] = true; // 使用过了，置为 true
                // dfs
                dfs(nums, u + 1);
                // 撤销选择
                visit[i] = false; // 当递归返回时就要将这个数字从标记数组中清除
                path.pop_back();
            }
        }
    }
    
    // 主函数
    vector<vector<int>> permute(vector<int>& nums) {
        visit.assign(nums.size(), false); // 将标记数组初始化成 n 个 false

        dfs(nums, 0); // 从 nums 数组的下标 0 开始枚举

        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> visit;

    void dfs(vector<int> nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++ ) {
            if (visit[i] == false) {
                visit[i] = true;
                path.push_back(nums[i]);
                dfs(nums, u + 1);
                path.pop_back();
                visit[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        visit.assign(nums.size(), false);
        dfs(nums, 0);
        return res;
    }
};



// 扩展：LC 47 全排列 II 
// 包含重复元素的 排列 问题 -> 需要 排序 + 减枝

class Solution {
public:
    vector<int> path; // 当前方案
    vector<vector<int>> res; // 所有方案
    vector<bool> visit; // 标记数组

    // 递归函数：从 nums 数组的下标 u 开始枚举每个位置填什么数
    void dfs(vector<int>& nums, int u) {
        // 递归出口：如果当前方案中的元素个数 等于 数组长度
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // 否则，从 0 开始枚举每一个位置
        for (int i = 0; i < nums.size(); i ++ ) {
            // 减枝：如果 nums[i] 是重复数字，且 nums[i - 1] 没被用过，则跳过
            if (i > 0 && nums[i] == nums[i - 1] && visit[i - 1] == false) continue;

            // 如果当前的数字 nums[i] 没有被用到过
            if (visit[i] == false) { 
                // 选择 nums[i]
                path.push_back(nums[i]);
                visit[i] = true; // 使用过了，置为 true
                // dfs
                dfs(nums, u + 1); // 枚举下标 + 1
                // 撤销选择
                visit[i] = false; // 当递归返回时就要将这个数字从标记数组中清除
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visit.assign(nums.size(), false); // 将标记数组初始化成 n 个 false

        sort(nums.begin(), nums.end()); // 先对原数组进行升序排序

        dfs(nums, 0); // 从 nums 数组的下标 0 开始枚举
        return res;
    }
};


