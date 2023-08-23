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

class Solution {
public:
    vector<int> res; // 结果数组

    void dfs(TreeNode* root){
        // 递归出口
        if(root == nullptr) return; // 若遍历到了空节点，则返回
        // 访问自己
        res.push_back(root->val);
        // 访问左子树
        dfs(root->left);
        // 访问右子树
        dfs(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};
