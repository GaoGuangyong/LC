
// 思路：
// 定义两个栈 a 和 b --> a 存，b 弹
// 在队尾插入元素：
//     直接存入 a 栈
// 在队头删除元素：
//     若 b 栈不空，则直接从 b 栈弹出，若 b 栈为空，则说明没有元素了，返回 -1
//     若 b 栈为空，则先将 a 栈的所有元素都搬到 b 栈，再从 b 栈弹出

class CQueue {
public:
    stack<int> a, b; // a 存，b 弹

    // 构造函数
    CQueue() {

    }

    // 在队尾插入元素
    void appendTail(int value) {
        a.push(value);
    }

    // 在队首删除元素
    int deleteHead() {
        //【1】搬：若 b 为空，且 a 不空，将 a 中的所有元素搬运到 b
        if (b.empty()) { 
            while (a.size()) {
                b.push(a.top());
                a.pop();
            }

        }
        //【2】弹：若 b 栈不空，则直接从 b 栈弹出，返回弹出元素，若 b 栈为空，则说明没有元素了，返回 -1
        if (b.empty()) return -1;

        int t = b.top();
        b.pop();
        return t;
    }
};



// 无注释版本
class CQueue {
public:
    stack<int> a, b;

    // 构造函数
    CQueue() {

    }

    // 在队尾插入元素
    void appendTail(int value) {
        a.push(value);
    }

    // 在队首删除元素
    int deleteHead() {
        if (b.empty()) { 
            while (a.size()) {
                b.push(a.top());
                a.pop();
            }

        }

        if (b.empty()) return -1;

        int t = b.top();
        b.pop();
        return t;
    }
};
