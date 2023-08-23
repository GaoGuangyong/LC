
// BFS
// 该写法也作为 多源最短路问题 的模板

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 特判：如果树为空，则返回空数组
        if (root == nullptr) return {};
        
        queue<TreeNode*> q; // BFS 队列
        q.push(root); // 根节点入队

        vector<vector<int>> res; // 结果数组
        
        // BFS 过程
        while (q.size()) { // 队列不空时循环
            vector<int> level; // 存储每层遍历到的节点
            int len = q.size(); // 当前层的节点数量（！！！注意这里是 q.size() 不是 level.size()）
            
            // 遍历每一层的 len 个节点
            while (len -- ) { // 有的题出错，改用 for (int i = 0; i < len; i ++ )
                auto t = q.front(); // 获取队头
                q.pop(); // 队头出队

                level.push_back(t->val); // 将当前节点的值插入 level 数组
                if (t->left != nullptr) q.push(t->left); // 如果当前节点有左儿子，就把左儿子入队
                if (t->right != nullptr) q.push(t->right); // 如果当前节点有右儿子，就把右儿子入队
            }
            
            res.push_back(level); // 遍历完一层后，就要把 level 插入结果数组中
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


