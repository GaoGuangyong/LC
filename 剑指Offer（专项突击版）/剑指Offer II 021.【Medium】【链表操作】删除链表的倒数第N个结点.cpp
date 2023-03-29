/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 删除链表的倒数第 k 个节点

// 第一步先要确定要删除的节点是哪一个
// 原链表（长度 n - 1）：         1 -> 2 -> ... -> (n - k - 1) -> (n - k) -> (n - k + 1) -> ... -> (n - 1)
// 加头节点后  (长度 n): dummy -> 1 -> 2 -> ... -> (n - k - 1) -> (n - k) -> (n - k + 1) -> ... -> (n - 1)

// 最后一个节点就是原链表的第 n - 1 个节点，则倒数第 k 个节点就是原链表的第 n - k 个节点
// 要删除原链表第 n - k 个节点，即让原链表的第 (n - k - 1) 个节点的后继指向原链表的第 (n - k + 1) 个节点

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        // 新建虚拟头节点，并将其后继指向头节点
        auto dummy = new ListNode(-1);
        dummy->next = head;

        // 求加虚拟头节点后链表的长度 n
        int n = 0;
        for (auto p = dummy; p != nullptr; p = p->next) n ++ ;

        // p 从虚拟头节点开始，向后跳 n - k - 1 步，就到了原链表的第 n - k - 1 个节点
        auto p = dummy;
        for (int i = 0; i < n - k - 1; i ++ ) p = p->next;

        // 让原链表的第 n - k - 1 个节点的后继指向原链表的第 n - k + 1 个节点
        p->next = p->next->next;

        return dummy->next;
    }
};


// 无注释版本
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        int n = 0; 
        for (auto p = dummy; p != nullptr; p = p->next) n ++ ;

        auto p = dummy;
        for (int i = 0; i < n - k - 1; i ++ ) p = p->next;

        p->next = p->next->next;

        return dummy->next;
    }
};




