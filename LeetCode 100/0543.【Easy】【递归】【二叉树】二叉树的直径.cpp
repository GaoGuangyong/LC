
// 扩展：N叉树 -> LC 1522
// 我们定义根节点的深度定义为 1，空节点的深度定义为 0
// 因为直径是求边数，深度是求节点数，所以：
// 某个节点为根的子树的直径的左边长度 = 其左子树的最大深度
// 某个节点为根的子树的直径的右边长度 = 其右子树的最大深度

// 因此对于以节点 root 为根节点的二叉树，其直径 = 左边长度 + 右边长度 = 其左子树的最大深度 + 其右子树的最大深度

class Solution {
public:
    int res = 0;

    // 递归函数，返回以 root 节点为根的子树的深度，在递归过程中，计算每个节点为根的子树的直径
    int dfs(TreeNode* root) {
        // 递归出口：遍历到空节点时，遍历结束，返回空节点的深度 0
        if (root == nullptr) return 0;

        // 递归左右子树
        int l = dfs(root->left); // 求当前节点左子树的深度
        int r = dfs(root->right); // 求当前节点右子树的深度

        // 以当前节点为根的子树的直径 = 左子树的深度 + 右子树的深度
        res = max(res, l + r); // 更新直径的最大值

        // 返回以 root 为根的子树的深度
        return max(l, r) + 1; // 深度 = max(左儿子深度，右儿子深度) + 当前节点指向这两个儿子的边
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};

// 无注释版
class Solution {
public:
    int res = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        res = max(res, l + r); // 更新直径的最大值

        return max(l, r) + 1; // 返回以 root 为根的子树的深度
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;    
    }
};


