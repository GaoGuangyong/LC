
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

// 解法一：非原地算法：递归

class Solution {
public:
    void flatten(TreeNode* root) {
        // 递归出口：如果遍历到了空节点，则返回
        if (root == nullptr) return; 

        // 先递归展平左右子树
        flatten(root->left);
        flatten(root->right);

        // 此时左右子树已经被展平成一条链表

        TreeNode* l = root->left; // 用指针 l 保存下展平后的左子树的根节点
        TreeNode* r = root->right; // 用指针 r 保存下展平后的右子树的根节点

        // 1、将展平后的原左子树接到根节点右边
        root->left = nullptr; // 将根节点的左子树删掉
        root->right = l; // 将根节点的右指针指向展平后的原左子树

        // 2、找到展平后的原左子树的最后一个节点，然后将展平后的原右子树接到其右边
        TreeNode* p = root; // 用一个指针 p 保存树的根节点
        while (p->right != nullptr) p = p->right; // p 从根节点开始，一路向右走，直到展平后的原左子树的最后一个节点
        
        p->right = r; // 将展平后的原右子树接到展平后的左子树的末尾
    }
};

// 无注释版本
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        flatten(root->left);
        flatten(root->right);

        auto l = root->left;
        auto r = root->right;

        root->left = nullptr;
        root->right = l;

        auto p = root;
        while (p->right != nullptr) p = p->right;

        p->right = r;
    }
};

