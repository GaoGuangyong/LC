
// 类似二路归并
// 定义 p 指向 nums1 数组的最后一个元素
// 定义 q 指向 nums2 数组的最后一个元素
// 定义 tail 指向合并后的 nums1 数组的最后一个元素
// 比较 p 指向的值和 q 指向的值，将大的值放到 nums1[tail]
// tail 指针往前移动，p 或者 q 指针也相应往移动
// 循环以上步骤直到 p = 0 或 q = 0
// 若 q >= 0, 将 nums2 数组剩余的元素挪进 nums1

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n - 1;
        int p = m - 1;
        int q = n - 1;

        while (p >= 0 && q >= 0) { // 注意 >= 
            // 判断：将更大的数放到 nums1[tail] 处
            if (nums1[p] > nums2[q])
                nums1[tail -- ] = nums1[p -- ];
            else
                nums1[tail -- ] = nums2[q -- ];
        }
        // 循环结束后，如果 q >= 0，说明 nums2 还剩了，全部放到 nums1 的对应位置
        while (q >= 0) {
            nums1[tail -- ] = nums2[q -- ];
        }
    }
};


// 二刷
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n - 1;
        int t1 = m - 1;
        int t2 = n - 1;

        while (t1 >= 0 && t2 >= 0) {
            if (nums1[t1] > nums2[t2]) nums1[tail -- ] = nums1[t1 -- ];
            else nums1[tail -- ] = nums2[t2 -- ]; 
        }

        while (t2 >= 0) nums1[tail -- ] = nums2[t2 -- ];
    }
};

