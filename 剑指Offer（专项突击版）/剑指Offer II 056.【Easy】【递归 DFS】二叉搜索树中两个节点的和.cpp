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

// DFS
// 像这类判断是否存在两数和为某一给定值的题，都用哈希表
// 我们可以使用 深度优先搜索 的方式遍历整棵树，用哈希表记录遍历过的节点的值
// 对于一个值为 x 的节点，我们检查哈希表中是否存在 k - x 即可
// 如果存在，那么就可以在该二叉树上找到两个节点的和为 k；否则，将 x 放入到哈希表中
// 如果遍历完整棵树（即遍历到了空节点）都不存在对应的元素，那么该树上不存在两个和为 k 的节点

class Solution {
public:
    // 全局变量
    unordered_set<int> S; // 定义一个哈希表，存二叉树中的节点值

    // 递归函数：遍历过程中判断以当前节点 root 为根的子树中是否存在 2 个节点，其和为 k
    bool dfs(TreeNode* root, int k) {
        // 递归出口：如果遍历到了空节点，则表示没有找到，返回 false
        if (root == nullptr) return false;

        int x = root->val; // 当前节点的值 x

        // 如果（k - x）在哈希表中已存在，则说明找到了 x 和 k - x，它们的和为 k，返回 true
        if (S.count(k - x)) return true; 
        // 否则，将 x 放入哈希表
        else S.insert(x);

        // 递归判断左右子树
        if (dfs(root->left, k) == true) return true;
        if (dfs(root->right, k) == true) return true;

        // 如果左右子树都找不到，则返回 false
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};


// 无注释版本
class Solution {
public:
    unordered_set<int> S;

    bool dfs(TreeNode* root, int k) {
        if (root == nullptr) return false;

        int x = root->val; 
        
        if (S.count(k - x)) return true; 
        else S.insert(x);

        if (dfs(root->left, k) == true) return true;
        if (dfs(root->right, k) == true) return true;

        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};

