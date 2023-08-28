// 模拟
// 使用两个栈，一个主栈，一个辅助栈

// 出队：
//【1】找到原始栈 a 的栈底元素 t：只要原始栈 a 中元素个数 > 1，就先将原始栈 a 的栈顶挪到辅助栈 b 中
//【2】将栈底元素 t 出栈
//【3】将辅助站 b 中的元素挪回原始栈 a 中

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



// 二刷
class MyQueue {
public:
    stack<int> a;
    stack<int> b;

    MyQueue() {

    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while (a.size() > 1) {
            b.push(a.top());
            a.pop();
        }

        int t = a.top();
        a.pop();

        while (b.size() > 0) {
            a.push(b.top());
            b.pop();
        }

        return t;
    }
    
    int peek() {
        while (a.size() > 1) {
            b.push(a.top());
            a.pop();
        }

        int t = a.top();

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

