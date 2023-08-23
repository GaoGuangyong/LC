/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 根据中序遍历序列 & 先序遍历序列还原二叉树
// 为了快速找出中序遍历序列中某一个节点得位置：定义一个哈希表，记录中序序列中每个节点的下标（此操作常见于中序 + 前/后序还原二叉树）
// 一定画图分析遍历序列的下标范围
// 左子树中，先序遍历序列的下标范围：[pl + 1 ~ pl + (k - il)] 中序遍历的下标范围：[il ~ k - 1]
// 右子树中，先序遍历序列的下标范围：[pl + (k - il) + 1 ~ pr] 中序遍历的下标范围：[k + 1 ~ ir]

class Solution {
public:
    unordered_map<int, int> hash; // 定义一个哈希表，存中序遍历序列中每个元素及其下标
    vector<int> preorder; // 为了在 DFS 函数里使用 preorder，声明成全局变量
    vector<int> inorder; // 为了在 DFS 函数里使用 inorder，声明成全局变量

    // DFS 函数：根据 preorder[pl ~ pr] 和 inorder[il ~ ir] 构造二叉树，返回根节点
    TreeNode* dfs(int pl, int pr, int il, int ir) {
        if (il > ir) return nullptr; // 递归出口：如果当前区间长度为 0，则遍历结束，返回空节点

        TreeNode* root = new TreeNode(preorder[pl]); // 确定根节点：前序序列的第一个节点
        int k = hash[root->val]; // 在中序遍历序列中找到根节点的下标 k，则 k 左边序列的长度：(k - il)

        root->left = dfs(pl + 1, pl + k - il, il, k - 1) ; // 递归建立左子树
        root->right = dfs(pl + k - il + 1, pr, k + 1, ir); // 递归建立右子树

        return root;
    }

    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
        preorder = _preorder;
        inorder = _inorder;

        int n = preorder.size();
        
        // 维护哈希表，记录中序遍历序列中每个节点的下标
        for (int i = 0; i < n; i ++ ) hash[inorder[i]] = i;
        
        return dfs(0, n - 1, 0, n - 1); // 初始时，先序和中序遍历的范围都是整个数组
    }
};


// 无注释版本
class Solution {
public:
    unordered_map<int, int> hash;
    vector<int> preorder;
    vector<int> inorder;

    TreeNode* dfs(int pl, int pr, int il, int ir) {
        if (il > ir) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]); 
        int k = hash[root->val];

        root->left = dfs(pl + 1, pl + k - il, il, k - 1);
        root->right = dfs(pl + k - il + 1, pr, k + 1, ir);
        
        return root;
    }


    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
        preorder = _preorder;
        inorder = _inorder;
        
        int n = preorder.size();
        for (int i = 0; i < n; i ++ ) hash[inorder[i]] = i;
        
        return dfs(0, n - 1, 0, n - 1);
    }
};


// 代码框架
class Solution {
public:
    unordered_map<int, int> hash;
    vector<int> preorder;
    vector<int> inorder;

    TreeNode* dfs(int pl, int pr, int il, int ir) {
        
    }


    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
        
    }
};



// 二刷
class Solution {
public:
    unordered_map<int, int> hash;
    vector<int> preorder;
    vector<int> inorder;

    TreeNode* dfs(int pl, int pr, int il, int ir) {
        if (il > ir) return nullptr;

        TreeNode* root = new TreeNode(preorder[pl]);
        int k = hash[root->val];

        root->left = dfs(pl + 1, k - il + pl, il, k - 1);
        root->right = dfs(k - il + pl + 1, pr, k + 1, ir);

        return root;
    }

    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
        preorder = _preorder;
        inorder = _inorder;
        
        int n = inorder.size();
        for (int i = 0; i < n; i ++ ) hash[inorder[i]] = i;

        return dfs(0, n - 1, 0, n - 1);
    }
};



