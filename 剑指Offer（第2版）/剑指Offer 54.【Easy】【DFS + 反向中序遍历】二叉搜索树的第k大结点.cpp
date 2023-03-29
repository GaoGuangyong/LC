/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉搜索树 + 反向中序遍历

// 中序遍历即可得到有序序列 [最小值 ... 最大值]，则第 k 大的节点就是第 n - k + 1 个节点，与 n 有关
// 反向中序遍历也可得到有序序列 [最大值 .. 最小值]，则第 k 大的节点就是第 k 个节点，与 n 无关

// 求第 k 大的节点：按照反向中序遍历，每次遍历到节点时 k -- ，当 k 减到 0 时，那个节点就是第 k 大的
// 求第 k 小的节点：按照中序遍历，每次遍历到节点时 k -- ，当 k 减到 0 时，那个节点就是第 k 小的

class Solution {
public:
    // 全局变量
    int res;
    int k;

    // DFS 函数：逆序中序遍历二叉搜索树
    void dfs(TreeNode* root) {
        // 递归出口：当遍历到空节点，说明遍历完了，返回
        if (root == nullptr) return; 

        // 右
        dfs(root->right);

        // 每次遍历到当前节点时 k -- ，当 k 减到 0 时，那个节点就是第 k 大的
        k -- ;
        if (k == 0) {
            res = root->val;
            return;  // 减枝：当 k 减到 0 时，返回，此时 res 指向的节点就是第 k 大的节点
        }

        // 左
        dfs(root->left);
    }

    // 主函数
    int kthLargest(TreeNode* root, int _k) {
        k = _k;
        dfs(root);
        return res;
    }
};


// 无注释版本
class Solution {
public:
    int res;
    int k;

    void dfs(TreeNode* root) {
        if (root == nullptr) return; 

        dfs(root->right);

        k -- ;
        if (k == 0) {
            res = root->val;
            return;
        }

        dfs(root->left);
    }

    int kthLargest(TreeNode* root, int _k) {
        k = _k;
        dfs(root);
        return res;
    }
};
