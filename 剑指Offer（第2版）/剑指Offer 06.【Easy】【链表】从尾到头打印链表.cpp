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
        // 递归遍历下一个节点，相当于当前节点压栈
        dfs(head->next); 
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
        // 辅助栈
        stack<int> stk;

        // 遍历单链表，将所有节点入栈
        ListNode* p = head;
        while (p != nullptr) {
            stk.push(p->val);
            p = p->next;
        }

        // 创建结果数组，将辅助栈中的元素弹出，加入结果数组
        vector<int> res;

        while (stk.size()) {
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};



