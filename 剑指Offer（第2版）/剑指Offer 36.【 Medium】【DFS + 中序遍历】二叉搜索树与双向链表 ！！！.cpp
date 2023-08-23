/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

// DFS 中序遍历

// left: 指向双向链表的前驱节点
// right: 指向双向链表的后继节点

class Solution {
public:
    // 全局变量
    Node* head; // 双向链表的头结点
    Node* prev; // 对于当前遍历的节点来说，prev 就是其前驱节点，也是最后一次指向的节点

    // DFS 函数：从节点 root 开始采用【中序遍历】的方法遍历二叉搜索树，并在遍历过程中实现 right 和 left 指针
    void dfs(Node* root) {
        // 递归出口：当遍历到空节点时，遍历结束，返回
        if (root == nullptr) return;

        // 【1】递归遍历左子树
        dfs(root->left);

        // 【2】遍历当前节点
        // 如果头节点为空，则 root 就是第一个要处理的节点
        if (head == nullptr) head = root;
        
        // 如果 prev 节点不为空，即当前处理的不是第一个节点
        if (prev != nullptr) {
            prev->right = root; // 将 prev 的后继指向当前节点
            root->left = prev;
        }

        // 将 prev 指向当前节点
        prev = root;

        //【3】递归遍历右子树
        dfs(root->right);
    }

    // 主函数：将二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
    Node* treeToDoublyList(Node* root) {
        // 特判：如果是空树，则返回空指针
        if (root == nullptr) return nullptr;

        // 初始化双向链表的 头节点 与 前驱节点
        head = nullptr;
        prev = nullptr;

        dfs(root); // 从根节点开始遍历

        // 递归遍历结束后，处理首位节点，即将二者相连
        head->left = prev;
        prev->right = head;

        return head;

    }
};


// 无注释版本
class Solution {
public:
    Node* head; 
    Node* prev; 

    void dfs(Node* root) {
        if (root == nullptr) return;

        dfs(root->left);

        if (head == nullptr) head = root;
        if (prev != nullptr) {
            prev->right = root; 
            root->left = prev;
        }
        prev = root;

        dfs(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;

        head = nullptr;
        prev = nullptr;

        dfs(root); 

        head->left = prev;
        prev->right = head;

        return head;

    }
};

