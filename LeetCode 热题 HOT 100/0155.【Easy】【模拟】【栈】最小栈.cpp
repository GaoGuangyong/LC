
// 可以在每个元素 a 入栈时把当前栈的最小值 m 存储起来。在这之后无论何时，如果栈顶元素是 a，我们就可以直接返回存储的最小值 m
// 因此可以使用一个辅助栈 min_stk，与元素栈 stk 同步插入与删除，用于存储与每个元素对应的最小值
// 当一个元素要入栈时，我们取当前辅助栈的栈顶存储的最小值，与当前元素比较得出最小值，将这个最小值插入辅助栈中
// 当一个元素要出栈时，我们把辅助栈的栈顶元素也一并弹出
// 在任意一个时刻，栈内元素的最小值就存储在辅助栈的栈顶元素中



class MinStack {
    stack<int> stk; // 元素栈
    stack<int> min_stk; // 辅助栈
public:
    // 初始化栈
    MinStack() {
       min_stk.push(INT_MAX); // 初始化时辅助栈里放一个最大值
    }
    // 将元素 x 入栈
    void push(int x) {
        stk.push(x); 
        // 比较要插入的元素 x 和辅助栈的栈顶元素的大小关系，将较小的插入辅助栈（这样就保证了辅助栈的栈顶一直是最小元素）
        min_stk.push(min(min_stk.top(), x)); 
    }
    // 删除栈顶元素
    void pop() {
        // 元素栈和辅助栈同步弹出
        stk.pop();
        min_stk.pop();
    }
    // 获取栈顶元素
    int top() {
        return stk.top();
    }
    // 获取栈中的最小元素
    int getMin() {
        return min_stk.top(); // 取辅助栈的栈顶元素
    }
};


// 无注释版本
class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;

    // 初始化栈
    MinStack() {
        min_stk.push(INT_MAX);
    }

    // 将元素 val 入栈
    void push(int val) {
        stk.push(val);
        min_stk.push(min(min_stk.top(), val));
    }
    
    // 删除栈顶元素
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    // 获取栈顶元素
    int top() {
        return stk.top();
    }
    
    // 获取栈中的最小元素
    int getMin() {
        return min_stk.top();
    }
};
