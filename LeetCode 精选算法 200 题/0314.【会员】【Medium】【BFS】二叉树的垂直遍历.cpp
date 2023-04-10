/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 写法一：声明 2 个队列

class Solution {
public:
    // 全局变量
    map<int, int> hash; // 定义有序哈希表：存 <竖向下标，在 res 中的下标 i>
    vector<vector<int>> res; // res[i] 表示竖向下标为 i 的列中的所有节点

    // 主函数
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL) return res;

        queue<TreeNode*> q; // BFS 队列，存节点值
        q.push(root); // 根节点入队

        queue<int> idx; // BFS 队列，存节点的 "竖向下标"
        idx.push(0); // 根节点下标入队

        // BFS 过程
        while (q.size()) {
            auto node = q.front();
            auto row = idx.front();

            q.pop();
            idx.pop();

            // 如果当前下标在哈希表中不存在，则是竖向的第一个节点
            if (!hash.count(row)) {
                // 定义一个 path 数组，存当前下标所在列中的节点
                vector<int> path;
                // 将当前节点加入 path 数组
                path.push_back(node->val);
                // 将 path 数组加入 res 数组中 
                res.push_back(path);
                // 当前这列竖向下标为 row 的数组存放在 res 的下标 hash[row] 处 
                hash[row] = res.size() - 1;
            }
            // 如果当前下标在哈希表中存在，则直接将当前节点加入 res[hash[row]]
            else {
                res[hash[row]].push_back(node->val);
            }

            // 如果有左儿子，就将左儿子入队，左儿子的竖向下标为 当前节点的竖向下标 - 1
            if (node->left != NULL) {
                q.push(node->left);
                idx.push(row - 1);
            }
            // 如果有右儿子，就将右儿子入队，右儿子的竖向下标为 当前节点的竖向下标 + 1
            if (node->right != NULL) {
                q.push(node->right);
                idx.push(row + 1);
            }           

        }

        // 遍历有序哈希表，按下标递增的顺序把 res[v] 数组输出
        vector<vector<int>> ordered_res;
        for (auto& [k, v]: hash) {
            ordered_res.push_back(res[v]);
        }
        return ordered_res;
    }
};


// 写法二（改进）：声明 1 个队列

class Solution {
public:
    // 全局变量
    map<int, int> hash; // 定义有序哈希表：存 <竖向下标，在 res 中的下标 i>
    vector<vector<int>> res; // res[i] 表示竖向下标为 i 的列中的所有节点

    // 主函数
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL) return res;

        queue<pair<TreeNode*, int>> q; // BFS 队列，存 <节点, 节点的竖向下标>
        q.push({root, 0}); // 根节点入队

        // BFS 过程
        while (q.size()) {
            auto t = q.front();
            q.pop();

            auto node = t.first;
            auto row = t.second;

            // 如果当前下标在哈希表中不存在，则是竖向的第一个节点
            if (!hash.count(row)) {
                // 定义一个 path 数组，存当前下标所在列中的节点
                vector<int> path;
                // 将当前节点加入 path 数组
                path.push_back(node->val);
                // 将 path 数组加入 res 数组中 
                res.push_back(path);
                // 当前这列竖向下标为 row 的数组存放在 res 的下标 hash[row] 处 
                hash[row] = res.size() - 1;
            }
            // 如果当前下标在哈希表中存在，则直接将当前节点加入 res[hash[row]]
            else {
                res[hash[row]].push_back(node->val);
            }

            // 如果有左儿子，就将左儿子入队，左儿子的竖向下标为 当前节点的竖向下标 - 1
            if (node->left != NULL) {
                q.push({node->left, row - 1});
            }
            // 如果有右儿子，就将右儿子入队，右儿子的竖向下标为 当前节点的竖向下标 + 1
            if (node->right != NULL) {
                q.push({node->right, row + 1});
            }           
        }

        // 遍历有序哈希表，按下标递增的顺序把 res[v] 数组输出
        vector<vector<int>> ordered_res;
        for (auto& [k, v]: hash) {
            ordered_res.push_back(res[v]);
        }
        return ordered_res;
    }
};


// 无注释版本
class Solution {
public:
    map<int, int> hash;
    vector<vector<int>> res;

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) return res;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (q.size()) {
            auto t = q.front();
            q.pop();

            auto node = t.first;
            auto row = t.second;

            if (!hash.count(row)) {
                vector<int> path;
                path.push_back(node->val);
                res.push_back(path);
                hash[row] = res.size() - 1;
            }
            else {
                res[hash[row]].push_back(node->val);
            }

            if (node->left != NULL) {
                q.push({node->left, row - 1});
            }
            if (node->right != NULL) {
                q.push({node->right, row + 1});
            }           

        }

        vector<vector<int>> ordered_res;
        
        for (auto& [k, v]: hash) {
            ordered_res.push_back(res[v]);
        }

        return ordered_res;
    }
};
