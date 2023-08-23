// 排列问题，原数组有重复元素
// 每一个位置可以放数组中的任意一个数, 所以指针 i 总是从 0 开始
// 另外需要一个 状态数组 辅助记录当前哪些数字已经用过了

// 因为有重复数字，那么关键就是要让这些重复数字的相对位置不改变，即对于重复数字，每次都选取第一个没被用过的那一个
// 如果 nums[i] == nums[i - 1] 那么 nums[i] 就是重复数字
// 如果此时 num[i - 1] 又恰好没被用过，那么 nums[i] 就不第一个没有被用过的重复数字，跳过

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


// 二刷
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> visit;

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i ++ ) {
            if (i > 0 && nums[i] == nums[i - 1] && visit[i - 1] == false) continue;
            
            if (visit[i] == false) {
                path.push_back(nums[i]);
                visit[i] = true;

                dfs(nums, u + 1);

                visit[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visit.assign(nums.size(), false);
        sort(nums.begin(), nums.end());

        dfs(nums, 0);
        return res;
    }
};
