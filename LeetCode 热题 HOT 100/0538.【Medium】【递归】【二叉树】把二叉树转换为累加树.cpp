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

// 递归
// 反中序遍历
// 由于二叉搜索树的中序遍历是从小到大
// 而累加树要求 当前节点的新值 = 大于或等于当前节点的所有节点值之和。故对于每个节点可以先遍历其右子树，再遍历其节点，最后遍历其左子树。

class Solution {
public:
    int sum = 0; // 结果：大于等于 某节点值的所有数的和

    // 递归函数：反中序遍历，遍历过程中更新每个节点的新值
    void dfs(TreeNode* root) {
        // 递归出口：若当前遍历到了空节点，则遍历结束，直接返回
        if (root == nullptr) return;
        // 右
        dfs(root->right);
        // 根
        sum += root->val; // 将遍历完右子树后的和 sum + 当前节点的值
        root->val = sum; // 将 root 值更新为 sum
        // 左
        dfs(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};

// 无注释版
class Solution {
public:
    int sum = 0;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        
        dfs(root->right);
        
        sum += root->val;
        root->val = sum;
        
        dfs(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};
