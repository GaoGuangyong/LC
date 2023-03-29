
// 在归并排序的过程中计算逆序对的数量
// 总的逆序对数 = 左侧区间的逆序对数 + 右侧区间的逆序对数 + 跨区间的逆序对数

class Solution {
public: 
    // 辅助函数：修改过的归并排序：在归并排序的过程中，计算 num[l ~ r] 中逆序对的数量，并返回
    int merge(vector<int>& nums,int l, int r) {
        // 递归出口：若最终只有一个元素，则没有逆序对，返回 0
        if (l >= r) return 0; 

        int mid = (l + r) >> 1; // 二分 [l ~ r] 区间

        // 先计算 左侧区间 [l, mid] + 右侧区间 [mid + 1, r] 中的逆序对数量
        int res = merge(nums, l, mid) + merge(nums, mid + 1, r); 
        

        // 以下是归并过程

        vector<int> temp; // 临时数组，用来存储归并后的结果

        // i 指向左半边的起点，j 指向右半边的起点
        int i = l;
        int j = mid + 1; 
        
        // 当左半边没有遍历完，且，右半边没有遍历完
        while (i <= mid && j <= r) { 
            // 如果左半边当前所指的数更小或相等（即不构成逆序对），就把左半边的数加入 temp 数组
            if (nums[i] <= nums[j]) temp.push_back(nums[i ++ ]); 

            // 如果右半边当前所指的数更小（即构成逆序对），就把右半边的数加入 temp 数组
            // 同时计算逆序对数量：此时 nums[j] < nums[i]，即 nums[j] < nums[i ~ mid]，共有 mid - i + 1 个
            else { 
                temp.push_back(nums[j ++ ]); 
                res += mid - i + 1; 
            }
        } // 结束循环后，左半边或右半边，必有一边已经遍历完毕

        while (i <= mid) temp.push_back(nums[i ++ ]); // 当左半边还没有遍历完，则把左半边剩余的都加入temp
        while (j <= r) temp.push_back(nums[j ++ ]); // 当右半边还没有遍历完，则把右半边剩余的都加入temp

        // 从 l 开始，把临时数组的的数放回原数组中
        for (int i = l, j = 0; i <= r; i ++, j ++ ) {
            nums[i] = temp[j];
        }
            
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

