// 滑动窗口， 队列
class RecentCounter {
public:
    // 用队列维护一个滑动窗口，队头是最远的请求，队尾是最近的请求
    queue<int> q; 

    RecentCounter() {

    }

    // 返回在 [t-3000, t] 内发生的请求数
    int ping(int t) {
        // 先将时间 t 入队 
        q.push(t);
        // 当滑动窗口的长度大于 3000，就将队头元素出队，使长度小于等于 3000
        while (t - q.front() > 3000) q.pop(); 
            
        return q.size();
    }
};



// 无注释版本
class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {

    }
    
    int ping(int t) {
        q.push(t);
        while (t - q.front() > 3000) q.pop();

        return q.size();
    }
};

