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

// 二叉树枚举路径的问题：往往都是枚举最高点，这个最高点被称作 LCA (最近公共祖先)
// 对于每个节点，都求一下向左走最远能走多少 && 向右走最远能走多少，再将二者相加

class Solution {
public:
    int res = INT_MIN; // 因为是求路径的最大值，所以初始化成负无穷

    // 递归函数：返回以 root 节点为起点，向下的最大路径和
    int dfs(TreeNode* root) {
        // 递归出口：如果当前遍历到了空节点，则最大路径和为 0
        if (root == nullptr) return 0;

        // 分别求出以当前节点的左，右儿子为起点，向下的最大路径和 l，r
        int l = max(0, dfs(root->left)); // 如果路径和为负数，则 l = 0
        int r = max(0, dfs(root->right)); // 如果路径和为负数，则 r = 0

        // 更新以 root 为根的最大路径和：root 的节点值 + 左子树的最大路径和 + 右子树的最大路径和
        res = max(res, root->val + l + r);

        // 返回以 root 节点为起点，向下的最大路径和
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};


// 无注释版本

class Solution {
public:
    int res = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int l = max(0, dfs(root->left));
        int r = max(0, dfs(root->right));

        res = max(res, root->val + l + r);
        
        return root-> val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};

