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
// 本题显然属于先计算，后递归的类型

class Solution {
public:
    // 全局变量
    int res = 0;

    // DFS 函数：从 root 节点向下遍历，root 节点之前的路径上的数字是 num，在遍历过程中更新 res
    // 注意：该 dfs 函数没有 return，这和一般的写法不一样
    void dfs(TreeNode* root, int num) {
        // 遍历到 root 节点后，路径上的数字就变成了 num * 10 + root->val
        num = num * 10 + root->val;

        // 递归出口：如果当前遍历的节点是叶节点，则把当前的数字 num 加到结果 res 中
        if (root->left == nullptr && root->right == nullptr) res += num;

        if (root->left != nullptr) dfs(root->left, num); // 如果有左儿子，则递归左儿子
        if (root->right != nullptr) dfs(root->right, num); // 如果有右儿子，则递归右儿子
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};


// 无注释版本
class Solution {
public:
    int res = 0;

    void dfs(TreeNode* root, int num) {
        num = num * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) res += num;

        if (root->left) dfs(root->left, num);
        if (root->right) dfs(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};


