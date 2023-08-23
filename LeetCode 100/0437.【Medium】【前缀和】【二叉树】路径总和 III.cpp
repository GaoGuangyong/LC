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
// 前缀和，见笔记
// 先看一维版 题目lc 560. 和为 K 的子数组，再做这个就好一些，否则直接想有点难度

// 如果前缀和 curSum，在节点 A 和节点 B 处相差 target，则位于节点 A 和节点 B 之间的节点之和就是 target
// 抵达当前节点(即 B 节点)后，将前缀和累加，然后查找在前缀和哈希表中，有没有前缀和 curSum-target 的节点(即 A 节点)
// 有几个这样的节点，就表示从 A 到 B 有几条路径之和满足条件的情况。然后递归进入左右子树
// 左右子树遍历完成之后，回到当前层，需要把当前节点添加的前缀和去除。避免回溯之后影响上一层
// 因为思想是前缀和，不属于前缀的，我们就要去掉它。

class Solution {
public:
    unordered_map<long long, int> hash; // 定义哈希表，存前缀和及其出现的次数
    int res = 0;

    // 递归函数：从节点 root 开始遍历二叉树，目标和为 target，到当前节点之前的前缀和为 curSum
    void dfs(TreeNode* root, int target, long long curSum) {
        // 递归出口：如果遍历到了空节点，则直接返回
        if (root == nullptr) return;

        curSum += root->val; // 更新前缀和 += 当前节点的值
        res += hash[curSum - target]; // 将前缀和 curSum - target 出现的次数加到结果上，即有多少个 A 这样的节点
        
        hash[curSum] ++ ; // 当前前缀和出现的次数 + 1

        dfs(root->left, target, curSum); // 递归到左子树找 target
        dfs(root->right, target, curSum); // 递归到右子树找 target

        hash[curSum] -- ; // 回溯，当前前缀和出现的次数 - 1
    }

    int pathSum(TreeNode* root, int targetSum) {
        hash[0] = 1; // 初始化哨兵，表示和为 0 的前缀只有 1 个
        dfs(root, targetSum, 0); // 从根节点开始遍历，目标和是 targetSum，当前的前缀和是 0
        return res;
    }
};

// 无注释版本
typedef long long LL;

class Solution {
public:
    unordered_map<LL, int> hash;
    int res = 0;

    void dfs(TreeNode* root, int target, LL curSum) {
        if (root == nullptr) return;
        
        curSum += root->val;

        res += hash[curSum - target];
        hash[curSum] ++ ;

        dfs(root->left, target, curSum);
        dfs(root->right, target, curSum);

        hash[curSum] -- ;

    } 

    int pathSum(TreeNode* root, int targetSum) {
        hash[0] = 1;
        dfs(root, targetSum, 0);
        return res;
    }
};

