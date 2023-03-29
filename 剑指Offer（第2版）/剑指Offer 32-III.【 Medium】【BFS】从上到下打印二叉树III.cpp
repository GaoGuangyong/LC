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
// 二叉树的之字形层序遍历

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; // 结果数组
        if (root == nullptr) return {}; // 特判：如果二叉树为空，则直接返回空数组

        queue<TreeNode*> q; // BFS 队列
        q.push(root); // 根节点入队

        int level = 0; // 记录层数的变量，初始为 0 代表根节点所在层为 0 层

        // BFS 过程
        while (q.size()) { // 只要队列不空，就不断将节点入队
            vector<int> path; // 存每层遍历到的节点
            int len = q.size(); // 当前层的节点数量

            // 遍历每一层的 len 个节点
            while (len -- ) {
                auto t = q.front(); // 获取队头
                q.pop(); // 队头出队

                path.push_back(t->val); // 将当前节点的值插入 path 数组
                if (t->left != nullptr) q.push(t->left); // 如果当前节点有左儿子，就把左儿子入队
                if (t->right != nullptr) q.push(t->right); // 如果当前节点有右儿子，就把右儿子入队
            }
            // 如果是奇数层的节点，则反转 path 数组
            if (level % 2 == 1) {
                reverse(path.begin(), path.end());
            }
            level ++ ; // 层数 +1
            res.push_back(path);
        }
        return res;
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

        int level = 0;

        while (q.size()) {
            vector<int> path;
            int len = q.size();

            while (len -- ) {
                auto t = q.front();
                q.pop();

                path.push_back(t->val);
                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }

            if (level % 2 == 1) reverse(path.begin(), path.end());
            
            level ++ ;
            res.push_back(path);
        }

        return res;
    }
};



