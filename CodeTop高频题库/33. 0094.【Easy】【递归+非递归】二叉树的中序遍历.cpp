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


// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历

// 解法一：非递归（用栈实现）
// 专门用来解决 树的遍历问题 的非递归写法
// 只要当前节点非空，就将其压入栈，然后向左走，一直这样走，就会走到左下角
// 此时，如果栈不空，就从栈顶弹出左下角的节点，加入结果数组，再向右走
// 下一轮循环时，对右儿子做同样的操作

// 像这种只能解决一类特定问题的代码，要求背下来

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        stack<TreeNode*> stk;

        while (root != nullptr || !stk.empty()) { // 当前节点非空 或 栈不空 时循环

            // 只要当前节点非空，就压入栈，并一路向左走，直到将左下角的节点压栈
            while (root != nullptr) { 
                stk.push(root); // 将当前节点入栈
                root = root->left; // 向左遍历
            }

            // 此时，如果栈不空，就用 root 指向栈顶节点（即左下角节点），然后从栈顶弹出左下角的节点，加入结果数组，再向右走
            if (!stk.empty()) {
                root = stk.top(); // 将 root 指向左下角节点
                stk.pop(); // 将左下角节点从栈中弹出
                res.push_back(root->val); // 将左下角节点的节点值加入结果数组

                root = root->right; // 向右遍历
            }
        }

        return res;
    }
};


// 框架版本
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        // 当前节点非空 或 栈不空时循环

            // 只要当前节点非空，就压入栈，并一路向左走，直到走到左下角


            // 此时，如果栈不空，就从栈顶弹出左下角的节点，加入结果数组，再向右走


    }
};


// 二刷
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;

        while (root != nullptr || !stk.empty()) {
            
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }

            if (!stk.empty()) {
                root = stk.top();
                stk.pop();

                res.push_back(root->val);

                root = root->right;
            }
        }

        return res;
    }
};


// 解法二：递归

class Solution {
public:
    vector<int> res; // 结果数组

    void dfs(TreeNode* root) {
        // 递归出口
        if (root == nullptr) return; // 若遍历到了空节点，则返回
        // 递归左子树
        dfs(root->left);
        // 遍历当前结点
        res.push_back(root->val);
        // 递归右子树
        dfs(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};


