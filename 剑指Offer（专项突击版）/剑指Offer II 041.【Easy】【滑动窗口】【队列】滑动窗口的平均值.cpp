// 根据题意，需要一个数据容器来储存数据
// 因为该容器具有当容量达到上限时需要释放最早加入容器的性质，即符合 “先进先出”，那么这个容器就可以使用队列

// 用队列维护滑动窗口

class MovingAverage {
public:
    int size = 0;
    queue<int> q; // 定义队列
    double sum = 0;

    // 用滑动窗口的大小 size 初始化对象
    MovingAverage(int size) {
        this->size = size;
    }

    // 将 val 入队，求此时滑动窗口内元素的平均值
    double next(int val) {
        q.push(val);
        sum += val;
        // 如果当前数字入队后，队列长度超过了滑动窗口的大小，则把队头的值减去，并让队头的出队
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        // 返回平均值
        return sum / q.size();
    }
};


// 无注释版本
class MovingAverage {
public:
    int size = 0;
    queue<int> q; 
    double sum = 0;

    MovingAverage(int size) {
        this->size = size;
    }

    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }
};
