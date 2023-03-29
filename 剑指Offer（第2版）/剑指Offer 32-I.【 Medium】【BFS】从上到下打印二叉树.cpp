/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// BFS
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res; // 结果数组
        if (root == nullptr) return {}; // 如果是空树，则什么都不做，直接返回空数组
        
        queue<TreeNode*> q; // BFS 队列
        q.push(root); // 根节点入队

        // BFS 过程
        while (q.size()) { // 只要队列不空，就不断将节点入队
            auto t = q.front(); // 获取队头
            q.pop(); // 队头出队

            res.push_back(t->val); // 将队头节点加入结果数组

            // 如果队头节点有左右孩子的话，将左右孩子也入队，稍后处理
            if (t->left != nullptr) q.push(t->left);
            if (t->right != nullptr) q.push(t->right);
        }
        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;

        if (root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);

        while (q.size()) {
            auto t = q.front();
            q.pop();
            res.push_back(t->val);
            if (t->left != nullptr) q.push(t->left);
            if (t->right != nullptr) q.push(t->right);
        }

        return res;
    }
};

