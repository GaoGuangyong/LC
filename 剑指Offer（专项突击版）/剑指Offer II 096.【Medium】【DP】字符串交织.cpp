
// DP
// 状态表示：
// f[i][j] 表示 s1 的 [1 ~ i] 和 s2 的 [1 ~ j] 是否可以交错组成 s3 的 [1 ~ i + j] (下标从 1 开始)

// 初始化：
// 空串和空串可以拼成空串，f[0][0] = true

// 状态转移：
// 如果 s3[i + j] == s1[i]，则看 s1 的 [1 ~ i - 1] 和 s2 的 [1 ~ j] 是否可以交错组成 s3 的 [1 ~ i - 1 + j] 即 f[i − 1][j]
// 如果 s3[i + j] == s2[j]，则看 s2 的 [1 ~ j - 1] 和 s1 的 [1 ~ i] 是否可以交错组成 s3 的 [1 ~ j - 1 + i] 即 f[i][j − 1]
// 两种情况只要有一种为真，则 f[i][j] 就为真

// 时间复杂度：状态总共有 n^2 个，状态转移复杂度是 O(1)，所以总时间复杂度是 O(n^2)

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(); // 字符串 1 的长度
        int n = s2.size(); // 字符串 2 的长度

        // 特判：如果 s1 和 s2 的长度相加不等于 s3 的长度，则必定不可能组成
        if (s3.size() != m + n) return false; 

        // 为了方便 DP，将 3 个字符串都向后移动一位
        s1 = ' ' + s1; 
        s2 = ' ' + s2; 
        s3 = ' ' + s3;

        // 定义状态数组
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1)); 

        // 初始化：
        f[0][0] = true; // 空串和空串可以拼成空串

        // 注意：此题存在空串 与 长度为 1 的串 交错的情况，所以 i, j 都要从 0 开始
        for (int i = 0; i <= m; i ++ ) {
            for (int j = 0; j <= n; j ++ ) {
                if (i > 0 && s1[i] == s3[i + j]) f[i][j] = f[i - 1][j];
                if (j > 0 && s2[j] == s3[i + j]) f[i][j] = f[i][j] || f[i][j - 1];
            }
        }
        
        return f[m][n];
    }
};


// 无注释版本
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        if (s3.size() != n + m) return false;

        s1 = ' ' + s1;
        s2 = ' ' + s2;
        s3 = ' ' + s3;

        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));

        f[0][0] = true;

        for (int i = 0; i <= n; i ++ ) {
            for (int j = 0; j <= m; j ++ ) {
                if (i > 0 && s3[i + j] == s1[i]) f[i][j] = f[i - 1][j];
                if (j > 0 && s3[i + j] == s2[j]) f[i][j] = f[i][j] || f[i][j - 1];
            }
        }

        return f[n][m];
    }
};


