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
// 本题考查将二叉树转化成链表
// 方法：边中序遍历边构建链表：
// 中序遍历过程中要记录链表的尾节点，并将当前遍历的节点插到尾节点的右儿子上，并将尾节点更新成当前节点

class Solution {
public:
    // 全局变量
    TreeNode* tail; // 定义尾节点，实时指向新构造的链表的尾部

    // dfs 函数：中序遍历二叉树 root
    void dfs(TreeNode* root) {
        // 递归出口：如果当前遍历到的节点为空，则返回
        if (root == nullptr) return;
        // 左
        dfs(root->left);
        // 根
        tail->right = root; // 将当前节点插到尾节点的右面
        root->left = nullptr; // 将当前节点的左儿子置为空
        tail = root; // 将尾节点后移一位，指向当前节点
        // 右
        dfs(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        // 创建虚拟头节点，在初始时，尾节点指向虚拟头节点
        TreeNode* dummy = new TreeNode(-1);
        tail = dummy;

        dfs(root);
        return dummy->right;
   }
};


// 无注释版本
class Solution {
public:
    TreeNode* tail = new TreeNode(-1);

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        dfs(root->left);
        
        tail->right = root;
        root->left = nullptr;
        tail = root;
        
        dfs(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        tail = dummy;

        dfs(root);
        return dummy->right;
   }
};


