
/*
  在链表中找到相邻的两个节点，如果这两个节点的前一个节点的值比待插入的值小并且后一个节点的值比待插入的值大
  那么就将新节点插入这两个节点之间
  如果找不到符合条件的两个节点，也就是待插入的值大于链表中已有的最大值或小于已有的最小值
  那么新的节点将被插入值最大的节点和值最小的节点之间

  三种情况
  1、p < x < p->next ：如 1 -> 3 -> 4 插入 2，得到 1 -> (2) -> 3 -> 4 
  2、p->next < p < x ：如 1 -> 3 -> 4 插入 5，得到 1 -> 3 -> 4 -> (5)，即 x 比最大值都大
  3、x < p->next < p ：如 1 -> 3 -> 4 插入 0，得到 (0) -> 1 -> 3 -> 4，即 x 比最小值都小

*/

class Solution {
public:
    Node* insert(Node* head, int x) {
        // 特判：如果是空链表，插入后只有 x
        if (head == nullptr) {
            head = new Node(x);
            head->next = head;
            return head;
        }

        // 如果不是空链表，新建 p 指向头节点
        auto p = head;

        // 只要还没到链表尾，就循环，寻找待插入的位置
        while (p->next != head) {                    // !!!!!!! 注意循环链表的终止条件
            // 如果遍历到了边界，则判断 x 是不是边界点
            if (p->next->val < p->val) {
                if (x >= p->val) break; // 若 x 比最大值都大
                if (x <= p->next->val) break; // 若 x 比最小值都小
            }
            // 否则，如果 x ∈ [p->val, p->next->val]
            if (x >= p->val && x <= p->next->val) break;

            p = p->next;
        }

        // 将 x 插入到 p 与 p->next 之间
        p->next = new Node(x, p->next); // 学习这种简洁的写法
        // 相当于以下几行
        // auto t = p->next;
        // p->next = new Node(x);
        // p->next->next = t;
        
        return head;
    }
};


// 无注释版本
class Solution {
public:
    Node* insert(Node* head, int x) {
        if (head == nullptr) {
            head = new Node(x);
            head->next = head;
            return head;
        }

        Node* p = head;

        while (p->next != head) { 
            if (p->next->val < p->val) {
                if (x >= p->val) break;
                if (x <= p->next->val) break;
            }
            if (x >= p->val && x <= p->next->val) break;

            p = p->next;
        }

        p->next = new Node(x, p->next);
        // 相当于以下几行
        // auto t = p->next;
        // p->next = new Node(x);
        // p->next->next = t;
        
        return head;
    }
};

// 二刷
class Solution {
public:
    Node* insert(Node* head, int x) {
        if (head == nullptr) {
            auto head = new Node(x);
            head->next = head;
            return head;
        }

        auto p = head;
        while (p->next != head) {
            if (p->val > p->next->val) {
                if (x >= p->val) break;
                if (x <= p->next->val) break;
            }
            if (x >= p->val && x <= p->next->val) break;
            p = p->next;
        }

        auto t = new Node(x);
        t->next = p->next;
        p->next = t;
        
        return head;
    }
};
