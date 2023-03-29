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
// 根据每个节点所在的层数，更新该层最左侧的节点
// 对于每一个节点，都先搜左儿子，再搜右儿子
// 则某一层第一个搜到的节点就是该层最左侧的节点（即层数变化时遍历到的那个节点）

class Solution {
public:
    int res; // 最下最左侧节点
    int maxd = 0; // 维护二叉树的最大深度，初始值设为 0
    
    // dfs 函数：从位于 d 层的节点 root 开始搜索，在搜索过程中更新每层的第一个节点的值
    void dfs(TreeNode* root, int d) {
        // 递归出口：如果遍历到了空节点，则表示当前这层已经搜完了，返回
        if (root == nullptr) return;

        

        // 如果当前节点的深度 > 最大深度 maxd，则说明搜索到了新的一层，当前节点就是本层最左侧节点，并更新最大深度
        if (d > maxd) {
            res = root->val; // 当前节点就是本层的最左侧节点
            maxd = d; // 更新最大深度 maxd
        }

        dfs(root->left, d + 1); // 递归遍历左子树
        dfs(root->right, d + 1); // 递归遍历右子树
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1); // 从根节点 root 开始递归搜索，层数为 1
        return res;
    }
};


// 无注释版本
class Solution {
public:
    int res; 
    int maxd = 0; 

    void dfs(TreeNode* root, int d) {
        if (root == nullptr) return;
      
        if (d > maxd) {
            res = root->val;
            maxd = d;
        }

        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
};