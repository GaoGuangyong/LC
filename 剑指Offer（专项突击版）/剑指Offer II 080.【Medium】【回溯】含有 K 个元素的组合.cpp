// 组合问题

class Solution {
public:
    vector<int> path; // 当前方案
    vector<vector<int>> res; // 所有方案

    // dfs 函数：返回 u ... n 中所有可能的 k 个数的组合
    void dfs(int u, int n, int k) {
        // 递归出口：若已经枚举了 k 个数，则将当前方案插入结果中
        if (k == path.size()) {
            res.push_back(path);
            return;
        }

        // 从 u 枚举到 n
        for (int i = u; i <= n; i ++ ) {
            // 选择 i
            path.push_back(i);
            // dfs
            dfs(i + 1, n, k);
            // 撤销选择
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k); // 返回 1 ... n 中所有可能的 k 个数的组合
        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(int u, int n, int k) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        
        for (int i = u; i <= n; i ++ ) {
            path.push_back(i);
            dfs(i + 1, n, k);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
};