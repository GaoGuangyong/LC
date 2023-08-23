/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 模板题：迭代
// 画图理解

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 特判空链表
        if (head == nullptr) return nullptr;
        
        auto a = head; // 当前节点
        auto b = a->next; // 当前节点的后继
        while (b != nullptr) {
            auto c = b->next;
            b->next = a; // 反转的操作只有这一步
            a = b;
            b = c;
        }
        head->next = nullptr;

        return a;
    }
};

// 二刷（结构体也要自己会写）

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        auto a = head;
        auto b = a->next;

        while (b != nullptr) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }

        head->next = nullptr;

        return a;
    }
};


// 解法二：递归
// 先考虑 reverseList 函数能做什么，它可以翻转一个链表，并返回新链表的头节点，也就是原链表的尾节点。
// 我们可以先递归处理 reverseList(head->next)，这样我们可以将以head->next为头节点的链表翻转，并得到原链表的尾节点tail
// 此时head->next是新链表的尾节点，我们令它的next指针指向head，并将head->next指向空即可将整个链表翻转，且新链表的头节点是tail。

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 特判
        if (!head || !head->next) return head;
        
        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};
