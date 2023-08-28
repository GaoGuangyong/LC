/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS
// 思路 ：将上一题 (Offer 55-I) 的函数作为辅助函数，利用平衡二叉树的递归定义

class Solution {
public:
    // 递归函数：求树的深度
    int height(TreeNode* root) {
        // 递归出口：当遍历到空节点时，遍历结束，返回深度 0
        if (root == nullptr) return 0;
        // 否则，深度 = 左右子树深度的最大值 + 1
        return max(height(root->left), height(root->right)) + 1;
    }

    // 主函数
    bool isBalanced(TreeNode* root) {
        // 特判：空树也是平衡二叉树
        if (root == nullptr) return true; 

        // 否则，判断平衡二叉树的条件：左右子树的深度差 <= 1 && 左子树是平衡二叉树 && 右子树是平衡二叉树
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
       
    }
};



// 无注释版本
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        
        return max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true; 

        return (abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
       
    }
};



