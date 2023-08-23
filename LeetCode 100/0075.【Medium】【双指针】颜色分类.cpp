

// 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
// 我们使用整数 0、1 和 2 分别表示红色、白色和蓝色


// 双指针（背，只有这题能用上）https://www.acwing.com/video/1418/

// 用 i 遍历数组，用 j 和 k 分割数组；j 从前往后移动，k 从后往前移动；枚举条件：i <= k
// 使 [0 ~ j - 1] 都是 0，[j ~ i - 1] 都是 1，[k + 1 ~ n - 1] 都是 2 （画数轴分析）
// 当 i > k 的时候就排序完成了

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 注意循环条件：i <= k
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k; ) {
            // 如果遍历到了 0，就和 j 交换（把 0 往前放），然后 j 向后移动，此时交换到 i 的是 nums[j]，一定是 0，不需要判断其值了，所以 i ++ 
            if (nums[i] == 0) { 
                swap(nums[i], nums[j]);
                j ++ ; // j 向后移动一步
                i ++ ;
            }

            // 如果遍历到了 2，就和 k 交换（把 2 往前放），然后 k 向前移动，此时交换到 i 的是 nums[k]，值不确定，仍需要判断其值，所以不要 i ++ 
            else if (nums[i] == 2) { 
                swap(nums[i], nums[k]);
                k -- ; // k 向前移动一步
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

// 二刷
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k; ) {
            if (nums[i] == 0) {
                swap(nums[i], nums[j]);
                i ++ ;
                j ++ ;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[k]);
                k -- ;
            }
            else i ++ ;
        }
    }
};
