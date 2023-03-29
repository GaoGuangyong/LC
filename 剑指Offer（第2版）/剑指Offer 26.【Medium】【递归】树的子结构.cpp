/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // 辅助函数：判断二叉树 B 是不是二叉树 A 的子树
    bool isSame(TreeNode* A, TreeNode* B) {
        // 递归出口：
        // 如果 B 先遍历到了空节点，则说明 A 能完全匹配 B，返回 true
        if (B == nullptr) return true;
        // 如果 A 先遍历到了空节点，则说明 A 匹配不完 B，返回 false
        if (A == nullptr) return false; 
        // 如果 A 和 B 遍历到的节点值不同，则说明不匹配，返回 false
        if (A->val != B->val) return false; 

        // 如果 A->val == B->val，则递归判断其左、右子树是否匹配
        return isSame(A->left, B->left) && isSame(A->right, B->right);
    }

    // 主函数
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // 特判：依据题意，空树不是任意一个树的子结构
        if (A == nullptr || B == nullptr) return false;
        
        // 递归出口：如果此时 B 是 A 的子树，则返回 true
        if (isSame(A, B) == true) return true;

        // 递归判断 B 是不是 A 的左子树 或 A 的右子树 的子树
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};



// 无注释版本

class Solution {
public:
    bool isSame(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return true;
        if (A == nullptr) return false; 
        if (A->val != B->val) return false; 

        return isSame(A->left, B->left) && isSame(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;
        
        if (isSame(A, B) == true) return true;

        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};


