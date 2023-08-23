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
// 根据每个节点所在的层数，更新该层的最大值
// 用哈希表存 <层号, 这层的最大值>

class Solution {
public:
    // 全局变量
    unordered_map<int, int> hash; // 定义哈希表，存层号 d 以及该层的最大值 hash[d]
    int maxd = INT_MIN; // 最大层数

    // 递归搜索在 d 层的 节点 root ，更新 d 层的最大值 hash[d] 以及 最大层数 maxd
    void dfs(TreeNode* root, int d) {
        // 递归出口：如果变量到了空节点，表示当前这层已经搜完了，返回
        if (root == nullptr) return;

        // 更新最大层数
        maxd = max(maxd, d);

        // 更新 d 层的最大值
        if (!hash.count(d)) hash[d] = root->val; // 如果哈希表中找不到 d，则当前节点 root 是 d 层的第一个节点，将 d 层的最大值初始化为当前节点的值
        else hash[d] = max(hash[d], root->val); // 否则，该层已有节点，更新该层的最大值

        dfs(root->left, d + 1); // 递归遍历左子树
        dfs(root->right, d + 1); // 递归遍历右子树
    }

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 1); // 从根节点 root 开始递归搜索，层数为 1

        vector<int> res; // 结果数组

        // 从层数 1 开始，直到最大层数 maxd，将每层的最大值插入结果数组
        for (int i = 1; i <= maxd; i ++ ) {
            res.push_back(hash[i]);
        }

        return res;
    }
};



// 无注释版本
class Solution {
public:
    unordered_map<int, int> hash;
    int maxd = INT_MIN;

    void dfs(TreeNode* root, int d) {
        if (root == nullptr) return;

        maxd = max(maxd, d);

        if (!hash.count(d)) hash[d] = root->val;
        else hash[d] = max(hash[d], root->val);

        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 1);

        vector<int> res;

        for (int i = 1; i <= maxd; i ++ ) res.push_back(hash[i]);

        return res;
    }
};


// 二刷
class Solution {
public:
    unordered_map<int, int> hash;
    int maxd = -1;

    void dfs(TreeNode* root, int d) {
        if (root == nullptr) return;

        maxd = max(maxd, d);

        if (!hash.count(d)) hash[d] = root->val;
        else hash[d] = max(hash[d], root->val);

        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 1);

        vector<int> res;
        for (int i = 1; i <= maxd; i ++ ) res.push_back(hash[i]);
        return res;
    }
};
