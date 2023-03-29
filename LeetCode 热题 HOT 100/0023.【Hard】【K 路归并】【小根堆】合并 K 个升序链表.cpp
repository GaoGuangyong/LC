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

// 本题是 LC 21题 的延伸 --> K 路归并
// 即每次从指向 k 个链表的起始位置的指针中取最小的
// 可以利用 小根堆来实现

// 因为 优先队列中存的是 链表头节点的地址, 我们要比较的是节点的值 而不是 地址
// 所以 要自己定义 cmp 比较 节点的值

class Solution {
public:

    // 定义比较器 cmp，用于在优先队列中排序节点的值
    struct cmp {
        // 重载 "()" 是因为 STL容器 在比较的时候用的是 结构体的小括号运算符
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val; // 小根堆 是 '>'
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 定义小根堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;  

        // 定义虚拟头节点
        auto dummy = new ListNode(-1); 
        auto tail = dummy; // 定义尾节点，初始时指向虚拟头节点

        // 将这 k 个链表的头节点插到堆中
        for (auto l: lists) { // l 指向的就是当前链表的第一个节点
            // 如果 l 指向的非空的话，将 l 指向的节点插入小根堆中
            if (l != nullptr) { // leecode 会放空链表，必须加判断
                heap.push(l);
            }
        }

        // k 路归并
        while (heap.size()) { // 当堆里有元素的时候
            auto t = heap.top(); // 取堆顶元素
            heap.pop(); // 删掉堆顶元素
            tail->next = t; // 将当前节点插到尾节点的后面
            tail = tail->next; // 尾节点向后移动一位
            // 如果 t 所在的那个链表有下一个节点，则将下一个节点插到堆里
            if (t->next != nullptr) {
                heap.push(t->next);
            }
        }
        return dummy->next;
    }
};


// 无注释版本

class Solution {
public:
    // 定义结构体 cmp，重载 "()"
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;

        auto dummy = new ListNode(-1);
        auto tail = dummy;

        // 将这 k 个链表的头节点插到堆中
        for (ListNode* list: lists) {
            if (list != nullptr) heap.push(list);
        }

        // k 路归并
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
