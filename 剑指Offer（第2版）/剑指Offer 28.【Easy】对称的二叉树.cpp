
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// 递归
// 对称二叉树：递归定义

// 左孩子 = 有孩子
// 左孩子的左子树 = 右孩子的右子树
// 左孩子的右子树 = 右孩子的左子树

class Solution {
public:
    // dfs 函数: 判断二叉树 a，b 是否对称
    bool dfs(TreeNode* a, TreeNode* b) {
        // 递归出口：如果 a 和 b 同时遍历到了空节点，则是对称的
        if (a == nullptr && b == nullptr) return true;
        // 如果 a 先遍历到空节点 || b 先遍历到了空节点 || a 的节点值不等于 b 的节点值，则不是对称的
        if (a == nullptr || b == nullptr || a->val != b->val) return false;

        // 若 a, b 都不为空 && a 的根节点值等于 b 的根节点值
        // 则需要递归比较 b->right 与 a->left 以及 b->left 与 a->right
        return dfs(a->left, b->right) && dfs(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        // 特判：空树属于对称二叉树
        if (root == nullptr) return true;
        return dfs(root->left, root->right); // 检查左右子树
    }
};


// 无注释版本
class Solution {
public:
    bool dfs(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) return true;
        if (a == nullptr || b == nullptr || a->val != b->val) return false;
        return dfs(a->left, b->right) && dfs(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return dfs(root->left, root->right);
    }
};
