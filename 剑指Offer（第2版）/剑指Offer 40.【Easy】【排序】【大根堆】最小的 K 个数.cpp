
// 大根堆

// 使用大根堆存最小的 k 个数的过程：
// 先将当前元素加入大根堆中，然后从第 k + 1 个元素开始，从大根堆中弹出堆顶元素（最大值），使堆中始终存的是目前为止最小的 k 个数
// 遍历结束后，大根堆里剩下的就是最小的 k 个数

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res; // 结果数组
        priority_queue<int, vector<int>, less<int>> heap; // 定义一个大根堆

        // 遍历数组，维护大根堆
        for (int x: arr) {
            heap.push(x); // 先将当前元素加入大根堆
            if (heap.size() > k) heap.pop(); // 从第 k + 1 个元素开始，弹出堆顶元素
        }

        // 遍历大根堆，不断将最大的元素加入 res 中
        while (heap.size()) {
            res.push_back(heap.top()); // 将堆顶元素加入结果数组
            heap.pop(); // 弹出堆顶元素
        }

        // 因为结果要从小到大输出，所以将 res 数组倒转
        reverse(res.begin(), res.end());
        return res;
    }
};


// 无注释版本

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int, vector<int>, less<int>> heap;

        for (int x: arr) {
            heap.push(x);
            if (heap.size() > k) heap.pop();
        }

        while (heap.size()) {
            res.push_back(heap.top());
            heap.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
