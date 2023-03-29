
// 递归
// 二叉搜索树的特点：左子树 < 根 < 右子树

// 后序遍历序列 a[l ... r] 的特点 a[L, R, root]，根节点: a[r]
// 从左向右遍历，找到第一个使 a[pos] > a[r] 成立的位置 pos, 则左子树 L: [0, pos -1]，右子树 R: [pos, r - 1]
// 然后从 pos 开始向右遍历，如果有 < a[r] 的，则不是二叉搜索树的后序序列


class Solution {
public:
    // 递归函数：判断序列 a[l ~ r] 是不是某个二叉搜索树的后序遍历序列
    bool dfs(vector<int>& a, int l, int r) {
        if (r <= l) return true; // r == l 显然是true，而 r < l 是递归出口，也为true
        
        int root = a[r]; // 取序列的最后一个元素作为根节点

        // 从左往右找第一个 > 根节点的位置 pos
        int pos = l; 
        while (pos < r && a[pos] < root) pos ++ ; // 找到 a[pos]

        // 从 a[pos] 开始向后遍历，如果有 a[i] < root，则不是二叉搜索树的后序序列
        for (int i = pos; i < r; i ++ ) { 
            if (a[i] < root) return false;
        }

        // 递归遍历 a[l ~ pos - 1] 和 a[pos ~ r - 1]
        return dfs(a, l, pos - 1) && dfs(a, pos, r - 1); 
    }


    // 主函数
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
    bool dfs(vector<int>& a, int l, int r) {
        if (r <= l) return true;
        
        int root = a[r];

        int pos = l; 
        while (pos < r && a[pos] < root) pos ++ ;

        for (int i = pos; i < r; i ++ ) { 
            if (a[i] < root) return false;
        }

        return dfs(a, l, pos - 1) && dfs(a, pos, r - 1); 
    }

    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) return true; 
        return dfs(postorder, 0, postorder.size() - 1); 
    }
};


