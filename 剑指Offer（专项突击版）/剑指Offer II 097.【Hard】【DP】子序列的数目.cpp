
// DP
// 这种两个字符串的问题，一般都用二维数组来表示状态：
// 第一维表示第一个字符串的最后一个字符，第二维表示第二个字符串的最后一个字符

// 状态表示：
// f[i][j] 表示 s[1 ~ i] 中所有和 t[1 ~ j] 相等的子序列的个数（下标从 1 开始）

// 初始化：
// t 为空时，也是一种合法方案，即方案数为 1
// f[i][0] = 1;

// 状态转移：
// 根据 选/不选 s[i] 分 2 种情况
// 如果不选 s[i]，则在 s[1 ~ i - 1] 中找所有和 t[1 ~ j] 相等的子序列，即 f[i][j] = f[i − 1][j]
// 如果选 s[i]，那就意味着 s[i] == t[j]，则在 s[1 ~ i - 1] 中找所有和 t[1 ~ j - 1] 相等的子序列，即 f[i][j] = f[i − 1][j - 1]
// 将这两种情况的结果相加即可

typedef unsigned long long LL;

class Solution {
public:
    int numDistinct(string s, string t) {
        // 获取字符串 s 和 t 的长度
        int n = s.size();
        int m = t.size();

        // 为了方便 DP，将 2 个字符串都向后移动一位
        s = ' ' + s;
        t = ' ' + t;
        
        // 定义状态数组
        vector<vector<LL>> f(n + 1, vector<LL>(m + 1));
        
        // 初始化：t 为空时，在 s[1 ~ i] 中选空的字符串，这也是一种合法方案，即方案数为 1
        for (int i = 0; i <= n; i ++ ) {
            f[i][0] = 1;
        }
        
        // 状态转移：
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                // 不选 s[i]
                f[i][j] = f[i - 1][j];
                // 选 s[i]
                if (s[i] == t[j])
                    f[i][j] += f[i - 1][j - 1];
            }
        }

        return f[n][m];
    }
};


// 无注释版本

typedef unsigned long long LL;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        s = ' ' + s;
        t = ' ' + t;
        
        vector<vector<LL>> f(n + 1, vector<LL>(m + 1));
        
        for (int i = 0; i <= n; i ++ ) {
            f[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                f[i][j] = f[i - 1][j];
                
                if (s[i] == t[j])
                    f[i][j] += f[i - 1][j - 1];
            }
        }

        return f[n][m];
    }
};