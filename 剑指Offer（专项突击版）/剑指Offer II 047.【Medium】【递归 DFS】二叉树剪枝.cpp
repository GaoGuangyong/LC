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

// DFS

class Solution {
public:
    // dfs 函数：判断以 root 为根的这棵子树是否含有 1 节点（true 表示含有 1，false 表示不含 1），如果不含 1，则删掉该二叉树
    bool dfs(TreeNode* root) {
        // 递归出口，如果当前节点为空，则肯定不含 1，返回 false
        if (root == nullptr) return false;

        // 递归左右子树
        // 如果左子树不含 1，则左子树置为空
        if (dfs(root->left) == false) root->left = nullptr;
        // 如果右子树不含 1，则右子树置为空
        if (dfs(root->right) == false) root->right = nullptr;
            
        // 若当前节点为 1 或 左右子树之一不为空（说明左右子树之一包含 1），则当前二叉树包含 1，返回 true
        if (root->val == 1 || root->left != nullptr || root->right != nullptr) return true;
        // 否则返回 false
        else return false;
    }

    TreeNode* pruneTree(TreeNode* root) {
        // 如果以根节点开始的整个树都没有 1，则把整个树删掉
        if (dfs(root) == false) root = nullptr;
        return root;
    }
};


// 无注释版本
class Solution {
public:
    bool dfs(TreeNode* root) {
        if (root == nullptr) return false;

        if (dfs(root->left) == false) root->left = nullptr;
        if (dfs(root->right) == false) root->right = nullptr;

        if (root->val == 1 || root->left != nullptr || root->right != nullptr) return true;
        else return false;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (dfs(root) == false) root = nullptr;
        return root;
    }
};