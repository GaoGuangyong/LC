/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 同面试题 04.06.
// 利用二叉搜索树的性质
// 二叉搜索树的一个性质是中序遍历序列单调递增，因此二叉搜索树中的节点 p 的中序后继满足条件：
// 中序后继是节点值大于 p 的节点值的所有节点中节点值最小的一个节点

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr; // 定义后继指针，初始化为空指针，最终返回这个指针

        //【1】如果 p 节点有右儿子，则从 p 节点右儿子开始一路向左，最左边的那个节点就是 p 节点的后继
        if (p->right != nullptr) {
            successor = p->right; // 先将后继指针指向 p 的右儿子
            while (successor->left != nullptr) { // 当 p 的右儿子有左儿子，就一路向左
                successor = successor->left;
            } 
            return successor;
        }

        //【2】如果节点 p 没有右儿子，则需要从根节点开始遍历寻找节点 p 的父节点
        TreeNode* node = root; // 用 node 表示遍历到的节点，初始时 node = root

        // 只要没变量到空节点，就循环遍历
        while (node != nullptr) {
            // 如果 node > p，则 p 的后继节点可能是 node 或者在 node 的左子树中
            if (node->val > p->val) {
                successor = node; // node 可能是后继节点
                node = node->left; // 将 node 移动到其左子节点继续遍历
            }
            // 如果 node < p 的节点值，则 p 的后继节点可能在 node 的右子树中
            else if (node->val < p->val) {
                node = node->right; // 将 node 移动到其右子节点继续遍历
            }
            // 如果 node == p，则此时，successor 指向的就是 p 的父节点，也就是其后继
            else break;
        } // 循环结束后，successor 指向的就是 p 的后继

        return successor;
    }
};



// 无注释版本
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;

        if (p->right != nullptr) {
            successor = p->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            } 
            return successor;
        }

        TreeNode* node = root;

        while (node != nullptr) {
            if (node->val > p->val) {
                successor = node; 
                node = node->left;
            }
            else if (node->val < p->val) {
                node = node->right; 
            }
            else if (node->val == p->val) break;
        } 

        return successor;
    }
};


