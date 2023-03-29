

// DP
// 状态表示：
// f[i] 表示用 i 个节点（1 ~ i）能组成的二叉搜索树的数量，则答案为 f[n]

// 状态转移：
// 左子树可以有 0, 1, ... , n − 1 个节点，对应的右子树有 n − 1, n − 2, ... , 0 个节点
// 对于某个位置 i，枚举根节点 j：
// 将 [1 ~ i] 划分成 2 个区间，左侧为 [1 ~ j - 1]，右侧为 [j + 1 ~ i]，长度（节点数）分别为 j - 1 和 i - j
// f[i] = f[j - 1] * f[i - j]
// 将所有的 f[i] 相加即可

class Solution {
public:
    int numTrees(int n) {
        // 定义状态数组
        vector<int> f(n + 1);

        // 初始化
        f[0] = 1;

        // 状态转移
        // 枚举 1 ~ n
        for (int i = 1; i <= n; i ++ ) {
            // 对于当前的 i，枚举根节点 j
            for (int j = 1; j <= i; j ++ ) {
                f[i] += f[j - 1] * f[i - j];
            }
        }
        return f[n];
    }
};

// 无注释版本

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1);

        f[0] = 1;
        
        for (int i  = 1; i <= n; i ++ ) {
            for (int j = 1; j <= i; j ++ ) {
                f[i] += f[j - 1] * f[i - j];
            }
        }

        return f[n];
    }
};



// DFS
// 对于每段连续的序列 l,l+1,…rl,l+1,…r，枚举二叉搜索树根节点的位置；
// 分别递归求出左右子树的所有方案；
// 左子树的任意一种方案和右子树的任意一种方案拼在一起，可以得到当前节点的一种方案，所以我们将左右子树的所有方案两两组合，并记录在答案中。
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

    // 递归区间 [l, r]
    vector<TreeNode*> dfs(int l, int r) {
        // 递归出口
        if (l > r) return {nullptr}; // 如果当前子区间例没有节点了，则当前子树就是空的，返回空树 {nullptr}
        vector<TreeNode*> res;

        // 枚举根节点位置
        for (int k = l; k <= r; k ++ ) {
            auto left = dfs(l, k - 1);
            auto right = dfs(k + 1, r);
            // 左边选一个右边选一个
            for (TreeNode* l: left)
                for (TreeNode* r: right) {
                    // 拼成一棵树
                    TreeNode* root = new TreeNode(k);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
        }

        return res;
    }
};
