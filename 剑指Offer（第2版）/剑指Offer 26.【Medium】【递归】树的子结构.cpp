/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/solution/yi-pian-wen-zhang-dai-ni-chi-tou-dui-che-uhgs/


// 递归

class Solution {
public:
    // 辅助函数：判断二叉树 A 是否包含 B（即 B 是否为 A 的子树）
    bool dfs(TreeNode* A, TreeNode* B) {
        // 递归出口：
        // 如果 B 为空树，说明 B 先遍历完了，则说明 B 能完全匹配 A，返回 true
        if (B == nullptr) return true;
        // 否则，如果 B 不为空树，但是 A 先遍历完了，则说明 B 不能完全匹配 A，返回 false
        if (A == nullptr) return false; 
        // 如果 A 和 B 遍历到的节点值不同，则说明不匹配，返回 false
        if (A->val != B->val) return false; 

        // 否则，如果当前节点的值相等，继续递归判断 A 的左子树和 B 的左子树，以及 A 的右子树和 B 的右子树是否包含关系
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }

    // 主函数：判断 B 是不是 A 的子结构
    // 思路：从 A 的根节点开始向下找，看能否找到 A 的子树包含 B，如果能找到，则说明 B 是 A 的子结构
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // 特判：依据题意，空树不是任意一个树的子结构
        if (A == nullptr || B == nullptr) return false;
        
        // 递归出口：如果找到了 A 的子树 = B，则返回 true
        if (dfs(A, B) == true) return true;

        // 否则，递归判断 B 是不是 A 的左子树的子结构 或 A 的右子树的子结构
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};



// 无注释版本

class Solution {
public:
    bool dfs(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return true;
        if (A == nullptr) return false; 
        if (A->val != B->val) return false; 

        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;
        
        if (dfs(A, B) == true) return true;

        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};


