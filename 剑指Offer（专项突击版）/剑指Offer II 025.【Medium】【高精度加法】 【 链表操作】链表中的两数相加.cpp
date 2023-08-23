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

// 反转链表 + 高精度加法
// 画图分析，见笔记

class Solution {
public:
    // 辅助函数：反转链表：将链表 head 反转，并返回反转后的头指针
    ListNode* reverseList(ListNode* head) {
        auto a = head;
        auto b = a->next;
        while (b != nullptr) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        head->next = nullptr; // 不要忘记写这个
        return a;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 先将这两个链表反转（注意：别忘记写 l1 = 和 l2 = ）
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        // 新建一个链表头节点，用于指向相加后的链表，初始值设为 -1
        ListNode* dummy = new ListNode(-1);

        int t = 0; // 进位 t

        // 接下来不断采用头插法，从反转后的两个链表的起点开始，不断插入链表头节点 dummy 后面
        while (l1 != nullptr || l2 != nullptr || t != 0 ) {
            // 如果 l1 非空，就把 l1 的值加上
            if (l1 != nullptr) {
                t += l1->val;
                l1 = l1->next;
            }
            // 如果 l2 非空，就把 l1 的值加上
            if (l2 != nullptr ) {
                t += l2->val;
                l2 = l2->next;
            }
            // 此时 t = l1->val + l2->val + t，也就是当前这一位的2个数相加再加上进位的 总和

            // 新建一个节点 node, 当前节点的值就是总和 t % 10 （取个位）
            auto node = new ListNode(t % 10);
            t /= 10; // 当前节点的进位就是总和 t / 10 （取十位）

            // 接下来把 node 节点插到 head 后面（头插法，画图理解）
            node->next = dummy->next;
            dummy->next = node;
        }

        return dummy->next;
    }
};


// 无注释版本
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* dummy = new ListNode(-1);

        int t = 0; 

        while (l1 != nullptr || l2 != nullptr || t != 0) {
            if (l1 != nullptr) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                t += l2->val;
                l2 = l2->next;
            }
            
            ListNode* node = new ListNode(t % 10);
            node->next = dummy->next;
            dummy->next = node;

            t /= 10;
        }

        return dummy->next;
    }
};

