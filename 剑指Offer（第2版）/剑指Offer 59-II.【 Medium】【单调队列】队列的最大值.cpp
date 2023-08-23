
// 单调队列

class MaxQueue {
public:
    deque<int> a; // a 是普通的双端队列
    deque<int> b; // a 是非严格的递减的单调双端队列

    // 构造函数
    MaxQueue() {

    }

    // 取队列最大值操作
    int max_value() {
        // 按照题目要求，如果队列为空，max_value 需返回 -1（改成 a.empty() 也一样）
        if (b.empty()) return -1;
        return b.front();
    }

    // 队尾插入元素操作
    void push_back(int value) {
        // a 是普通队列，直接插入
        a.push_back(value);

        // b 是单调队列，需要维护其单调性后再插入
        // 当要插入的元素大于 b 的队尾元素时，删除 b 的队尾元素，直至满足单调性
        while (b.size() && value > b.back()) { // 非严格递减，所以是 >，如果是严格递减，则是 >=
            b.pop_back();
        }
        b.push_back(value);
    }

    // 队头弹出元素操作
    int pop_front() {
        // 按照题目要求，如果队列为空，pop_front 需返回 -1（改成 a.empty() 也一样）
        if (b.empty()) return -1;

        int value = a.front();

        // 弹出 a 的队头元素
        a.pop_front();

        // 若 b 的队头元素 = a 的队头元素，则说明当前弹出的元素是队列的最大值，故也弹出 b 的队头元素
        if (b.size() && value == b.front()) b.pop_front();

        return value;
    }
};


// 无注释版本
class MaxQueue {
public:
    deque<int> a;
    deque<int> b;

    MaxQueue() {

    }

    int max_value() {
        if (b.empty()) return -1;
        return b.front();
    }

    void push_back(int value) {
        a.push_back(value);

        while (b.size() && value > b.back()) { 
            b.pop_back();
        }
        b.push_back(value);
    }

    int pop_front() {
        if (b.empty()) return -1;

        int value = a.front();

        a.pop_front();

        if (b.size() && value == b.front()) b.pop_front();

        return value;
    }
};

