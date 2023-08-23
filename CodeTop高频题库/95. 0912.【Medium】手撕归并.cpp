
//【1】堆排序
class Solution {
public:
    vector<int> heap; // 使用一维数组存堆中的节点，编号从 1 开始

    // 将编号为 u 的节点向下调整：将 u 及其左右儿子调整为小根堆，并不断递归向下调整
    void down(int u) {
        //【1】先取出 heap[u]，heap[2u]，heap[2u + 1] 中的最小值对应的编号 t

        int t = u; // 用 t 存根节点 u 及其左右儿子中，值最小的那个节点的编号
        if (u * 2 <= heap.size() - 1 && heap[u * 2] < heap[t]) t = u * 2; // 如果编号 u 的节点有左儿子，且其左儿子的值更小的话，把 t 更新为左儿子的编号
        if (u * 2 + 1 <= heap.size() - 1 && heap[u * 2 + 1] < heap[t]) t = u * 2 + 1; // 如果编号 u 的节点有右儿子，且其右儿子的值更小的话，把 t 更新为右儿子的编号

        // 此时 t 存的就是三个节点中最小的那个节点的编号
        
        //【2】如果最小的节点的编号不是 u，则将其与 u 交换
        if (t != u) {
            swap(heap[u], heap[t]);
            down(t);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // 遍历 nums 数组，将 nums[0 ~ n - 1] 存到 heap[1 ~ n] 中
        heap.assign(n + 1, 0);
        for (int i = 0; i < n; i ++ ) heap[i + 1] = nums[i];

        // O(n) 的建堆方式：从编号 n / 2 的节点开始 down 到编号 1 的节点
        for (int i = n / 2; i >= 1; i -- ) down(i);

        // 将排序后的结果存到 res 数组中
        vector<int> res(n, 0);
        for (int i = 0; i < n; i ++ ) {
            res[i] = heap[1]; // 每次取出堆顶元素（最小值）存到 res 中 
            // 接下来删除堆顶元素
            swap(heap[1], heap[heap.size() - 1]); // 将堆顶元素和最后一个元素交换
            heap.pop_back(); // 删除最后一个元素（即原来的堆顶元素）
            down(1); // 从根节点开始重新调整为小根堆结构
        }

        // 返回排序后的数组
        return res;
    }
};

//【2】快速排序
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r) {
        // 当数组为空时，l = 0, r = -1, 会出现 l > r 的情况
        // 除了一开始需要判断 l > r 之外, 以后 只需要 判断 l == r 即可
        if (l >= r) return; // 递归出口：区间为空或只有一个元素，不需要排序，直接返回

        int x = nums[l + r >> 1]; // 选择中间元素作为基准值 x

        int i = l - 1; // 左指针 i 初始化为第一个元素的前一个位置
        int j = r + 1; // 右指针 j 初始化为最后一个元素的后一个位置

        while (i < j) {
            do i ++ ; while (nums[i] < x); // 当 nums[i] < x，则不管，i 继续向后走，直到第一个大于等于 x 的元素的位置
            do j -- ; while (nums[j] > x); // 当 nums[j] > x，则不管，j 继续向前走，直到第一个小于等于 x 的元素的位置
            if (i < j) swap(nums[i], nums[j]); // 若 i 在 j 左侧，则交换二者，保证大于x的在右侧，小于x的在左侧
        }

        quick_sort(nums, l, j); // 递归排序左侧区间，左侧区间为[l, j]
        quick_sort(nums, j + 1, r); // 递归排序右侧区间，右侧区间为[j + 1, r]
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};


//【3】归并排序
class Solution {
public:
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return; // 递归出口
        
        vector<int> temp(r - l + 1, 0); // 临时数组，用于存储归并排序后的数组

        int mid = (l + r) >> 1; // 二分 [l ~ r] 区间

        merge_sort(nums, l, mid); // 递归排序左侧区间 [l, mid]
        merge_sort(nums, mid + 1, r); // 递归排序右侧区间 [mid + 1, r]

        int i = l; // i 指向左侧区间的起点
        int j = mid + 1; // j 指向右侧区间的起点
        int k = 0; // k 指向 res 数组，代表结果数组中目前有的元素个数

        // 当左侧区间 与 右侧区间都没有遍历完时循环
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) temp[k ++ ] = nums[i ++ ]; // 如果左侧区间当前所指的数更小，就把左侧区间的数加入 temp 数组
            else temp[k ++ ] = nums[j ++ ]; // 否则，就把右侧区间的数加入 temp 数组
        } // 结束循环后，左右中，必有一边已经遍历完毕
        
        while (i <= mid) temp[k ++ ] = nums[i ++ ]; // 当左侧区间还没有遍历完，则把左侧区间剩余的都加入 temp
        while (j <= r) temp[k ++ ] = nums[j ++ ]; // 当右侧区间还没有遍历完，则把右侧区间剩余的都加入 temp
        
        for (int i = l, j = 0; i <= r; i ++ , j ++ ) nums[i] = temp[j]; // 最后，再将结果数组中的元素复制回原数组中
    }

    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// 归并排序写法二
class Solution {
public:
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return; // 递归出口
        
        int mid = (l + r) / 2; // 二分 [l ~ r] 区间

