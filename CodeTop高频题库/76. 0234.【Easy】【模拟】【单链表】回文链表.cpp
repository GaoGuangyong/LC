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
 // 思路：
 // 原链表：1 -> 2-> 3-> 4 -> 3 -> 2 -> 1
 // 先算一下链表的长度，找出中间节点 mid（第 (n + 1) / 2 个节点），把链表划分成两部分：[0 ~ mid - 1] 和 [mid ~ n - 1] 前半部分有 n / 2 个节点，后半部分有 (n / 2) + 1 个节点                    |     
 // 【1】求链表中的节点数量 n = 7 和 中点 mid = (n + 1) / 2 = 4
 // 【2】把后半部分的节点反转过来，1 -> 2-> 3-> 4 <- 3 <- 2 <- 1，
 // 【3】用两个指针，一个从前往后，一个从后往前，判断各个节点知否相同
 // 【4】将链表恢复原状（不知道为何，不恢复链表不 AC）

// 空间复杂度 O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 特判，如果是空节点 或 只有 1 个节点，则是回文链表
        if (head == nullptr || head->next == nullptr) return true;

        // 先求链表中的节点数量
        int n = 0;
        for (auto p = head; p != nullptr; p = p->next) n ++; 
        
        // 找中间结点 mid（第 (n + 1) / 2 个节点）
        auto mid = head;
        for (int i = 0; i < (n + 1) / 2 - 1; i ++ ) // 从头开始，向后跳 (n + 1) / 2 - 1 步
            mid = mid -> next;

        // 反转后半部分 [mid ~ n - 1] 的链表，节点数 (n / 2) + 1，共需反转 (n / 2) 次
        auto a = mid;
        auto b = a->next;
        for (int i = 0; i < n / 2; i ++ ) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        } // 反转结束后，a 指向原链表的最后一个节点，即反转后的链表的第一个结点

        // 判断是否回文
        bool res = true; // 默认是回文链表
        auto l = head; // 指针 l 指向的前半部分的起点
        auto r = a;  // 指针 r 指向的后半部分的起点
        for (int i = 0; i < n / 2; i ++ ) {
            // 如果前后两个节点的值不一样，就不是回文链表
            if (l->val != r->val){ 
                res = false;
                break;
            }
            // 否则，l，r 继续指向下一个节点
            l = l->next;
            r = r->next;
        }

        // 恢复链表，即将上面的翻转后半部分链表从后向前再翻转一遍
        auto tail = a; // 记录尾结点，最后恢复链表需要 tail->next 指向 nullptr
        b = a->next; // 注意，此时，a 指向的是原链表最后一个节点 1，令 b 指向 a 前面的节点 2
        for (int i = 0; i < n / 2; i ++ ) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        tail->next = nullptr; // 最后 再令恢复后的链表的尾节点的 next 为空

        return res;
    }
};

// 无注释版本
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        int n = 0;
        for (auto p = head; p != nullptr; p = p->next) 
            n ++ ;

        auto mid = head;
        for (int i = 0; i < (n + 1) / 2 - 1; i ++ )
            mid = mid->next;

        auto a = mid;
        auto b = a->next;
        for (int i = 0; i < n / 2; i ++ ) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }

        bool res = true;
        auto l = head;
        auto r = a;
        for (int i = 0; i < n / 2; i ++ ) {
            if (l->val != r->val) {
                res = false;
                break;
            }
            l = l->next;
            r = r->next;
        }

        auto tail = a;
        b = a->next;
        for (int i = 0; i < n / 2; i ++ ) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        tail->next = nullptr;

        return res;
    }
};



// 笔试时，采用下述解法
// 空间复杂度 O(n)
// 先复制链表值到数组列表中，再使用双指针法判断是否为回文

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 特判，如果是空节点 或 只有 1 个节点，则是回文链表
        if (head->next == nullptr) return true;
        vector<int> nums;
        
        // 用 p 遍历链表，将链表节点的值复制到 nums 数组中
        auto p = head;
        while (p != nullptr) {
            nums.push_back(p->val);
            p = p->next;
        }
        
        // 使用双指针法判断是否为回文
        int n = nums.size();
        for (int i = 0, j = n - 1; i < j; i ++ , j -- ) {
            if (nums[i] != nums[j]) return false;
        }

        return true;
    }
};


// 二刷
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) return true;

        vector<int> nums;
        auto p = head;
        while (p != nullptr) {
            nums.push_back(p->val);
            p = p->next;
        }

        for (int i =  0, j = nums.size() - 1; i < j; i ++ , j -- ) {
            if (nums[i] != nums[j]) return false;
        }

        return true;
    }
};

