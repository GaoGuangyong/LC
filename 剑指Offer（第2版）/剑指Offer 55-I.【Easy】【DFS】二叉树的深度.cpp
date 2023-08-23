/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 解法一
class Solution {
public:
    int res = 0; // 二叉树深度的最大值

    // 递归函数：从二叉树 root 的深度 depth 开始遍历，并在遍历过程中维护最大深度
    void dfs(TreeNode* root, int depth) {
        // 递归出口：若遍历到空节点，则直接返回
        if (root == nullptr) return; 

        // 每遍历到一个节点，都先更新当前的最大深度
        res = max(res, depth); 
        
        // 递归处理左右子树
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int maxDepth(TreeNode* root) {
        dfs(root, 1); // 递归起点：树根，此时深度为1
        return res;
    }
};

// 无注释版本
class Solution {
public:
    int res = 0;

    void dfs(TreeNode* root, int depth){
        if (root == nullptr) return; 

        res = max(res, depth);
        
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int maxDepth(TreeNode* root) {
        dfs(root, 1); // 递归起点：树根，此时深度为1
        return res;
    }
};


// 解法二
// 某个节点的深度最大值为其左/右子树深度的最大值 + 1

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

