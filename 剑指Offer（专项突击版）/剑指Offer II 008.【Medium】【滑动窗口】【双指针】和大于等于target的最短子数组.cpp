// 滑动窗口
// 对于每个位置 i，从左开始枚举数组，找到尽可能靠【右】的 j，满足 [j, i] 的和 >= s

// 题意：找出区间和 >= target 的连续区间，使该区间的长度最小，求该最小的区间长度

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX; // 因为要计算最小值，所以初始化成最大值，用于判断是否无解
        int sum = 0; // 滑动窗口中的元素之和

        // 在 nums 里维护一个滑动窗口
        for (int i = 0, j = 0; i < nums.size(); i ++ ) { 
            // 先右移 i，将当前元素的值加到 sum 上
            sum += nums[i]; 
            // 当右移 i 后，若滑动窗口中的元素之和 >= target，则找到了一个合法区间，计算其长度，再右移 j
            while (j <= i && sum >= target) {
                res = min(res, i - j + 1); // 计算区间长度，并更新最短区间长度
                sum -= nums[j]; // 从总和中删掉 nums[j]
                j ++ ; // j 向后移动 1 位
            } // 循环结束时 sum < target，故接着右移 i 寻找下一个合法的区间
        }

        // 如果遍历结束了，res 仍是 INT_MAX，则没有找到这样的区间，返回区间长度 0
        if (res == INT_MAX) res = 0; 
           
        return res;
    }
};


// 无注释版本

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;

        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            sum += nums[i];
            
            while (j <= i && sum >= target) {
                res = min(res, i - j + 1);
                sum -= nums[j];
                j ++ ;
            }
        }

        if (res == INT_MAX) res = 0;
        return res;
    }
};