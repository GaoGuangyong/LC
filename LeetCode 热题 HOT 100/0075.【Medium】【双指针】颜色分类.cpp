// 背，只有这题能用上 https://www.acwing.com/video/1418/


// 双指针（背，只有这题能用上）
// 用 i 遍历数组，j 从前往后扫描，k 从后往前扫描
// 使 [0 ~ j - 1] 都是 0，[j ~ i - 1] 都是 1，[k + 1 ~ n - 1] 都是 2，当 i > k 的时候就排序完成了

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k;) {
            // 如果遍历到了 0，就和 j 交换（把 0 往前放），此时交换到 i 的是 nums[j]，一定是 0，所以 i ++
            if (nums[i] == 0) { 
                swap(nums[i], nums[j]);
                j ++ ;
                i ++ ;
            }
            // 如果遍历到了 2，就和 k 交换（把 2 往前放），此时交换到 i 的是 nums[k]，不一定是 0，所以不要 i ++ 
            else if (nums[i] == 2) { 
                swap(nums[i], nums[k]);
                k -- ;
            }
            // 如果遍历到了 1，就跳过
            else if (nums[i] == 1) { 
                i ++ ;
            }
        }
    }
};


// 无注释版本
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k; ) {
            if (nums[i] == 0) {
                swap(nums[i], nums[j]);
                j ++ ;
                i ++ ;
            }
            else if (nums[i] == 2) {
                swap(nums[k], nums[i]);
                k -- ;
            }
            else if (nums[i] == 1) {
                i ++ ;
            }
        }
    }
};

