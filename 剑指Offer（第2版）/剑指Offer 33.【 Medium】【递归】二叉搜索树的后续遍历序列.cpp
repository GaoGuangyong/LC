
// 递归

// 二叉搜索树的特点：左子树 < 根 < 右子树

// 后序遍历序列 nums[l ... r] 的特点 nums[L, R, r]，根节点: nums[r]
// 从左向右遍历，找到第一个使 nums[pos] > nums[r] 成立的位置 pos, 则左子树 L: [l, pos - 1]，右子树 R: [pos, r - 1]
// 然后从 pos 开始向右遍历，如果有 < nums[r] 的，则不是二叉搜索树的后序序列

class Solution {
public:
    // 递归函数：判断序列 nums[l ~ r] 是不是某个二叉搜索树的后序遍历序列
    bool dfs(vector<int>& nums, int l, int r) {
        if (l >= r) return true; // l == r 显然是 true，而 l > r 是递归出口，也为 true
        
        int root = nums[r]; // 获取根节点：序列的最后一个元素

        // 从左往右找第一个 > 根节点的位置 pos
        int pos = l; 
        while (pos < r && nums[pos] < root) pos ++ ; // 找到 nums[pos]

        // 从 nums[pos] 开始向后遍历，如果有 nums[i] < root，则不是二叉搜索树的后序序列
        for (int i = pos; i < r; i ++ ) { 
            if (nums[i] < root) return false;
        }

        // 递归遍历 nums[l ~ pos - 1] 和 nums[pos ~ r - 1]
        return dfs(nums, l, pos - 1) && dfs(nums, pos, r - 1); 
    }


    // 主函数：给定一个数组，判断该数组是不是某个二叉搜索树的后序遍历序列
    bool verifyPostorder(vector<int>& postorder) {
        // 特判：空树也属于二叉搜索树
        if (postorder.empty()) return true; 

        // 递归判断序列 postorder[0 ~ n-1] 是不是某二叉搜索树的后序遍历序列
        return dfs(postorder, 0, postorder.size() - 1); 
    }
};


// 无注释版本
class Solution {
public:
    bool dfs(vector<int>& nums, int l, int r) {
        if (l >= r) return true;
        
        int root = nums[r];

        int pos = l; 
        while (pos < r && nums[pos] < root) pos ++ ;

        for (int i = pos; i < r; i ++ ) { 
            if (nums[i] < root) return false;
        }

        return dfs(nums, l, pos - 1) && dfs(nums, pos, r - 1); 
    }

    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) return true; 
        return dfs(postorder, 0, postorder.size() - 1); 
    }
};


