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

// 双指针 画图分析
// 用指针 p->next 遍历链表（即 p 指向当前遍历到的节点的前一个节点），对于当前遍历的节点，看后面是否有和它相等的节点

// 定义一个指针 q，初始时指向当前节点 (p->next) 的 next
// 如果当前节点 p->next 和 q 相等，则用 q 指针一直向后遍历，直到找到第一个和 p->next 不同的节点或者遍历到空为止
// 如果此时，当前节点 p->next 的 next 等于 q，则说明当前节点不是重复节点，将 p 向后移动一位
// 如果此时，当前节点 p->next 的 next 不等于 q，则说明当前节点是重复节点，将所有的相同节点删除，方法：p->next 指向 q

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1); // 定义一个虚拟头节点
        dummy->next = head;
        auto p = dummy;

        // 用 p->next 指针遍历链表（关键），这样写就能用 p 表示当前遍历节点的前一个节点
        while (p->next != nullptr) {
            auto q = p->next->next; // 定义 q 指针，初始时指向当前节点（p->next）的 next

            // 当 q 不为空，或 q 的值等于当前节点 p->next，则将 q 向后移动，直到 q 和当前节点的值不同 或 到达空节点
            while (q != nullptr && q->val == p->next->val) q = q->next;

            // 如果此时，当前节点 p->next 的 next 等于 q，则说明当前节点不是重复节点，将 p 向后移动
            if (p->next->next == q) p = p->next;
            
            // 否则，说明当前节点是重复节点，将所有的相同节点删除
            else p->next = q;
            
        }
        return dummy->next; // 返回链表
    }
};

