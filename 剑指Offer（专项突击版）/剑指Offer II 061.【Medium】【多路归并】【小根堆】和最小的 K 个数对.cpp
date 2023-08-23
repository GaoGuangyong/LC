
// 多路归并，分析过程见笔记
// 时间复杂度 O(Klogn)

// n 个序列的示意图如下：
// nums2[0] + nums1[0], nums2[0] + nums1[1], ...... , nums2[0] + nums1[m - 1]
// nums2[1] + nums1[0], nums2[1] + nums1[1], ...... , nums2[1] + nums1[m - 1]
// ..........................................................................
// nums2[n - 1] + nums1[0], nums2[n - 1] + nums1[1], ...... , nums2[n - 1] + nums1[m - 1]

// 求和最小的 k 个元素就是从上述 n 个序列中求值最小的 k 个元素 ==> n 路归并

// n 路归并
// 先将这 n 个序列的第 1 个元素加入小顶堆
// 将小顶堆的堆顶输出
// 再将小顶堆的堆顶所在序列的下一个元素加入小根堆中
// 不断重复上述过程，直到输出 k 个元素为止

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res; // 定义结果数组
        
        int m = nums1.size();
        int n = nums2.size();
        
        // 定义小顶堆，注意每个元素都是数组类型，长度为 3
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;

        // 把每个序列的第 1 个元素（数对和：nums2[i] + nums1[0]）先加入堆中
        // 堆中元素的结构：{数对的和, 该数对用到的 nums1 数字的下标, 该数对用到的 nums2 数字的下标}
        for (int i = 0; i < n; i ++ ) {
            heap.push({nums2[i] + nums1[0], 0, i});
        }

        // 重复执行 k 次堆的弹出操作
        while (k -- ) {
            if (heap.size()) {
                auto t = heap.top(); // 取出堆顶元素（当前堆中，数对的和的最小值）
                heap.pop();

                // 将数对的和对应的 2 个数，以数组的方式输出到结果数组中
                res.push_back({nums1[t[1]], nums2[t[2]]});

                // 只要堆顶元素所在的序列还有元素，就把该序列中下一个元素加入堆中（nums2 下标不变，nums1 下标 + 1）
                if (t[1] < m - 1) {
                    heap.push(nums2[t[2]] + nums1[t[1] + 1], t[1] + 1, t[2]);
                }
            }
        }

        return res;
    }
};



// 无注释版本
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;

        int m = nums1.size();
        int n = nums2.size();

        for (int i = 0; i < n; i ++ ) {
            heap.push({nums2[i] + nums1[0], 0, i});
        }

        while (k -- ) {
            if (heap.size()) {
                auto t = heap.top();
                heap.pop();

                res.push_back({nums1[t[1]], nums2[t[2]]});

                if (t[1] < m - 1) {
                    heap.push({nums2[t[2]] + nums1[t[1] + 1], t[1] + 1, t[2]});
                }
            }
        }

        return res;
    }
};

