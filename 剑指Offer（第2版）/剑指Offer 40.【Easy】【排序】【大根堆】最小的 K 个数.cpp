
// 大根堆
// 遍历数组，将每个元素先加入大根堆中，然后判断堆中元素的个数，若元素个数 > k，则弹出堆顶元素（当前堆中的最大值）
// 遍历结束后，大根堆里剩下的就是最小的 k 个数

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res; // 结果数组
        priority_queue<int, vector<int>, less<int>> heap; // 定义一个大根堆

        // 遍历数组，维护大根堆
        for (int x: arr) {
            heap.push(x); // 先将当前元素加入大根堆
            // 如果堆中的元素个数超过 k 个，则弹出堆顶（即堆里的最大值）
            if (heap.size() > k) heap.pop();
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
