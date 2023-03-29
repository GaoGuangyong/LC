

// 双指针
// i 先向右移动，对于每一个 i ，都从头开始找一个尽可能靠【左】的 j，使 [j, i] 之间的数的乘积 < k

// 则元素乘积小于 k 的子数组数目为 i - j + 1
// 理由： [j, i] 满足，则 [j + 1, i] ... [i, i] 都满足。共 i - j + 1 个 子数组满足

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0; // 符合条件的子数组的个数
        int product = 1; // 滑动窗口内元素的乘积

        // 在 nums 中维护一个滑动窗口
        for (int i = 0, j = 0; i < nums.size(); i ++ ) { 
            // 先右移 i，把当前元素 nums[i] 乘到 product 上
            product *= nums[i]; 

            // 当右移 i 后，若滑动窗口内的乘积 >= k，则
            while (j <= i && product >= k) { 
                product /= nums[j]; // 从乘积中除以 nums[j]
                j ++ ; // j 向后移动一位
            } // 循环结束时，窗口内的元素的乘积 < k

            res += i - j + 1; // 计算当前滑动窗口内满足条件的的子数组数目
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0; 
        int product = 1;

        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            product *= nums[i];

            while (j <= i && product >= k) {
                product /= nums[j];
                j ++ ;
            }

            res += i - j + 1;
        }

        return res;
    }
};


