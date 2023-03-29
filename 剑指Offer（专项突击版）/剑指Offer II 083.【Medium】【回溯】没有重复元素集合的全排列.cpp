// 排列问题，原数组没有重复元素
// 每一个位置可以放数组中的任意一个数, 所以指针 i 总是从 0 开始
// 另外需要一个 状态数组 辅助记录当前哪些数字已经用过了


// 不包含重复元素的全排列

class Solution {
public:
    int n;
    vector<int> path; // 当前方案
    vector<vector<int>> res; // 所有方案
    vector<bool> visit; // 标记数组，visit[i] = true 表示被使用了

    // 递归函数：从 nums 数组的下标 u 开始枚举每个位置填什么数
    void dfs(vector<int>& nums, int u) {
        // 递归出口：如果当前方案中的元素个数 等于 数组长度
        if (path.size() == n) {
            res.push_back(path);
            return;
        }
        // 对于当前下标 u，枚举每一个数字
        for (int i = 0; i < n; i ++ ) {
            if (visit[i] == false) { // 如果当前的数字 nums[i] 没有被用到过
                // 选择 nums[i]
                path.push_back(nums[i]);
                visit[i] = true; // 使用过了，置为 true
                // dfs
                dfs(nums, u + 1); // 0 也能过
                // 撤销选择
                visit[i] = false; // 当递归返回时就要将这个数字从标记数组中清除
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        visit.assign(n, false); // 将标记数组初始化成 n 个 false
        dfs(nums, 0); // 从 nums 数组的下标 0 开始枚举
        return res;
    }
};


// 无注释版本
class Solution {
public:
    int n;
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> visit;

    void dfs(vector<int> nums, int u) {
        if (path.size() == n) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < n; i ++ ) {
            if (visit[i] == false) {
                path.push_back(nums[i]);
                visit[i] = true;

                dfs(nums, u + 1);

                visit[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        visit.assign(n, false);

        dfs(nums, 0);
        return res;
    }
};


// 扩展：LC 47 全排列 II 
// 包含重复元素的全排列

class Solution {
public:
    int n;
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> visit;

    void dfs(vector<int>& nums, int u) {
        if (path.size() == n) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < n; i ++ ) {
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
        n = nums.size();
        visit.assign(n, false); 

        sort(nums.begin(), nums.end());

        dfs(nums, 0);
        return res;
    }
};