        merge_sort(nums, l, mid); // 递归排序左侧区间 [l, mid]
        merge_sort(nums, mid + 1, r); // 递归排序右侧区间 [mid + 1, r]

        int i = l; // i 指向左侧区间的起点
        int j = mid + 1; // j 指向右侧区间的起点

        vector<int> temp; // 临时数组，用于存储归并排序后的数组 

        // 当左侧区间 与 右侧区间都没有遍历完时循环
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i ++ ]); // 如果左侧区间当前所指的数更小，就把左侧区间的数加入 temp 数组
            else temp.push_back(nums[j ++ ]); // 否则，就把右侧区间的数加入 temp 数组
        }

        while (i <= mid) temp.push_back(nums[i ++ ]); // 当左侧区间还没有遍历完，则把左侧区间剩余的都加入 temp
        while (j <= r) temp.push_back(nums[j ++ ]); // 当右侧区间还没有遍历完，则把右侧区间剩余的都加入 temp
        
        for (int i = l, j = 0; i <= r; i ++ , j ++ ) nums[i] = temp[j]; // 最后，再将临时数组中的元素复制回原数组中
    }

    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};



//【4】冒泡排序（超时）
class Solution {
public:
    void bubble_sort1(vector<int>& nums, int n) {
        for (int i = 0; i < n - 1; i ++ ) {
            for (int j = 0; j < n - 1 - i; j ++ ) {
                if (nums[j] > nums[j + 1]) {
                    // 交换 nums[j] 和 nums[j + 1] 的值
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }

    void bubble_sort2(vector<int>& nums, int n) {
        for (int i = n - 1; i > 0; i -- ) {
            for (int j = 0; j < i; j ++ ) {
                if (nums[j] > nums[j + 1]) {
                    // 交换 nums[j] 和 nums[j + 1] 的值
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }


    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        bubble_sort(nums, n);
        return nums;
    }
};


//【5】选择排序（超时）
vector<int> select_sort(vector<int>& nums) {
    int min_idx;
    int n = nums.size();

    // 外层循环控制遍历次数，每一次循环将找到当前范围内的最小值 nums[min_idx] 并放到正确的位置上
    for (int i = 0; i < n - 1; i ++ ) {
        min_idx = i; // 初始时，设当前遍历下标为最小值下标
        // 内层循环从当前遍历位置的下一个位置开始，遍历剩余元素，找到比当前最小值还小的最小值
        for (int j = i + 1; j < n; j ++ ) {
            // 如果找到了比当前最小值还小的元素，更新最小值索引
            if (nums[j] < nums[min_idx]) {
                min_idx = j;
            }
        }
        // 将最小值与当前位置的值交换，将最小值放到正确的位置上
        swap(nums[i], nums[min_idx]);
    }
    return nums;
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int max_idx;
        int n = nums.size();

        // 外层循环控制遍历次数，每一次循环将找到当前范围内的最大值并放到正确的位置上
        for (int i = n - 1; i > 0; i -- ) {
            // 假设当前索引位置为最大值的索引
            max_idx = i;
            // 内层循环从当前索引的前一个位置开始，遍历剩余元素，找到比当前最大值还大的元素
            for (int j = i - 1; j >= 0; j -- ) {
                // 如果找到了比当前最大值还大的元素，更新最大值索引
                if (nums[j] > nums[max_idx]) {
                    max_idx = j;
                }
            }
            // 将当前最大值与当前位置交换，将最大值放到正确的位置上
            swap(nums[i], nums[max_idx]);
        }

        return nums;
    }
};




// 二刷

// 快排
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int i = l - 1;
        int j = r + 1;
        int x = nums[l + r >> 1];

        while (i < j) {
            do i ++ ; while (nums[i] < x);
            do j -- ; while (nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }

        quick_sort(nums, l , j);
        quick_sort(nums, j + 1 , r);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};



// 归并
class Solution {
public:
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int mid = l + r >> 1;

        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);

        int i = l;
        int j = mid + 1;

        vector<int> temp;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i ++ ]);
            else temp.push_back(nums[j ++ ]); 
        }

        while (i <= mid) temp.push_back(nums[i ++ ]);
        while (j <= r) temp.push_back(nums[j ++ ]);

        for (int i = l, j = 0; i <= r; i ++ , j ++ ) nums[i] = temp[j];
    }

    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};


// 堆
class Solution {
public:
    vector<int> heap;

    void down(int u) {
        int t = u;
        if (u * 2 <= heap.size() - 1 && heap[u * 2] < heap[t]) t = u * 2;
        if (u * 2 + 1 <= heap.size() - 1 && heap[u * 2 + 1] < heap[t]) t = u * 2 + 1;

        if (t != u) {
            swap(heap[u], heap[t]);
            down(t);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        heap.assign(n + 1, 0);
        for (int i = 0; i < n; i ++ ) heap[i + 1] = nums[i];

        for (int i = n / 2; i >= 1; i -- ) down(i);

        vector<int> res(n, 0);
        for (int i = 0; i < n; i ++ ) {
            res[i] = heap[1];
            
            swap(heap[1], heap[heap.size() - 1]);
            heap.pop_back();
            down(1);
        }

        return res;
    }
};




