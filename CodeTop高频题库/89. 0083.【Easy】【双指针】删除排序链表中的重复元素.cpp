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

// 遍历，双指针
// 定义 tail 指针，指向当前（删除重复元素后）链表的最后一个节点，链表的第一个节点 head 一定保留，所以初始时 tail 指向 head
// 定义 p 指针从链表的第二个节点 head->next 开始遍历
// 如果 p 指针指向的节点的数和 tail 不同，说明是这个数的第一次出现，故保留（接到 tail 后面）
// 否则，说明这个数前面已经出现过了，跳过

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head; // 特判：空链表
        auto tail = head; // 定义 tail 指针，指向当前（删除重复元素后）链表的最后一个节点
        auto p = head->next; // 定义 p 指针，从链表的第二个节点开始遍历

        while (p != nullptr) {
            if (p->val != tail->val) { // 如果 p 指针指向的节点的数和 tail 不同，说明是这个数的第一次出现，故保留（接到 tail 后面）
                tail->next = p;
                tail = tail->next; // 更新当前的最后一个节点
            }
            p = p->next;
        }

        tail->next = nullptr; // 最后，在链表最后补上空节点
        
        return head;
    }
};

