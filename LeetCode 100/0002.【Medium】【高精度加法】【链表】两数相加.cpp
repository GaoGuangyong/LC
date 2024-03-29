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

// 类似 剑指 Offer II 025
// 画图分析，见笔记


// 反转链表 + 高精度加法

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1); // 定义虚拟头结点
        auto tail = dummy; // 定义尾节点，初始时指向虚拟头节点

        int t = 0; // 进位 t

        while (l1 != nullptr || l2 != nullptr || t != 0 ) {
            // 如果 l1 非空，就把 l1 的值加上
            if (l1 != nullptr) {
                t += l1->val;
                l1 = l1->next;
            }
            // 如果 l2 非空，就把 l2 的值加上
            if (l2 != nullptr) {
                t += l2->val;
                l2 = l2->next;
            }
            // 此时 t = l1->val + l2->val + t，也就是当前这一位的 2 个数相加再加上进位的 总和

            // 将当前节点的值 t % 10 插到链表尾节点后面
            tail->next = new ListNode(t % 10);
            tail = tail->next;

            t /= 10; // 更新进位：t / 10
        }

        return dummy->next;
    }
};


// 无注释版本
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

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

            tail->next = new ListNode(t % 10);
            tail = tail->next;
            t /= 10;
        }

        return dummy->next;
    }
};

