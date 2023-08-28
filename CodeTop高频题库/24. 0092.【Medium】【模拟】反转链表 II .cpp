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

// 画图分析，见笔记
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(-1); // 定义虚拟头节点 dummy
        dummy->next = head;

        // 先让 pre 指向要反转的链表段的起始节点的前一个节点
        auto pre = dummy;
        for (int i = 0; i < left - 1; i ++ ) { // 需要跳 left - 1 步
            pre = pre->next;
        }
        // 局部反转链表
        auto a = pre->next; // a 指向要反转的链表段的起始节点
        auto b = a->next;
        for (int i = 0; i < right - left; i ++ ) { // 一共需要翻转 right - left 条边
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        } // 反转结束后，a 指向 right，b 指向 a->next

        // 处理局部反转的链表段的首尾节点处的连接情况
        pre->next->next = b;
        pre->next = a;

        return dummy->next;
    }
};

// 二刷
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto pre = dummy;

        for (int i = 0; i < left - 1; i ++ ) pre = pre->next;

        auto a = pre->next;
        auto b = a->next;
        for (int i = 0; i < right - left; i ++ ) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }

        pre->next->next = b;
        pre->next = a;
    
        return dummy->next;
    }
};
