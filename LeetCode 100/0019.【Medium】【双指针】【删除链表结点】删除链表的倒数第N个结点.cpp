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


// 解法二：双指针（推荐）

// 设置虚拟节点 dummy 指向 head
// 设定双指针 p 和 q，初始都指向虚拟头节点 dummy
// 移动 q，直到 p 与 q 之间相隔的元素个数为 n
// 同时移动 p 与 q，直到 q 指向的为 nullptr
// 将 p 的下一个节点指向下下个节点

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto p = dummy;
        auto q = dummy;

        // 让 q 先移动 n + 1 步，使 p 与 q 之间的元素个数为 n
        for (int i = 0 ; i < n + 1 ; i ++ ) q = q->next;
        
        // 同时移动 p 与 q，直到 q 指向的为 nullptr，此时 p 指向的就是倒数第 n 个节点的前一个节点
        while (q != nullptr) {
            p = p->next;
            q = q->next;
        }

        // 删除 p->next 节点
        p->next = p->next->next;

        return dummy->next;
    }
};



// 无注释版
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto p = dummy;
        auto q = dummy;

        for (int i = 0; i < n + 1; i ++ ) q = q->next;

        while (q != nullptr) {
            p = p->next;
            q = q->next;
        }

        p->next = p->next->next;

        return dummy->next;
    }
};
