/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 解法一：DFS 递归
 
class Solution {
public:
    // 全局变量
    vector<int> res;

    void dfs(ListNode* head) {
        // 递归出口：如果遍历到空节点，则结束遍历，返回
        if (head == nullptr) return;
        
        dfs(head->next); // 递归遍历下一个节点，相当于当前节点压栈
        res.push_back(head->val); // 当所有节点都压栈后，从栈顶开始一个一个加入数组尾部
    }

    vector<int> reversePrint(ListNode* head) {
        dfs(head);
        return res;
    }
};


// 解法二：栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        
        stack<int> stk; // 辅助栈

        // 遍历单链表，将所有节点入栈
        for (ListNode* p = head; p != nullptr; p = p->next) {
            stk.push(p->val);
        }

        vector<int> res;

        while (stk.size()) {
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};



