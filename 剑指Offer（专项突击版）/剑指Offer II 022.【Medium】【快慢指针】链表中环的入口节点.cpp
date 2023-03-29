/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 基于 141. 环形链表 的解法，当快慢指针相遇时，让其中任一个指针指向头节点，然后让它俩以相同速度前进，再次相遇时所在的节点位置就是环开始的位置。

/* LC 141
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
*/

class Solution {
public:
    ListNode *detectCycle(ListNode* head) {
        // 初始时，快指针和慢指针都指向链表头
        ListNode* slow = head;
        ListNode* fast = head; 

        // 判断是否存在环路
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; // 慢指针每次走 1 步
            fast = fast->next->next; // 快指针每次走 2 步
            
            // 如果快慢指针相遇，说明有环，退出循环
            if (fast == slow) break;
        }

        // 如果退出循环时，fast 为空或 fast 的下一个节点为空，说明没有环
        if (fast == nullptr || fast->next == nullptr) return NULL;
        
        // 如果存在环路，查找环路起点
        fast = head; // 当第一次相遇时，令快指针重新指向链表头

        // 当快慢指针不重合时循环，第二次相遇时循环结束   
        while (fast != slow) { 
            fast = fast->next; // 快指针每次走 1 步
            slow = slow->next; // 慢指针每次走 1 步
        }

        return fast; // 当第二次相遇时，快慢指针相遇的位置即是环路的起点
    }
};


// 无注释版本
class Solution {
public:
    ListNode *detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head; 

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) break;
        }

        if (fast == nullptr || fast->next == nullptr) return NULL;

        fast = head;
        while (fast != slow) { 
            fast = fast->next;
            slow = slow->next;
        } 

        return fast;
    }
};
