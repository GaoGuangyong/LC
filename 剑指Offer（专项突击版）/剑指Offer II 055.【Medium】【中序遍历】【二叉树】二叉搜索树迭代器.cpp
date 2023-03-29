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

// 将 LC 94 题 二叉树的中序遍历的代码拆分到 BSTIterator 和 next 这两个函数里
// 为了实现循环的效果，每次 next 函数主体完成后，要再加上初始化代码，继续下一次循环

class BSTIterator {
public:
    stack<TreeNode*> stk;

    // 初始化，只要当前节点有左儿子，就一直向左，将所有的左儿子都加到栈中
    BSTIterator(TreeNode* root) {
        while (root != nullptr) { // 只要当前节点非空，就一路向左走
            stk.push(root);
            root = root->left;
        }
    }

    // 找二叉搜索树的中序遍历的下一个数，即下一个最小的元素，栈不空时才执行 next 函数
    int next() {
        // next 函数的主体
        auto root = stk.top(); // 取栈顶
        stk.pop(); // 栈顶出栈

        int v = root->val; // 记录下栈顶的值
        
        root = root->right;

        // 执行下一次循环
        while (root != nullptr) { // 只要当前节点非空，就一路向左走
            stk.push(root);
            root = root->left;
        }

        return v; // 每循环一次返回：出栈的元素，即下一个最小的元素
    }

    // 判断是否存在下一个数
    bool hasNext() {
        return stk.size();
    }
};




// 补充：LC 94 

// 解法一：非递归
// 专门用来解决 树的遍历问题 的非递归写法
// 只要当前节点非空，就将其压入栈，然后向左走，一直这样走，就会走到左下角
// 此时，如果栈不空，就从栈顶弹出左下角的节点，遍历一下这个节点，如果这个节点有右儿子就再向右走
// 下一轮循环时，对右儿子做同样的操作
// 像这种只能解决一类特定问题的代码，要求背下来

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;

        // 当前节点非空 或 栈不空时循环
        while (root != nullptr || !stk.empty()) { 
            // 只要当前节点非空，就压入栈，并一路向左走，直到走到左下角
            while (root != nullptr) { 
                stk.push(root); // 将当前节点入栈
                root = root->left; // 向左遍历
            }

            // 此时，如果栈不空，就从栈顶弹出左下角的节点，加入结果数组，再向右走
            if (stk.top() != nullptr) {
                root = stk.top(); // 将 root 指向左下角节点
                stk.pop(); // 栈顶出栈
                res.push_back(root->val); // 将出栈元素加入结果数组
                root = root->right; // 向右遍历
            }
        }
        return res;
    }
};

