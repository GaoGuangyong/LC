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

// 解法一：
// 根据二叉搜索树的递归定义
// 如果该二叉树的左子树不为空，则左子树上所有节点的值均小于它的根节点的值
// 如果该二叉树的的右子树不空，则右子树上所有节点的值均大于它的根节点的值
// 它的左右子树也为二叉搜索树

typedef long long LL;

class Solution {
public:
    // dfs 函数：判断二叉树 root 是不是二叉搜索树，即判断 root 的值是否在 (min, max) 范围内
    bool dfs(TreeNode* root, LL min, LL max) {
        // 递归出口：如果遍历结束，则是二叉搜索树
        if (root == nullptr) return true;
        // 如果当前遍历节点的值在合法区间外
        if (root->val <= min || root->val >= max) return false;

        // 递归判断
        // root 的左儿子的值是否在 (min, root->val) 范围
        bool l = dfs(root->left, min, root->val);
        // root 的右儿子的值是否在 (root->val, max) 范围
        bool r = dfs(root->right, root->val, max);

        return l  && r; // 只有左子树 和 右子树都是，root 才是
    }

    // 判断以 root 为根节点的树是否为二叉搜索树
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};

// 无注释版本
typedef long long LL;

class Solution {
public:
    bool dfs(TreeNode* root, LL min, LL max) {
        if (root == nullptr) return true;
        if (root->val >= max || root->val <= min) return false;

        bool l = dfs(root->left, min, root->val);
        bool r = dfs(root->right, root->val, max);

        return l && r;
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);        
    }
};


// 解法二：
// 根据二叉搜索树的性质：一棵树是二叉搜索树，就等价于它的中序遍历是递增的
// 用中序遍历（左、根、右），记录一下最后一次遍历到的节点，下一个遍历到的节点一定要严格大于它就行了

class Solution {
public:
    TreeNode* pre = nullptr; // 记录中序遍历序列的前驱，初始时指向空

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true; // 特判：空树必是二叉搜索树
        // 左
        if (isValidBST(root->left) == false) return false;
        if (pre != nullptr && root->val <= pre->val) return false; // 如果前驱存在，且当前节点的值 <= 前驱，则不是二叉搜索树
        pre = root;
        if (isValidBST(root->right) == false) return false;

        return true;
    }
};

