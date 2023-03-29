// DP
// 在 LC 131题的 DP 基础上，再进行一次 DP
// 第一次 DP
// 状态表示：
// f1[j][i] 表示 s[j ~ i] 是不是回文串，当我们需要判断某个序列是不是回文串的时候，就可以调用这个状态数组

// 状态转移：
// 当 s[j ~ i] 的长度 == 1 时，必是回文串
// 当 s[j ~ i] 的长度 == 2 时，若 s[j] == s[i]，则是回文串
// 当 s[j ~ i] 的长度 > 2 时，若 s[j] == s[i] && f1[j + 1][i - 1] ，则是回文串
// 其他情况都不是回文串

// 第二次 DP
// 状态表示：
// f2[i] 表示把区间 [1 ~ i] 划分成回文串，最少划分成几个部分，则答案为 f2[n] − 1

// 状态转移：
// 假设 把整个区间 [1 ~ i] 分成 [1 ~ k - 1] 和 [k ~ i]；最后一个区间是 [k ~ i] 已确定，前面的 [1 ~ k - 1] 如何划分不确定
// 划分的最后一个区间的 k 有 i 种情况：[1 ~ i], [2 ~ i], ... , [i ~ i] 
// [k ~ i] 是回文串时，【把区间 [1 ~ i] 划分成回文串，最少划分成几个部分】 可以从 【把区间 [1 ~ k - 1] 划分成回文串，最少划分成几个部分】 中转移过来
// 枚举最后一个区间的起点 k（1 ~ i），当最后一个区间是回文串时，更新 f2[i] 的最小值即可：f2[i] = min(f2[i], f2[k - 1] + 1)

class Solution {
public:
    vector<vector<bool>> f1; // 第一次 DP 的状态数组 声明
    vector<int> f2; // 第二次 DP 的状态数组 声明

    int minCut(string s) {
        // 预处理 f1[j][i]
        int n = s.size();
        s = " " + s;
        // 第一次 DP 的状态数组 f1 的定义
        f1 = vector<vector<bool>>(n + 1, vector<bool>(n + 1)); 
        // 第一次 DP 的状态数组 f1 的实现
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= i; j ++ ) {
                // 当 s[j ~ i] 的长度 == 1 时，必是回文串
                if (j == i) f1[j][i] = true;
                // 当 s[j ~ i] 的长度 == 2 时，若 s[j] == s[i]，则是回文串
                else if (i - j + 1 == 2 && s[j] == s[i]) f1[j][i] = true;
                // 当 s[j ~ i] 的长度 > 2 时，若 s[j] == s[i] && f[j + 1][i - 1] ，则是回文串
                else if (s[j] == s[i] && f1[j + 1][i - 1] == true) f1[j][i] = true;
                // 其他情况都不是回文串
                else f1[j][i] = false;
            }
        }

        // 第二次 DP 的状态数组 f2 的定义
        f2 = vector<int>(n + 1); 
        // 第二次 DP 的状态数组 f2 的实现
        for (int i = 1; i <= n; i ++ ) {
            f2[i] = INT_MAX; // 因为要求最小值，所以 f2[i] 的初值设为正无穷
            // 枚举最后一个区间的起点 k
            for (int k = 1; k <= i; k ++ ) {
                // 如果最后一个区间 [k ~ i] 是回文串，则更新 f2[i] 的最小值
                if (f1[k][i] == true)
                    f2[i] = min(f2[i], f2[k - 1] + 1);
            }
        }

        return f2[n] - 1;
    }
};


// 无注释版本
class Solution {
public:
    vector<vector<bool>> f1;
    vector<int> f2;

    int minCut(string s) {
        int n = s.size();
        s = " " + s;
        
        f1 = vector<vector<bool>>(n + 1, vector<bool>(n + 1)); 

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= i; j ++ ) {
                if (j == i) f1[j][i] = true;
                else if (i - j + 1 == 2 && s[j] == s[i]) f1[j][i] = true;
                else if (s[j] == s[i] && f1[j + 1][i - 1] == true) f1[j][i] = true;
                else f1[j][i] = false;
            }
        }

        f2 = vector<int>(n + 1); 
        
        for (int i = 1; i <= n; i ++ ) {
            f2[i] = INT_MAX;
            for (int k = 1; k <= i; k ++ ) {
                if (f1[k][i] == true)
                    f2[i] = min(f2[i], f2[k - 1] + 1);
            }
        }
        
        return f2[n] - 1;
    }
};


