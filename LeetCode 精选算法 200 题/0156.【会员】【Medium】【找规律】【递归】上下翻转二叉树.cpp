// https://leetcode.cn/problems/binary-tree-upside-down/solution/shang-xia-fan-zhuan-er-cha-shu-by-nortondark/

// 注意，题解说：所有右节点，都是叶子节点，且有兄弟节点

// 例子
//       1                 4
//      / \               / \
//     2   3     ->      5   2
//    / \                   / \
//   4   5                 3   1

// 规律
//【1】3、5 是右叶子节点，变为左叶子节点
//【2】根和子树的根，变为右叶子节点 


// 关于【2】的说明：每次递归旋转后 root 都会变成右叶子节点

//       1                 2
//      / \      ->       / \
//     2   3             3   1
//                          / \
//                         空  空


class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        // 特判：如果是空树，则返回空
        if (root == nullptr) return nullptr;

        // 递归出口：如果遍历到叶节点，返回叶节点
        if (root->left == nullptr && root->right == nullptr) return root;

        // 只需递归处理左子树，不需要递归右子树，右子树都是叶子节点
        TreeNode* newRoot = upsideDownBinaryTree(root->left);

        // 三角关系翻转
        root->left->left = root->right; // 4 -> 5, 2 -> 3  
        root->left->right = root; // 4 -> 2, 2 -> 1  
        
        // 根 和 子树的根，变为右叶子节点 （每次递归旋转后 root 都会变成右叶子节点）
        root->left = nullptr;
        root->right = nullptr;

        // 返回整棵树最左的叶子节点
        return newRoot;
    }
};



// 无注释版本
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        if (root->left == nullptr && root->right == nullptr) return root;

        TreeNode* newRoot = upsideDownBinaryTree(root->left);

        root->left->left = root->right;
        root->left->right = root; 
        
        root->left = nullptr;
        root->right = nullptr;

        return newRoot;
    }
};
