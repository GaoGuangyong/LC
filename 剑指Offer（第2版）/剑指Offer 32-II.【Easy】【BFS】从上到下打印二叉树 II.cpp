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
    // 将二叉树按层序遍历的顺序输出，每层输出为 1 个数组
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 特判：如果树为空，则返回空数组
        if (root == nullptr) return {};

        vector<vector<int>> res; // 结果数组
        queue<TreeNode*> q; // BFS 队列
        q.push(root); // 根节点入队

        // BFS 过程
        while (q.size()) { // 队列不空时循环
            vector<int> level; // 存储每层遍历到的节点
            int len = q.size(); // 当前层的节点数量
            
            // 遍历每一层的 len 个节点
            while (len -- ) {
                auto t = q.front(); // 获取队头
                q.pop(); // 队头出队

                level.push_back(t->val); // 将当前节点的值插入 level 数组

                if (t->left != nullptr) q.push(t->left); // 如果当前节点有左儿子，就把左儿子入队
                if (t->right != nullptr) q.push(t->right); // 如果当前节点有右儿子，就把右儿子入队
            }

            // 遍历完一层后，把 level 插入结果数组中
            res.push_back(level);
        }
        
        return res; // 返回最终结果
    }
};


// 无注释版本
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);

        while (q.size()) {
            vector<int> level;
            int len = q.size();

            while (len -- ) {
                auto t = q.front();
                q.pop();

                level.push_back(t->val);
                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }

            res.push_back(level);
        }

        return res;
    }
};


