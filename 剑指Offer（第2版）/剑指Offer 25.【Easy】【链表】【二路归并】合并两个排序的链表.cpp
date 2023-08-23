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


// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的

// 思想：二路归并

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 定义一个虚拟头节点
        auto dummy = new ListNode(-1);
        auto tail = dummy; // 定义一个尾节点，初始时指向虚拟头节点

        // 当链表 l1 与 l2 都 不为空时循环
        while (l1 != nullptr && l2 != nullptr) { 
            // 若 l1 的值 < l2 的值
            if (l1->val < l2->val) {
                tail->next = l1; // 将 l1 加入 结果链表
                tail = l1; // tail 指针指向 l1（即向后移动一位）
                l1 = l1->next; // l1 指向它的下一个节点
            }
            // 若 l2 的值 <= l1 的值
            else {
                tail->next = l2; // 将 l2 加入 结果链表
                tail = l2; // tail 指针指向 l2（即向后移动一位）
                l2 = l2->next; // l2 指向它的下一个节点
            }
        }

        // 循环结束后，一定有一个链表还没处理完
        if (l1 != nullptr) tail->next = l1; // 若 l1 没处理完，则将 l1 的剩余部分接到后面
        if (l2 != nullptr) tail->next = l2; // 若 l2 没处理完，则将 l2 的剩余部分接到后面

        return dummy->next; // 返回结果链表（即虚拟头节点的下一个节点）
    }
};


// 无注释版本
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto tail = dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }

            else if (l2->val <= l1->val) {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }

        
        if (l1 != nullptr) tail->next = l1;
        if (l2 != nullptr) tail->next = l2;

        return dummy->next;
    }
};