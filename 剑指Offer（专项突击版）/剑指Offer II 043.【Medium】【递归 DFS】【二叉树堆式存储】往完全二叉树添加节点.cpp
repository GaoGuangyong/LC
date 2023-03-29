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

// 完全二叉树的堆式存储

// 堆的性质（以小根堆为例）：
// 1、堆是一棵完全二叉树：根节点为编号 1 的节点，编号 x 的节点的左儿子的编号为 2x，右儿子的编号为 2x + 1
// 2、递归定义：二叉树中的每个节点都 < 其左右儿子，即根节点为整个二叉树的最小值

// 堆的存储
// 使用一维数组（下标从 1 开始）存堆中的编号 1 ~ size 的节点
// vector<TreeNode*> heap; 

// 手写堆：将完全二叉树存到一维数组中；根节点是 1，根节点的左右儿子是 2 和 3，以此类推
// 首先用层序遍历二叉树，然后将其存入下标从 1 开始的数组，找父节点的时候直接将其下标除以 2 即可

class CBTInserter {
public:
    // 全局变量
    TreeNode* root; // 定义根节点 root
    vector<TreeNode*> heap; // 利用一个一维数组来模拟堆，存完全二叉树的节点

    // 函数含义：给定根节点 root，初始化一个堆
    CBTInserter(TreeNode* _root) {
        root = _root;    
        heap.push_back(0); // 堆存储二叉树是从 1 开始 前面补个 0 占位
        
        // 用 bfs 方式遍历完全二叉树，将所有节点存到堆里
        queue<TreeNode*> q; // BFS 队列
        q.push(root); // 根节点入队

        while (q.size()) { // 当队列不空的时候
            auto t = q.front(); // 取队头 t
            q.pop(); // 队头出队
            heap.push_back(t); // 将队头插入堆里
            if (t->left != nullptr) q.push(t->left); // 如果存在左儿子，就将左儿子存到堆里
            if (t->right != nullptr) q.push(t->right); // 如果存在右儿子，就将右儿子存到堆里
        }
    }

    // 函数含义：将 v 插入完全二叉树中，返回 v 的父节点的值
    int insert(int v) {
        TreeNode* t = new TreeNode(v); // 创建当前节点，值为要插入的数

        heap.push_back(t); // 将当前节点插入堆中
        int k = heap.size() - 1; // 当前节点的下标 k
        int p = k / 2; // 当前节点的父亲节点的下标

        // 如果 k = 2p，则当前节点为左儿子
        if (p * 2 == k) heap[p]->left = t;
        // 如果 k = 2p + 1，则当前节点为右儿子
        else if (p * 2 + 1 == k) heap[p]->right = t;
        
        // 返回插入节点的父节点的值
        return heap[p]->val;
    }

    TreeNode* get_root() {
        return root;
    }
};


// 无注释版本
class CBTInserter {
public:
    // 全局变量
    TreeNode* root; 
    vector<TreeNode*> heap;

    // 函数含义：给定根节点 root，初始化一个堆
    CBTInserter(TreeNode* _root) {
        root = _root;    
        heap.push_back(0); 
        
        queue<TreeNode*> q;
        q.push(root); 

        while (q.size()) { 
            auto t = q.front();
            q.pop(); 
            heap.push_back(t); 
            if (t->left != nullptr) q.push(t->left); 
            if (t->right != nullptr) q.push(t->right); 
        }
    }

    // 函数含义：将 v 插入完全二叉树中，返回 v 的父节点的值
    int insert(int v) {
        TreeNode* t = new TreeNode(v); 

        heap.push_back(t); 
        int k = heap.size() - 1; 
        int p = k / 2; 

        if (p * 2 == k) heap[p]->left = t;
        else if (p * 2 + 1 == k) heap[p]->right = t;
        
        return heap[p]->val;
    }

    TreeNode* get_root() {
        return root;
    }
};

