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

// 模拟
// 画图分析
//   p      a    b
// dummy -> 1 -> 2 -> 3 -> 4
// 先将 p->next = b，再将 a->next = b->next，最后将 b->next = a，链表变成：
//   p      b    a
// dummy -> 2 -> 1 -> 3 -> 4
// 再将 p 移动到 a (或后跳 2 步)

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 先建立虚拟头节点
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto p = dummy;

        // 用 p 从虚拟头节点开始遍历链表
        while (p->next != nullptr && p->next->next != nullptr) {
            auto a = p->next; // a 指向要交换的两个节点的第一个节点
            auto b = p->next->next; // b 指向要交换的两个节点的第二个节点
            p->next = b;
            a->next = b->next;
            b->next = a;
            p = a; // p = p->next->next;
        }

        return dummy->next;
    }
};

