
// 根据题意，需要一个容器来储存数据
// 因为该容器具有当容量达到上限时需要释放最早加入容器的性质，即符合 “先进先出”，那么这个容器就可以使用队列

// 用队列维护滑动窗口

class RecentCounter {
public:
    // 用队列维护一个滑动窗口，队头是最远的请求，队尾是最近的请求
    queue<int> q; 

    RecentCounter() {

    }

    // 返回在 [t-3000, t] 内发生的请求数
    int ping(int t) {
        q.push(t); // 先将时间 t 入队

        // 当滑动窗口的长度大于 3000，就将队头元素出队，使长度小于等于 3000
        while (t - q.front() > 3000) {
            q.pop(); 
        }
        
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

