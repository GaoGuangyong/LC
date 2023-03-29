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

// 1、若 p 和 q 都小于 root，则说明 p，q 都在 root 左侧，LCA 在 root 的左子树上，故递归搜索 root->left
// 2、若 p 和 q 都大于 root，则说明 p，q 都在 root 右侧，LCA 在 root 的右子树上，故递归搜索 root->right
// 3、若 p 和 q 分别在 root 两侧，则最近公共祖先为 root
// 4、若 p = root 或 q = root，则最近公共祖先为 root

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 情况 1
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        // 情况 2
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        // 剩下的情况 3 和 4 都是返回 root
        return root;
    }
};


// 无注释版本
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};


