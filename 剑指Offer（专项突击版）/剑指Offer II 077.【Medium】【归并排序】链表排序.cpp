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

// 过程见笔记
// 采用迭代的方式进行归并排序
// i 从 1 开始，每次 i *= 2
// 第 i 次迭代，将 2 个长度是 i 的区间合并成长度是 2i 的区间 
// 当 i = n / 2 时，将 2 个长度是 n / 2 的区间合并成长度是 n 的区间，此时排序就完成了

// 在上一步迭代后，即 i = n 时，代表所有节点均已归并完毕
// 采用双层循环来实现，要明白第 1 层 for 循环和第 2 层 for 循环的含义
// 第 1 层 for 循环是纵向层与层之间自下向上迭代
// 第 2 个 for 循环是横向每层从左往右每次遍历长度 2*i 的区间
// 在遍历每层的 [j ~ j + i - 1] 和 [j + i ~ j + 2*i - 1] 这两个区间时
// first 表示第一个区间的起始点，second 表示第二个区间的起始点，cur 是上一个排好序的 2*i 长度区间的尾结点，之后开始归并即可
// j 表示当前一段的开始，j + i 表示下一段的开始。每次将这两个有序段归并为一个大的有序段，故而每次 +2i

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 求链表长度 n
        int n = 0;
        for (auto p = head; p; p = p->next) n ++;

        // 定义一个虚拟头节点， 因为 head 可能会变（ 由于原始的 head->val 可能不是最小的，就会被移到后面）
        auto dummy = new ListNode(-1);
        dummy->next = head;

        // 第 1 层 for 循环是纵向层与层之间自下向上迭代，第 2 个 for 循环是横向每层从左往右每次遍历长度 2i 的区间
        for (int i = 1; i < n; i *= 2 ) {
            // 因为每一层第一段头结点是从第一个结点 head 开始的，而这个第一个结点 head 是可能会变的
            // 要保证 first 指向第一段的头节点, 所以 cur = dummy, 因为这样一来，在第 2 层循环中 first = cur->next = dummy->next = head
            auto cur = dummy;
            // 每次枚举相邻的两个区间 [j ~ j + i - 1] 和 [j + i ~ j + 2*i - 1]
            for (int j = 0; j + i < n; j += 2 * i) { // 链表头结点索引当成 0，所以 j = 0 开始
                auto first = cur->next; // 注意：不能写 first = head, 因为这个起点会变
                auto second = first;
                // second 向后跳 i 步，指向第二个区间的起始点
                for (int k = 0; k < i; k ++) second = second->next;

                // 归并排序过程 (注意：因为是链表，所以写法不同于数组的归并)
                int l = 0, r = 0; // l, r 用于计数第一段和第二段归并的节点个数
                while (l < i && r < i && second) {  // && second 是因为长为 2i 的段的第 2 段可能不满 i, 第 1 段肯定长度为 i, 所以不 && first
                    // 如果第一段的当前节点小于第二段的当前节点, 则将小的节点（first）插入 cur 链表中
                    if (first->val <= second->val) { 
                        cur->next = first;
                        cur = cur->next;
                        first = first->next;
                        l ++ ;
                    }
                    // 如果第二段的当前节点小于第一段的当前节点, 则将小的节点（second）插入 cur 链表中
                    else { 
                        cur->next = second;
                        cur = cur->next;
                        second = second->next;
                        r ++ ;
                    }
                }
                // 如果第一个链表还有剩余，则把剩余部分放到 cur 链表后面
                while (l < i && first) {
                    cur->next = first;
                    cur = cur->next;
                    first = first->next;
                    l ++ ;
                }
                // 如果第二个链表还有剩余，则把剩余部分放到 cur 链表后面
                while (r < i && second) {
                    cur->next = second;
                    cur = cur->next;
                    second = second->next;
                    r ++ ;
                }
                // 把当前层已经归并好的 2i 段 的链表尾 链接到 当前层 下一段 2i 段的链表头 （即满足：cur是上一个排好序的2i链表段的尾结点）
                cur->next = second;
                // 跳出循环时，second已经是 j + 2i，即下一个 2i 链表段的新的头结点
            }
        } 
        return dummy->next; // 返回 head
    }
};


// 简单注释版本
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 求链表长度 n
        int n = 0;
        for (auto p = head; p; p = p->next) n ++;
        
        // 定义一个虚拟头节点
        auto dummy = new ListNode(-1);
        dummy->next = head;

        // 第 1 层 for 循环是纵向层与层之间自下向上迭代
        for (int i = 1; i < n; i *= 2 ) {
            // 要保证 first 指向第一段的头节点, 所以 cur = dummy
            auto cur = dummy;
            // 第 2 个 for 循环是横向每层从左往右每次遍历长度 2i 的区间
            for (int j = 0; j + i < n; j += 2 * i) { 
                // first 指向第一个区间的起始点
                auto first = cur->next; 
                // second 向后跳 i 步，指向第二个区间的起始点
                auto second = first;
                for (int k = 0; k < i; k ++) second = second->next;

                // 归并排序过程 
                int l = 0;
                int r = 0;
                while (l < i && r < i && first != nullptr && second != nullptr) {
                    // 如果第一段的当前节点 <= 第二段的当前节点, 则将小的节点（first）插入 cur 链表中
                    if (first->val <= second->val) {
                        cur->next = first;
                        cur = cur->next;
                        first = first->next;
                        l ++ ;
                    }
                    // 如果第二段的当前节点 < 第一段的当前节点, 则将小的节点（second）插入 cur 链表中
                    else {
                        cur->next = second;
                        cur = cur->next;
                        second = second->next;
                        r ++ ;
                    }
                }
                // 如果第一个链表还有剩余，则把剩余部分放到 cur 链表后面
                while (l < i && first != nullptr) {
                    cur->next = first;
                    cur = cur->next;
                    first = first->next;
                    l ++ ;
                }
                // 如果第二个链表还有剩余，则把剩余部分放到 cur 链表后面
                while (r < i && second != nullptr) {
                    cur->next = second;
                    cur = cur->next;
                    second = second->next;
                    r ++ ;
                }

                // 返回 head
                cur->next = second;
            }
        } 
        return dummy->next;
    }
};

