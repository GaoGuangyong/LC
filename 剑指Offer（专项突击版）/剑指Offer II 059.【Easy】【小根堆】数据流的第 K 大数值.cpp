

// 题意：求一个数组中第 k 大的数
// 小根堆：堆顶元素就是堆中最小的元素
// 从头开始遍历数组，用一个小根堆维护前 k 大的数（当超过 k 个数时，不断从中弹出最小的数）
// 最终：堆顶存的就是原数组中第 k 大的数

class KthLargest {
public:
    // 全局变量
    int k;
    priority_queue<int, vector<int>, greater<int>> heap; // 定义一个小根堆
    
    // 把数组 nums 中前 k 大的元素插入小根堆
    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        // 遍历 nums 数组，维护小根堆
        for (int x: nums) {
            // 先将当前元素插入堆中，如果堆中元素个数 > k，则弹出堆顶元素（最小元素）
            heap.push(x); 
            if (heap.size() > k) heap.pop();
        }
    }

    // 将 val 插入 nums 数组后，返回数组中第 k 大的数
    int add(int val) {
        // 将将 val 插入堆中，并维护小根堆
        heap.push(val);
        if (heap.size() > k) heap.pop();

        return heap.top(); // 返回堆顶（堆中最小的数，即原数组第 k 大的元素）
    }
};



// 无注释版本
class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;
    
    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        for (int x: nums) {
            heap.push(x); 
            if (heap.size() > k) heap.pop();
        }
    }

    int add(int val) {
        heap.push(val);
        if (heap.size() > k) heap.pop();

        return heap.top();
    }
};

