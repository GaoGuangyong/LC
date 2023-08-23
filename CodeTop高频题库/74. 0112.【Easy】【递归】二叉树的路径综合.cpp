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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 特判：若为空树，则无法得到和为 targetSum 的路径
        if (root == nullptr) return false;
        targetSum -= root->val; // 反向减掉当前的值
        // 如果到了叶节点，判断一下当前的 targetSum 是不是减到了 0
        if (root->left == nullptr && root->right == nullptr)
            return targetSum == 0;

        bool l = hasPathSum(root->left, targetSum); // 递归判断左子树
        bool r = hasPathSum(root->right, targetSum); // 递归判断右子树

        return (root->left != nullptr && l == true) || (root->right != nullptr && r == true);
    }
};

