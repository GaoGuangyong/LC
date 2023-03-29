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
    ListNode* deleteNode(ListNode* head, int val) {
        // 特判：如果头节点是要删除的节点，则直接返回头结点的下一个节点
        if (head->val == val) return head->next;

        // 用指针 p 用来遍历链表：当下一个节点不空 且 不是要删除的节点，就一直向后遍历
        ListNode* p = head; 
        while (p->next != nullptr && p->next->val != val) {
            p = p->next;
        } // 循环结束时，p 指向的就是要删除的节点的前一个节点 或 最后一个节点

        // 删除 p->next 节点
        p->next = p->next->next;

        return head;
    }
};


// 无注释版本
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) return head->next;

        ListNode* p = head; 
        while (p->next != nullptr && p->next->val != val) {
            p = p->next;
        }

        p->next = p->next->next;
        
        return head;
    }
};
