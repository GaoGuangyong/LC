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
    // 特判：如果 n < k，则异常，返回空指针
    if (n < k) return nullptr;
    // 从头节点开始向后跳 n - k 步
    ListNode* p = head;
    for (int i = 0; i < n - k; i ++ ) 
        p = p->next;
    return p;
}

int main() {
    int n;
    while (cin >> n) { // 读入多组样例
        // 读入一个数
        int val;
        cin >> val;
        // 将读入的第一个数作为链表的头节点
        ListNode* head = new ListNode(val); 
        ListNode* p = head;
        // 读入 n - 1 个数，作为链表的后续节点
        for (int i = 1; i < n; i ++ ) { 
            cin >> val;
            ListNode* q = new ListNode(val);
            p->next = q;
            p = p->next;
        }
        // 读入 k
        int k;
        cin >> k; 
        // 找到倒数第 k 个节点，输出该节点
        p = FindKthToTail(head, k, n); 
        cout << p->val << endl;
    }
    return 0;
}

