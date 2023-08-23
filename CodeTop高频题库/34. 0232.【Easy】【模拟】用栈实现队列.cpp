// 模拟
// 使用两个栈，一个主栈，一个辅助栈

class MyQueue {
public:
    // 全局变量
    stack<int> a; // 原始栈
    stack<int> b; // 辅助栈

    MyQueue() {

    }

    void push(int x) {
        a.push(x);
    }

    // 弹出队头元素
    int pop() {
        //【1】先找到栈底元素
        while (a.size() > 1) {
            b.push(a.top()); // 将原始栈 a 的栈顶不断的压入辅助栈 b
            a.pop();
        } // 循环结束时，a 的栈顶就是栈底元素

        //【2】找到栈底元素，并出栈
        int t = a.top();
        a.pop();

        //【3】将辅助栈 b 的栈顶不断压回原始栈 a
        while (b.size() > 0) {
            a.push(b.top());
            b.pop();
        }

        return t;
    }

    // 找队头元素相比于弹出队头元素，就差一步删除操作
    int peek() {
        //【1】先找到栈底元素
        while (a.size() > 1) {
            b.push(a.top()); // 将原始栈 a 的栈顶不断的压入辅助栈 b
            a.pop();
        } // 循环结束时，a 的栈顶就是栈底元素

        //【2】找到栈底元素
        int t = a.top();

        //【3】将辅助栈 b 的栈顶不断压回原始栈 a
        while (b.size() > 0) {
            a.push(b.top());
            b.pop();
        }

        return t;
    }

    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */