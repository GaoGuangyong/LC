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

// 类似面试题 04.12 但本题要求必须从根节点到叶节点
// DFS + 回溯
// 从根节点开始向下遍历二叉树，当遍历到叶节点时，判断一下当前路径的和是否为目标值 target
// 这种路径求和的问题，采用递归，每访问一个非叶子节点时，将当前节点值 t 放入 path 数组，并将目标和 target -= t
// 当遍历到叶节点时，只需判断 target 是否为 0

class Solution {
public:
    // 全局变量
    vector<int> path; // 当前路径
    vector<vector<int>> res; // 所有路径
    
    // 递归函数：在二叉树 root 中，找从根节点开始到叶节点和为 sum 的路径
    void dfs(TreeNode* root, int sum) {
        // 递归出口：遍历到空节点时结束当前路径
        if (root == nullptr) return; 

        // 获取当前访问的节点值
        int t = root->val; 

        // 选择当前节点
        path.push_back(t);
        sum -= t;

        // 若当前是叶节点，且 sum == 0，则找到了一条合法路径，将 path 放入 res 中
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            res.push_back(path);
        }
        // 递归左右儿子节点
        dfs(root->left, sum);
        dfs(root->right, sum);

        // 撤销选择
        path.pop_back();
        sum += t;
    }

    // 主函数
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target); // 在二叉树 root 中查找和为 target 的路径
        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(TreeNode* root, int target) {
        if (root == nullptr) return;

        int t = root->val;

        path.push_back(t);
        target -= t;    

        if (root->left == nullptr && root->right == nullptr && target == 0) res.push_back(path);
        dfs(root->left, target);
        dfs(root->right, target);

        path.pop_back();
        target += t;
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return res;    
    }
};




// 补充：面试题 04.12
class Solution {
public:
    int res;    
    
    // 递归函数：在以 root 为根的子树中查找和为 sum 的路径
    void dfs(TreeNode* root, int sum) {
        // 递归出口：遍历到空节点时结束当前路径
        if (root == nullptr) return;
        // 否则，不断将当前节点的值加入 path，并从 sum 中减去当前节点的值
        // 选择
        sum -= root->val;
        if (sum == 0) res += 1;
        // 递归
        dfs(root->left, sum);
        dfs(root->right, sum);
        // 撤销选择
        sum += root->val;
    }

    int pathSum(TreeNode* root, int sum) {
        // 特判
        if (root == nullptr) return 0;
        // 从当前节点往下遍历查找求和路径
        dfs(root, sum); 
        // 递归遍历，分别从当前节点的左右子树开始往下查找求和路径
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return res;
    }
};

