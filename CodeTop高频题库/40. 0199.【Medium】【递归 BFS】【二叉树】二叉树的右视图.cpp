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


// 返回二叉树每一层的最右边节点
// 宽度优先搜索 --> 队列
// 图示见方法二：https://leetcode.cn/problems/binary-tree-right-side-view/solution/er-cha-shu-de-you-shi-tu-by-leetcode-solution/

// BFS

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {}; // 特判，如果是空树，则返回空数组
    
        queue<TreeNode*> q; // BFS 队列
        q.push(root); // 根节点入队

        vector<int> res; // 结果数组

        // BFS 过程（按层遍历）
        while (q.size()) { // 只要队列不空，就不断将节点入队
            int len = q.size(); // 当前层的节点数量

            while (len -- ) { // 遍历每一层的 len 个节点
                auto t = q.front(); // 获取队头元素（即当前层靠左边的节点）
                q.pop(); // 队头出队

                // 如果某一次队头元素出队后，len = 0 了，则说明刚刚出队的是当前层的最后一个节点，将其插入 res 数组
                if (len == 0) res.push_back(t->val);

                if (t->left != nullptr) q.push(t->left); // 如果当前节点有左儿子，就把左儿子入队
                if (t->right != nullptr) q.push(t->right); // 如果当前节点有右儿子，就把右儿子入队
            }
        }

        return res;
    }
};



// 二刷
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> res;
    
        while (q.size()) {
            int len = q.size();
            
            while (len -- ) {
                auto t = q.front();
                q.pop();

                if (len == 0) res.push_back(t->val);

                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }
        }

        return res;
    }
};