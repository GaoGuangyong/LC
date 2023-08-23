/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// https://leetcode.cn/problems/copy-list-with-random-pointer/solution/fu-zhi-dai-sui-ji-zhi-zhen-de-lian-biao-c2nvs/ 看思路一


// 题目翻译：
// 给定一个单链表，链表中的每个节点包含一个额外的指针，随机指向链表中的其它节点或者指向 null；
// 请复制整个链表，并返回新链表的头节点

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // I、遍历原链表，在每个节点 p 后面插入一个复制的节点 q，并将原链表和复制链表连在一起，得到新链表
        for (auto p = head; p != nullptr; p = p->next->next) {
            auto q = new Node(p->val); // 新建节点 q，复制节点 p 的值
            q->next = p->next;
            p->next = q;
        }

        // II、遍历新链表，复制 random 指针
        // 从前往后遍历新链表，对于原链表中的节点 p（有 random 指针的节点），让它的 p->next->random = p->random->next
        for (auto p = head; p != nullptr; p = p->next->next) {
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
        }

        // III、拆分两个链表：断开新链表的所有 next 指针，恢复原链表的 next 指针 和 复制链表的 next 指针

        // 定义虚拟头节点 dummy 用来指向复制链表的头节点
        auto dummy = new Node(-1);

        // 遍历新链表，用 p 恢复原链表的 next 指针，用 q 恢复复制链表的 next 指针
        auto p = head;
        auto q = dummy;
        while (p != nullptr) {
            // 构建复制链表的 next 指针
            q->next = p->next; 
            q = q->next;
            // 构建原链表的 next 指针
            p->next = q->next; 
            p = p->next;
        }

        return dummy->next;
    }
};


// 无注释版本
class Solution {
public:
    Node* copyRandomList(Node* head) {
        for (auto p = head; p != nullptr; p = p->next->next) {
           auto q = new Node(p->val);
            q->next = p->next;
            p->next = q;
        }

        for (auto p = head; p != nullptr; p = p->next->next) {
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
        }

        auto dummy = new Node(-1);

        auto p = head;
        auto q = dummy;

        while (p != nullptr) {
            q->next = p->next; 
            q = q->next;
            
            p->next = q->next; 
            p = p->next;
        }

        return dummy->next;
    }
};


