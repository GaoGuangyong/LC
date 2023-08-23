/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 统计一共有多少个节点
        int n = 0;
        for (auto p = head; p != nullptr; p = p->next) n ++ ;
        
        // 从头开始向后跳 n - k 步，即可到达倒数第 k 个节点
        auto p = head;
        for (int i = 0; i < n - k; i ++ ) p = p->next;
    
        return p;
    }
};


// 无注释版本
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p != nullptr; p = p->next) n ++ ;
       
        auto p = head;
        for (int i = 0; i < n - k; i ++ ) p = p->next;
        
        return p;
    }
};


// 解法二：双指针（推荐）
// 先让 q 遍历 k 个结点，然后和 p 同时向后遍历，当 q 到达尾结点时 p 即为倒数第 k 个结点
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* q = head;
        for (int i = 0; i < k; i ++ ) {
            q = q->next;
        }
        while (q != nullptr) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};



