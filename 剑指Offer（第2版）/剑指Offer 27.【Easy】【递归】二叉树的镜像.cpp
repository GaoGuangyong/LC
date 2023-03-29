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


// 递归：从根节点开始，不断交换当前遍历节点的左右儿子

class Solution {
public:
    // 递归函数：给定二叉树 root，返回其镜像二叉树
    TreeNode* mirrorTree(TreeNode* root) {
        // 递归出口：如果遍历到了空节点，则返回空节点
        if (root == nullptr) return nullptr;

        // 交换指向左右儿子的指针
        swap(root->left, root->right); // 注意：swap 可以交换两个指针

        // 递归处理左右子树
        mirrorTree(root->left);
        mirrorTree(root->right);

        // 最后返回根节点，因为镜像之后根节点并没有变
        return root;
    }
};

// 无注释版本
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        swap(root->left, root->right);
        
        mirrorTree(root->left);
        mirrorTree(root->right);
        
        return root;
    }
};

