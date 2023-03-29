// 堆
// 用大根堆存较小的那一半数
// 用小根堆存较大的那一半数
// 注：若元素个数是奇数，则规定大根堆的元素比小根堆多一个

// addNum 函数实现思路
// 1、将当前元素先放入大根堆
// 2、如果大根堆的堆顶 > 小根堆的堆顶，则出现逆序，交换二者
// 3、交换完成后，如果大根堆的元素个数比小根堆多 2 个，则把大根堆的堆顶放到小根堆里

// findMedian 函数实现思路
// 如果元素总数为奇数，则中位数为大根堆的堆顶
// 如果元素总数为偶数，则中位数为大根堆的堆顶和小根堆堆顶的平均数

class MedianFinder {
public:
    // 全局变量
    priority_queue<int, vector<int>, less<int>> max_heap; // 定义大根堆，存小的那一半数
    priority_queue<int, vector<int>, greater<int>> min_heap; // 定义小根堆，存大的那一半数

    // 构造函数
    MedianFinder() {

    }

    // 从数据流中添加一个整数到数据结构中
    void addNum(int num) {
        // 将当前元素先放入大根堆
        max_heap.push(num);

        // 如果大根堆的堆顶 > 小根堆的堆顶，则交换二者
        if (min_heap.size() && max_heap.top() > min_heap.top()) {
            int maxv = max_heap.top(); // 存大根堆的堆顶
            int minv = min_heap.top(); // 存小根堆的堆顶

            max_heap.pop(); // 弹出大根堆的堆顶
            min_heap.pop(); // 弹出小根堆的堆顶

            max_heap.push(minv); // 将小根堆的堆顶压入大根堆
            min_heap.push(maxv); // 将大根堆的堆顶压入小根堆
        }
        // 交换完成后，如果大根堆的元素个数比小根堆多 2 个，则把大根堆的堆顶放到小根堆里
        if (max_heap.size() - min_heap.size() == 2){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    // 返回目前所有元素的中位数
    double findMedian() {
        // 如果元素总个数为奇数，则中位数 = 大根堆堆顶
        if ((max_heap.size() + min_heap.size()) % 2 == 1)
            return max_heap.top() * 1.0;
        // 如果元素总个数为偶数，则中位数 = (小根堆堆顶 + 大根堆堆顶) / 2
        else
            return (max_heap.top() + min_heap.top()) * 1.0 / 2.0;
    }
};


// 无注释版本
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> max_heap; 
    priority_queue<int, vector<int>, greater<int>> min_heap;

    MedianFinder() {

    }

    void addNum(int num) {
        max_heap.push(num);

        if (min_heap.size() && max_heap.top() > min_heap.top()) {
            int maxv = max_heap.top();
            int minv = min_heap.top();

            max_heap.pop();
            min_heap.pop();

            max_heap.push(minv);
            min_heap.push(maxv);
        }

        if (max_heap.size() - min_heap.size() == 2){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double findMedian() {
        if ((max_heap.size() + min_heap.size()) % 2 == 1)
            return max_heap.top() * 1.0;
        else
            return (max_heap.top() + min_heap.top()) * 1.0 / 2.0;
    }
};

