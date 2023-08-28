/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // 定义指向链表的指针 p, q 分别指向链表A, B的头节点
        ListNode* p = headA;
        ListNode* q = headB;

        while (p != q) { // 当 p, q 不相遇时循环
            if (p != nullptr) p = p->next; // 若 p 还没走完，就一直往后走
            else p = headB; // 如果 p 走完了，将其指向链表 B 的头节点
            if (q != nullptr) q = q->next; // 若 q 还没走完，就一直往后走
            else q = headA; // 如果 q 走完了，将其指向链表 B 的头节点
        }
        // 当 p, q 相遇时的节点就是相交的那个节点
        return p;
    }
};

// 二刷
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p1 = headA;
        auto p2 = headB;

        while (p1 != p2) {
            if (p1 != nullptr) p1 = p1->next;
            else p1 = headB;
            if (p2 != nullptr) p2 = p2->next;
            else p2 = headA;
        }

        return p1;
    }
};


