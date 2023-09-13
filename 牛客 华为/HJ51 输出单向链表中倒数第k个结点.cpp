

// 题意：
// 输入一个单向链表，输出该链表中倒数第 k 个结点，链表的倒数第 1 个结点为链表的尾指针

// 输入：
// 8
// 1 2 3 4 5 6 7 8
// 4
// 输出：
// 5


#include <iostream>
using namespace std;

// 链表节点
struct ListNode { 
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} //初始化
};

// 辅助函数：找到长度为 n 的链表 head 的倒数第 k 个节点
ListNode* FindKthToTail(ListNode* head, int k, int n) {
    // 从头节点开始向后跳 n - k 步
    auto p = head;
    for (int i = 0; i < n - k; i ++ ) p = p->next;
    return p;
}

int main() {
    int n;
    while (cin >> n) { // 读入多个空格分开的数字
        // 读入链表中的第一个数
        int val;
        cin >> val;

        // 将读入的第一个数作为链表的头节点
        ListNode* head = new ListNode(val); 

        ListNode* tail = head;
        // 读入 n - 1 个数，作为链表的后续节点
        for (int i = 1; i < n; i ++ ) { 
            cin >> val;
            ListNode* q = new ListNode(val);
            tail->next = q;
            tail = tail->next;
        }

        // 读入 k
        int k;
        cin >> k; 

        // 找到倒数第 k 个节点，输出该节点
        auto res = FindKthToTail(head, k, n); 
        cout << res->val << endl;
    }
    return 0;
}


// 二刷（推荐）
#include <bits/stdc++.h>
using namespace std;

struct ListNode { 
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n;
    while (cin >> n) {
        int val;
        cin >> val;

        auto head = new ListNode(val); 

        auto tail = head;
        
        for (int i = 1; i < n; i ++ ) { 
            cin >> val;
            auto node = new ListNode(val);
            tail->next = node;
            tail = tail->next;
        }

        int k;
        cin >> k; 

        auto p = head;
        for (int i = 0; i < n - k; i ++ ) p = p->next;
        cout << p->val << endl;
    }
    return 0;
}

