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


// https://www.acwing.com/activity/content/code/content/1652020/
// 给你一个链表数组，每个链表都已经按升序排列。
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。



// 本题是 LC 21题 的延伸 --> K 路归并
// 即每次从指向 k 个链表的起始位置的指针中取最小的
// 可以利用 小根堆来实现

// 注意：小根堆中存的是每个子链表的头节点的地址, 我们要比较的是子链表的头节点的值 而不是地址
// 所以 要自己定义 cmp 结构体 以在 priority_queue 中比较节点的值


class Solution {
public:
    // 定义比较器 cmp，用于在小根堆中排序节点的值
    struct cmp {
        // 重载 "()" 是因为 STL容器 在比较的时候用的是 结构体的小括号运算符
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val; // 小根堆 是 greater，是 '>'
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 定义小根堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;  

        auto dummy = new ListNode(-1); // 定义虚拟头节点
        auto tail = dummy; // 定义尾节点，初始时指向虚拟头节点

        // 遍历这 k 个链表，将第一个节点插到堆中
        for (auto list: lists) { // list 指向的就是当前链表的第一个节点
            // leecode 会放空链表，必须加判断：如果当前链表的第一个节点非空的话，将其插入小根堆中
            if (list != nullptr) heap.push(list);
        }

        // k 路归并
        while (heap.size()) { // 当堆里有元素的时候
            auto t = heap.top(); // 取堆顶元素（值最小的节点）
            heap.pop(); // 将其从堆中删掉

            tail->next = t; // 将当前节点插到尾节点的后面
            tail = tail->next; // 尾节点向后移动一位

            // 如果 t 所在的那个链表有下一个节点，则将下一个节点加入堆中
            if (t->next != nullptr) heap.push(t->next);
        }

        return dummy->next;
    }
};


// 无注释版本

class Solution {
public:
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;

        auto dummy = new ListNode(-1);
        auto tail = dummy;

        for (auto list: lists) {
            if (list != nullptr) heap.push(list);
        }

        while (heap.size()) {
            auto t = heap.top();
            heap.pop();

            tail->next = t;
            tail = tail->next;

            if (t->next != nullptr) heap.push(t->next);
        }

        return dummy->next;
    }
};