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

// 先算一下链表的长度，找出中间节点 mid（第 (n + 1) / 2 个节点），把链表划分成两部分：[0 ~ mid - 1] 和 [mid ~ n - 1]
// 前半部分有 n / 2 个节点，后半部分有 (n / 2) + 1 个节点

// 把后半部分反转一下
// 偶数：1 -> 2 -> 3 -> 4      中间节点 2, 把后半部分反转，变成  1 -> 2 <- 3 <- 4
// 奇数：1 -> 2 -> 3 -> 4 -> 5 中间节点 3, 把后半部分反转，变成  1 -> 2 -> 3 <- 4 <- 5

// 然后搞两个指针，一个指向前一半的起点，一个指向后一半（翻转后）的起点，只要把后面一半的每个结点插入到前面一半的结点和结点之间就可以了
// 偶数：1 -> 2 <- 3 <- 4      【1】把 4 插入 1 后面： 1 -> 4 -> 2 <- 3      【2】把 3 插入 2 后面：1 -> 4 -> 2 -> 3
// 奇数：1 -> 2 -> 3 <- 4 <- 5 【1】把 5 插入 1 后面： 1 -> 5 -> 2 -> 3 <- 4 【2】把 4 插入 2 后面：1 -> 5 -> 2 -> 4 -> 3

// 最后在结尾加上空指针 nullptr
// 偶数：1 -> 4 -> 2 -> 3 -> nullptr
// 奇数：1 -> 5 -> 2 -> 4 -> 3 -> nullptr

class Solution {
public:
    void reorderList(ListNode* head) {
        // if (head == nullptr) return; // 特判空节点（本题不同特判）

        // 计算链表长度
        int n = 0;
        for (auto p = head; p; p = p -> next) n ++ ;

        // 找中间结点 mid（第 (n + 1) / 2 个节点：从头开始，向后跳 (n + 1) / 2 - 1 步
        auto mid = head;
        for (int i = 0; i < (n + 1) / 2 - 1; i ++ ) mid = mid -> next;

        // 反转后半部分 [mid ~ n - 1] 链表（节点数：(n / 2) + 1 ）
        auto a = mid;
        auto b = a->next;
        for (int i = 0; i < n / 2; i ++ ) { // 一共需要反转 [(n / 2) + 1] - 1 = n / 2 次
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        } // 反转结束后，a 指向原链表的最后一个节点，即反转后的链表的第一个结点

        // 将翻转后的部分按顺序一个一个插入到左边的链表的每两个结点之间
        auto l = head; // 指针 l 指向的前半部分的起点
        auto r = a;  // 指针 r 指向的后半部分的起点

        for (int i = 0; i < n / 2; i ++ ) {
            // 先用指针 o 记录下 r 的后继
            auto o = r -> next;

            // 将 r 插入 l 后面
            r->next = l->next;
            l->next = r;

            // l 和 r 都指向下一个节点
            l = r->next;
            r = o;
        }

        // 如果链表的长度是奇数，则 mid 是最后一个节点，将其后继变为 nullptr
        if (n & 1)
            mid->next = nullptr;
        // 如果链表的长度是偶数，则 mid 是倒数第二个节点，将其后继的后继变为 nullptr
        else
            mid->next->next = nullptr;
    }
};


// 无注释版本

class Solution {
public:
    void reorderList(ListNode* head) {
        int n = 0;
        for (auto p = head; p != nullptr; p = p->next) n ++ ;

        auto mid = head;
        for (int i = 0; i < (n + 1) / 2 - 1; i ++) mid = mid->next;

        auto a = mid;
        auto b = a->next;
        for (int i = 0; i < n / 2; i ++ ) { 
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }

        auto l = head; 
        auto r = a;

        for (int i = 0; i < n / 2; i ++ ) {
            auto t = r->next;

            r->next = l->next;
            l->next = r;

            l = r->next;
            r = t;
        }

        if (n % 2 == 1) mid->next = nullptr;
        else mid->next->next = nullptr;
    }
};
