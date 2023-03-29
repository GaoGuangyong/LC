
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

// 解法一：模拟：模拟过程见笔记 
class Solution {
public:
    // dfs 函数：将多级双向链表展平，以数组的形式返回展平后的普通双向链表的 {头结点, 尾节点}
    vector<Node*> dfs(Node* head) {
        // 递归出口：当遍历到了空节点，则返回 空数组
        if (head == nullptr) return {nullptr, nullptr};

        // 定义当前遍历的节点 cur，尾节点 tail，初始时，都指向头节点
        Node* cur = head;
        Node* tail = head;

        while (cur != nullptr) {
            // tail 每次先移动到 cur 
            tail = cur;
            // 如果当前节点有 child 节点，则递归处理
            if (cur->child != nullptr) {
                // 则递归遍历子节点
                vector<Node*> t = dfs(cur->child);
                cur->child = nullptr; // 遍历完子节点后，child 节点要清空
                // 先拼接尾部
                t[1]->next = cur->next;
                if (cur->next != nullptr) cur->next->prev = t[1];
                // 再拼接头部
                t[0]->prev = cur;
                cur->next = t[0];
                // 更新 cur 和 tail
                cur = t[1]->next;
                tail = t[1]; // 注意：尾节点一定要先指向 t[1]，不能指向 cur
            } 
            // 如果当前节点没有 child 节点，则跳过
            else {
                cur = cur->next;
            }
        }

        return {head, tail};
    }

    Node* flatten(Node* head) {
        vector<Node*> res = dfs(head);
        return res[0]; //  res[0] 表示展平后的双向链表的头节点
    }
};


// 无注释版本
class Solution {
public:
    vector<Node*> dfs(Node* head) {
        if (head == nullptr) return {nullptr, nullptr};

        Node* cur = head;
        Node* tail = head;

        while (cur != nullptr) {
            tail = cur;
            if (cur->child != nullptr) {
                auto t = dfs(cur->child);
                cur->child = nullptr;

                t[1]->next = cur->next;
                if (cur->next != nullptr) cur->next->prev = t[1];

                cur->next = t[0];
                t[0]->prev = cur;

                cur = t[1]->next;
                tail = t[1]; 
            } 
            else {
                cur = cur->next;
            }
        }

        return {head, tail};
    }

    Node* flatten(Node* head) {
        auto res = dfs(head);
        return res[0];
    }
};


