/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 树形 DP
// 设某个子树如下
//     u
//    / \
//   l   r

// 设 f 是个长度为 2 的数组

// f[0] 表示以 u 为根，不偷 u，最多能偷窃的金额，此时 l 和 r 都可以选择 偷 / 不偷
// f[0] = max(l[0], l[1]) + max(r[0], r[1])

// f[1] 表示以 u 为根，偷 u，最多能偷窃的金额，此时 l 和 r 都不能偷
// f[1] = l[0] + r[0] + u->value;

// 答案：max(f[0], f[1])

class Solution {
public:
    // DFS 函数返回值类型为 vector<int>, 返回 {f0, f1}
    vector<int> dfs(TreeNode* u) {
        if (u == nullptr) return {0, 0}; // 递归出口
        // 递归遍历左右子树
        vector<int> l = dfs(u->left);
        vector<int> r = dfs(u->right);

        int f0 = max(l[0], l[1]) + max(r[0], r[1]); // 求不偷 u 时能偷的最大值
        int f1 = l[0] + r[0] + u->val; // 求偷 u 时能偷的最大值

        return {f0, f1}; // 返回长度为 2 的数组 {不偷 u, 偷 u}
    }

    int rob(TreeNode* root) {
        vector<int> f = dfs(root);
        return max(f[0], f[1]);
    }
};

// 无注释版本
class Solution {
public:
    vector<int> dfs(TreeNode* u) {
        if (u == nullptr) return {0, 0};
        vector<int> l = dfs(u->left);
        vector<int> r = dfs(u->right);

        int f0 = max(l[0], l[1]) + max(r[0], r[1]);
        int f1 = l[0] + r[0] + u->val;

        return {f0, f1};
    }

    int rob(TreeNode* root) {
        vector<int> f = dfs(root);
        return max(f[0], f[1]);
    }
};

