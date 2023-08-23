
// 输入一个数组，求出这个数组中的逆序对的总数

// 在归并排序的过程中计算逆序对的数量（归并排序模板见最后）
// 总的逆序对数 = 左侧区间的逆序对数 + 右侧区间的逆序对数 + 跨区间的逆序对数

class Solution {
public: 
    // 辅助函数：修改过的归并排序：在归并排序的过程中，计算 num[l ~ r] 中逆序对的数量，并返回
    int merge(vector<int>& nums, int l, int r) {
        if (l >= r) return 0; // 递归出口：若最终只有一个元素，则没有逆序对，返回 0

        int mid = (l + r) >> 1; // 二分 [l ~ r] 区间

        // 先递归计算 左侧区间 [l, mid] 的逆序对数 + 右侧区间 [mid + 1, r] 的逆序对数
        int res = merge(nums, l, mid) + merge(nums, mid + 1, r); 
        
        // 以下是归并过程

        int i = l; // i 指向左侧区间的起点
        int j = mid + 1; // j 指向右侧区间的起点
        
        vector<int> temp; // 临时数组，用来存储归并后的结果
        
        // 当左侧区间 与 右侧区间都没有遍历完时循环
        while (i <= mid && j <= r) { 
            if (nums[i] <= nums[j]) temp.push_back(nums[i ++ ]); // 如果左侧区间当前所指的数更小（即不构成逆序对），就把左侧区间的数加入 temp 数组

            // 否则，如果右侧区间当前所指的数更小（即构成逆序对），就把右侧区间的数加入 temp 数组，同时计算逆序对数量
            else {
                temp.push_back(nums[j ++ ]); 
                res += mid - i + 1; // 此时 nums[j] < nums[i]，即 nums[j] < nums[i ~ mid]，共有 mid - i + 1 个逆序对
            }
        } // 结束循环后，左侧区间或右侧区间，必有一边已经遍历完毕

        while (i <= mid) temp.push_back(nums[i ++ ]); // 当左侧区间还没有遍历完，则把左侧区间剩余的都加入 temp
        while (j <= r) temp.push_back(nums[j ++ ]); // 当右侧区间还没有遍历完，则把右侧区间剩余的都加入 temp

        for (int i = l, j = 0; i <= r; i ++, j ++ ) nums[i] = temp[j]; // 最后，再将临时数组中的元素复制回原数组中
            
        return res;
    }

    // 主函数
    int reversePairs(vector<int>& nums) {
       return merge(nums, 0, nums.size() - 1);
    }
};



// 无注释版本
class Solution {
public: 
    int merge(vector<int>& nums,int l, int r) {
        if (l >= r) return 0; 

        int mid = (l + r) >> 1;

        int res = merge(nums, l, mid) + merge(nums, mid + 1, r); 
        

        vector<int> temp; 

        int i = l;
        int j = mid + 1; 
        
        while (i <= mid && j <= r) { 
            if (nums[i] <= nums[j]) temp.push_back(nums[i ++ ]); 
            else { 
                temp.push_back(nums[j ++ ]); 
                res += mid - i + 1; 
            }
        }

        while (i <= mid) temp.push_back(nums[i ++ ]);
        while (j <= r) temp.push_back(nums[j ++ ]);

        for (int i = l, j = 0; i <= r; i ++, j ++ ) {
            nums[i] = temp[j];
        }
            
        return res;
    }

    int reversePairs(vector<int>& nums) {
       return merge(nums, 0, nums.size() - 1);
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

