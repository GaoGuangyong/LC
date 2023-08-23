
// 滑动窗口写法（推荐）
// 维护滑动窗口 [j ~ i]，其中 i 从 1 ~ target - 1，j 从 1 到 i - 1

class Solution {
public:
    vector<vector<int> > findContinuousSequence(int target) {
        vector<vector<int>> res;

        int sum = 0; // 记录当前滑动窗口内的元素和

        // 维护滑动窗口 [j ~ i]
        for (int i = 1, j = 1; i < target; i ++ ) {
            // 先将 i 加上
            sum += i;

            // 若 当前滑动窗口内的元素和 > 目标，则不断将 j 右移，直到当前滑动窗口内的元素和 <= 目标
            while (sum > target) {
                sum -= j;
                j ++ ;
            }

            // 如果当前区间的和等于 target，且至少要有 2 个数（即 i 和 j 不能相等）
            if (sum == target && j < i) { 
                vector<int> path;
                for (int k = j; k <= i; k ++ ) { 
                    path.push_back(k);
                }
                res.push_back(path);
            }
        }

        return res;
    }
};


// 双指针
// 因为是正整数序列，具有单调性，所以可以利用双指针算法将复杂度优化到 O(n)
// i 从 1 遍历到 target，查找以 i 开始时，j 应该是多少，满足 [i ~ j] 的和是 target

class Solution {
public:
    vector<vector<int> > findContinuousSequence(int target) {
        vector<vector<int>> res; // 结果数组

        int sum = 1; // sum 表示当前 [i ~ j] 区间的数字和

        // 双指针：正整数序列，所以从 1 开始
        int j = 1;
        for (int i = 1; i <= target; i ++ ) {
            // 当 [l ~ r] 的和 < target，则不断移动 j 指针，并将对对应的值加到 sum 上，直到区间和等于 target
            while (sum < target) {
                j ++ ;
                sum += j;
            }
 
            // 如果当前区间的和等于 target，且至少要有 2 个数
            if (sum == target && i < j) {
                // 将当前 [i ~ j] 区间的数一个一个加入 path 数组，作为其中一个合法方案
                vector<int> path;
                for (int k = i; k <= j; k ++ ) { 
                    path.push_back(k);
                }
                res.push_back(path);
            }

            // sum = sum - i，因为每次 i ++ , 下一个循环里 sum 要变成 [i + 1 ~ j] 的和
            sum -= i;
        }

        return res;
    }
};



// 无注释版本
class Solution {
public:
    vector<vector<int> > findContinuousSequence(int target) {
        vector<vector<int>> res;

        int sum = 1;

        int j = 1;
        for (int i = 1; i <= target; i ++ ) {
            while (sum < target) {
                j ++ ;
                sum += j;
            }

            if (sum == target && i != j) {
                vector<int> path;
                for (int k = i; k <= j; k ++ ) { 
                    path.push_back(k);
                }
                res.push_back(path);
            }

            sum -= i;
        }

        return res;
    }
};



