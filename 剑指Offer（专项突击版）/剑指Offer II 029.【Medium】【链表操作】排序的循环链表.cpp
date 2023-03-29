/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
/*
  在链表中找到相邻的两个节点，如果这两个节点的前一个节点的值比待插入的值小并且后一个节点的值比待插入的值大
  那么就将新节点插入这两个节点之间
  如果找不到符合条件的两个节点，也就是待插入的值大于链表中已有的最大值或小于已有的最小值
  那么新的节点将被插入值最大的节点和值最小的节点之间
  3 种插入情况：
  (1) cur->val < x < cur->next->val 顺序插入
  (2) 插入点为为序列的边界跳跃点：
    如 3 -> 4 -> 1 插入5，这样 1(cur->next) < 4(cur) < 5(x)，  4 为插入点的前驱节点；这种情况表示 x 比最大值都大
    如 3 -> 4 -> 1 插入0，这样 0(x) < 1(cur->next) < 4(cur)，  4 为插入点的前驱节点；这种情况表示 x 比最小值都小
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

        // 如果不是空链表，新建 cur 指向头节点
        Node* cur = head;

        // 只要还没到链表尾，就循环，寻找待插入的位置
        while (cur->next != head) { 
            // x 是边界点
            if (cur->next->val < cur->val) {
                if (x >= cur->val) break; // 若 x 比最大值都大
                if (x <= cur->next->val) break; // 若 x 比最小值都小
            }
            // x 不是边界点
            if (x >= cur->val && x <= cur->next->val) break;

            cur = cur->next;
        }

        // 将 x 插入到 cur 与 cur->next 之间
        cur->next = new Node(x, cur->next); // 学习这种简洁的写法
        // 相当于以下几行
        // auto t = cur->next;
        // cur->next = new Node(x);
        // cur->next->next = t;
        
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

        Node* cur = head;

        while (cur->next != head) { 
            if (cur->next->val < cur->val) {
                if (x >= cur->val) break;
                if (x <= cur->next->val) break;
            }
            if (x >= cur->val && x <= cur->next->val) break;

            cur = cur->next;
        }

        cur->next = new Node(x, cur->next);
        // 相当于以下几行
        // auto t = cur->next;
        // cur->next = new Node(x);
        // cur->next->next = t;
        
        return head;
    }
};

