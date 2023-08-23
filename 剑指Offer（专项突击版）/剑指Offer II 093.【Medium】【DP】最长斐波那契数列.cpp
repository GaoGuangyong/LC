
// DP
// 求最长斐波那契子序列 -> 回顾求最长上升子序列

// 状态表示：
// f[i][j] 表示倒数第一个数是 arr[i]，倒数第二个数是 arr[j] 的斐波那契子序列的最大长度

// 初始化：
// 最少选择了 arr[j] 和 arr[i]，因此长度初值为 2

// 状态转移：
// 由斐波那契数列的性质，计算出倒数第三个数（下标 k）的预期值 x = arr[i] - arr[j]
// 对于每个 i，都遍历一个小于 i 的 j，如果 x 在 arr[j] 之前出现过（即在哈希表中能找到 arr[i] - arr[j]
// 则更新 f[i][j] = max(f[i][j], f[j][k] + 1)

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        // 定义一个哈希表存数组中每个元素及其下标
        unordered_map<int, int> hash; 
        for (int i = 0; i < n; i ++ ) {
            hash[arr[i]] = i;
        }

        int res = 0;

        // 定义状态数组 + 初始化
        vector<vector<int>> f(n, vector<int>(n, 2)); // 最少选择了 arr[j] 和 arr[i]，因此将斐波那契子序列的长度初始化为 2

        // 状态转移
        // 因为至少要有 3 个数构成子序列，故 i 的范围 [2 ~ n - 1]，j 的范围 [1 ~ i - 1]
        for (int i = 2; i < n; i ++ ) { 
            for (int j = 1; j < i; j ++ ) {
                int x = arr[i] - arr[j]; // 倒数第三个数的预期值 x
                // 如果 x 在 arr[j] 之前出现过，记录 x 的下标 k，更新 f[i][j] = max(f[i][j], f[j][k] + 1)
                if (x < arr[j] && hash.count(x)) { 
                    int k = hash[arr[i] - arr[j]];
                    f[i][j] = max(f[i][j], f[j][k] + 1);
                }
                // 更新长度的最大值
                res = max(res, f[i][j]);
            }
        }
            
        // 如果最终 res 长度 < 3，则没找到斐波那契子序列，返回 0
        if (res < 3) res = 0;
        return res;
    }
};


// 二刷
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> hash;
        for (int i = 0; i < n; i ++ ) hash[arr[i]] = i;
        
        vector<vector<int>> f(n, vector<int>(n, 2));

        int res = 0;

        for (int i = 2; i < n; i ++ ) {
            for (int j = 1; j < i; j ++ ) {
                int x = arr[i] - arr[j];
                if (hash.count(x) && x < arr[j]) {
                    int k = hash[arr[i] - arr[j]];
                    f[i][j] = max(f[i][j], f[j][k] + 1);
                }
                res = max(res, f[i][j]);
            }
        }

        if (res == 2) return 0;
        return res;
    }
};


