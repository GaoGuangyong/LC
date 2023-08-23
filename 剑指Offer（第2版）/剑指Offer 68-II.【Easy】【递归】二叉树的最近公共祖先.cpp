/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 在二叉树 root 中查找 p, q 的最近公共祖先（LCA），并输出该节点

// 1、p 或 q 中的一个就是 root，则 root 就是最小公共祖先
// 2、如果在左、右子树中 p 和 q 各有一个，则 root 就是最近公共祖先
// 3、如果只在左子树中有 p 和 q 的最近公共祖先，则左子树的根节点就是最近公共祖先
// 4、如果只在右子树中有 p 和 q 的最近公共祖先，则右子树的根节点就是最近公共祖先
// 5、如果在左、右子树中都没有 p 和 q 的最近公共祖先，则没有最近公共祖先，返回空节点

class Solution {
public:
    // 在以 root 为根的树中查找 p 和 q
    // 如果 p 和 q 都存在，则返回它们的 LCA
    // 如果 p 和 q 只存在一个，则返回存在的那个
    // 如果 p 和 q 都不存在，则返回 nullptr
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归出口：遍历到空节点时，空树没有公共祖先，返回空
        if (root == nullptr) return nullptr;

        // 情况 1：p 或 q 中的一个就是 root，则 root 就是最小公共祖先
        if (root->val == p->val || root->val == q->val) return root;

        TreeNode* l = lowestCommonAncestor(root->left, p, q); // 递归的在左子树中查找节点 p 和 q
        TreeNode* r = lowestCommonAncestor(root->right, p, q); // 递归的在右子树中查找节点 p 和 q

        // 情况 2：如果 l 和 r 都不为空，说明节点 p 和 q 分别在左右子树中，则 root 是 LCA
        if (l != nullptr && r != nullptr) return root;

        // 情况 3：如果 r 为空，说明节点 p 和 q 都在左子树中，最终结果只看 l
        else if (l != nullptr && r == nullptr) return l;

        // 情况 4：如果 l 为空，说明节点 p 和 q 都在右子树中，最终结果只看 r
        else if (l == nullptr && r != nullptr) return r;
        
        // 情况 5：如果 l 和 r 都为空，说明在当前子树中没有找到 p 和 q，返回空指针
        else return nullptr;
    }
};

// 无注释版本
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root->val == p->val || root->val == q->val) return root;

        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);

        if (l != nullptr && r !=  nullptr) return root;
        else if (l != nullptr && r == nullptr) return l;
        else if (l == nullptr && r != nullptr) return r;
        else return nullptr;
    }
};
