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

// BFS

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res; // 结果数组
        queue<TreeNode*> q; // BFS 队列
        // 特判：如果树为空，则返回空的二维数组
        if (root == nullptr) return res;
        q.push(root); // 根节点入队

        int cnt = 0;

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
            // 遍历完一层后，就要把 level 插入结果数组中
            // 比传统的层序遍历多一次判断：奇数层的翻转后插入结果数组
            cnt ++;
            if (cnt % 2 == 0) reverse(level.begin(), level.end());

            res.push_back(level);
        }
        return res; // 返回最终结果
    }
};