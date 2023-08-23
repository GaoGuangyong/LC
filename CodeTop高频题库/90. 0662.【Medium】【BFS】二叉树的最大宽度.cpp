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



// BFS
// 求二叉树所有层中，宽度的最大值
// 注意：某一层两个节点之间的空节点也是要占据宽度的
// 即相当于完全二叉树，设某个节点编号是 x，则其左儿子编号是 2x，其右儿子编号是 2x + 1
// 将每一层的节点 id 都从 1 开始，即将每一层的节点 id 变为 当前节点编号 - 最左侧节点编号 + 1，如下图
//（避免除最后一层之外的所有层只有一个节点，最后一层有两个节点的这种情况下，节点编号爆 int）
// 后来数据加强了，节点编号还是可能爆 int，需要转换一下

/*     
        编号                id

         1                  1
       /   \              /   \ 
      2     3     ->     1     2
     / \   / \          / \   / \
    4   5 6   7        1   2 3   4
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0; // 特判：空树的最大宽度为 0

        queue<pair<TreeNode*, int>> q; // BFS 队列，队列中的元素为 pair<节点，节点编号> 距离最左侧节点的距离
        q.push({root, 1}); // 将根节点入队

        // BFS 过程
        int res = 1; // 初始化最大宽度为1（至少包含一个节点，即根节点）
        while (q.size()) { // 只要队列不空，就不断将节点入队
            int len = q.size(); // 当前层的节点数量

            int l = q.front().second; // 当前层最左侧节点的编号
            int r; // 当前层最右侧节点的编号

            // 遍历每一层的 len 个节点
            while (len -- ) {
                auto t = q.front(); // 获取队头元素
                q.pop(); // 队头出队

                auto node = t.first; // 获取当前节点

                // 每次将当前节点的编号强制变成：编号 - l + 1，这样就可以保证每一层的节点都是从 1 开始编号，即注释里的图实现的过程
                auto id = t.second - l + 1; 
                
                r = t.second; // 更新 r

                // 当前节点的左儿子的编号是 2 * id (注意要强制类型转换，有可能爆int)
                if (node->left != nullptr) q.push({node->left, id * 2ll}); 
                // 当前节点的右儿子的编号是 2 * id - 1 (注意要强制类型转换，有可能爆int)
                if (node->right != nullptr) q.push({node->right, id * 2ll + 1}); 
            }

            // 每遍历完一层后，比较当前层的宽度和之前的最大宽度，更新最大宽度
            res = max(res, r - l + 1);
        }
        return res;
    }
};


