/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 双指针技巧中的快慢指针，每当慢指针 slow 前进一步，快指针 fast 就前进两步
// 如果 fast 最终遇到空指针，说明链表中没有环
// 如果 fast 最终和 slow 相遇，那肯定是 fast 超过了 slow 一圈，说明链表中含有环

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针初始时都指向头节点
        ListNode* slow = head;
        ListNode* fast = head;

        // 快指针为空 或 快指针的下一个位置为空时停止
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; // 慢指针每次走 1 步
            fast = fast->next->next; // 快指针每次走 2 步
            // 快慢指针相遇，说明含有环
            if (slow == fast) return true;
        }
        // 否则，不包含环
        return false;
    }
};

// 无注释版本
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) return true;
        }

        return false;
    }
};

