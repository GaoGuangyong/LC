/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 同面试题 04.06.
// 利用二叉搜索树的性质
// 二叉搜索树的一个性质是中序遍历序列单调递增，因此二叉搜索树中的节点 p 的中序后继满足条件：
// 中序后继是节点值大于 p 的节点值的所有节点中节点值最小的一个节点

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = nullptr; // 定义后继指针，初始化为空指针，最终返回这个指针

        //【1】如果 p 节点有右儿子，则从 p 节点右儿子开始一路向左，最左边的那个节点就是 p 节点的后继
        if (p->right != nullptr) {
            res = p->right; // 先将后继指针指向 p 的右儿子
            while (res->left != nullptr) { // 当 p 的右儿子有左儿子，就一路向左
                res = res->left;
            } 
            return res;
        }

        //【2】如果节点 p 没有右儿子，则它的后继节点就是第一个 > p 的祖先节点
        // 从根节点开始遍历二叉搜索树，寻找节点 p 的祖先节点，直到节点为 空 或找到了祖先节点
        while (root != nullptr) {
            // 如果 root > p，则 p 的后继节点可能是 root 或者在 root 的左子树中
            if (root->val > p->val) {
                res = root; // root 可能是后继节点
                root = root->left; // 将 root 移动到其左子节点继续遍历
            }
            // 否则，p 的后继节点可能在 root 的右子树中
            else {
                root = root->right; // 将 root 移动到其右子节点继续遍历
            }
        } // 循环结束后，res 指向的就是 p 的后继

        return res;
    }
};


// 写法二（推荐）
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // 初始化结果节点为 空
        TreeNode* res = nullptr;

        // 遍历二叉搜索树，直到节点为 空 或找到了目标节点的位置
        while (root != nullptr) {
            // 目标节点在当前节点的左子树中
            if (root->val > p->val) {  
                res = root; // 记录当前节点为可能的后继节点
                root = root->left; // 继续在左子树中查找目标节点的后继节点
            } 
            // 目标节点在当前节点的右子树中
            else {  
                // 不记录当前节点，因为当前节点不是目标节点的后继节点
                // 目标节点的后继节点一定在右子树中，所以直接继续在右子树中查找
                root = root->right;
            }
        }
        // 返回可能的后继节点
        return res;
    }
};


// 无注释版本

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = nullptr;

        while (root != nullptr) {
            if (root->val > p->val) {
                res = root;
                root = root->left;
            }
            else {
                root = root->right; 
            }
        }

        return res;
    }
};

