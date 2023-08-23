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

// 相似题目：LC 92 反转链表 II https://leetcode.cn/problems/reverse-linked-list-ii/
// 画图分析，见笔记
// 1. 判断是否还有 k 个节点
// 2.1 局部反转链表
// 2.2 处理局部链表首尾结点处的连接情况
// 2.3 pre 更新为下一段需要局部反转的链表段的前一个节点

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1); // 定义虚拟头节点 dummy
        dummy->next = head;
        ListNode* pre = dummy; // 用 pre 指向需要局部反转的链表段的前一个节点，初始为虚拟头节点 dummy 

        while (pre->next != nullptr) {
            // 1. 判断是否还有 k 个节点（从 pre->next 开始走 k - 1 步，如果走到了空指针，则剩余不足 k 个节点）
            auto p = pre->next;
            for (int i = 0; i < k - 1; i ++ ) { // 移动 k - 1 步
                if (p != nullptr) p = p->next;
            }
            if (p == nullptr) break; // 如果循环结束时，p 指向空指针，则说明不足 k 个，不用反转了

            // 2.1 局部反转链表（从 pre->next 开始的 k 个节点）
            auto a = pre->next;
            auto b = a->next;
            for (int i = 0; i < k - 1; i ++ ) { // 共需要反转 k - 1 条边
                auto c = b->next;
                b->next = a;
                a = b;
                b = c;
            }

            // 2.2 处理局部反转的链表段的首尾节点处的连接情况
            auto t = pre->next; // 用临时节点 t 暂存 pre->next
            pre->next = a;
            t->next = b;

            // 2.3 pre 更新为下一段需要局部反转的链表段的前一个节点
            pre = t; // pre 需要指向 b 之前的结点, b 之前的结点是 head 而不是 a
        }

        return dummy->next;
    }
};


// 框架

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

    // 1. 判断是否还有 k 个节点（从 pre->next 开始走 k - 1 步，如果走到了空指针，则剩余不足 k 个节点）
    
    // 2.1 局部反转链表（从 pre->next 开始的 k 个节点）
    // 2.2 处理局部反转的链表段的首尾节点处的连接情况
    // 2.3 pre 更新为下一段需要局部反转的链表段的前一个节点

    }
};


// 二刷
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;

        while (pre->next != nullptr) {
            auto p = pre->next;
            for (int i = 0; i < k - 1; i ++ ) {
                if (p != nullptr) p = p->next;
            }
            if (p == nullptr) break;

            auto a = pre->next;
            auto b = a->next;
            for (int i = 0; i < k - 1; i ++ ) {
                auto c = b->next;
                b->next = a;
                a = b;
                b = c;
            }

            auto t = pre->next;
            pre->next = a;
            t->next = b;

            pre = t;
        }

        return dummy->next;
    }
};

