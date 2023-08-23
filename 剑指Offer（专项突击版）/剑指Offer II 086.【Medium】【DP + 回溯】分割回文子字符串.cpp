
// DP + 回溯
// 状态表示：
// f[j][i] 表示 s[j ~ i] 是不是回文串，当我们需要判断某个序列是不是回文串的时候，就可以调用这个状态数组

// 状态转移：
// 当 s[j ~ i] 的长度 == 1 时，必是回文串
// 当 s[j ~ i] 的长度 == 2 时，若 s[j] == s[i]，则是回文串
// 当 s[j ~ i] 的长度 > 2 时，若 s[j] == s[i] && f[j + 1][i - 1] == true，则是回文串
// 其他情况都不是回文串

class Solution {
public:
    vector<string> path; // 一个合法方案
    vector<vector<string>> res; // 所有合法方案

    vector<vector<bool>> f; // 状态表示

    // 递归函数：从字符串 s 的下标 u 开始枚举，计算所有可能的方案
    void dfs(string s, int u) {
        // 递归出口：遍历完整个字符串，说明我们已经找到一条合法路径，加入 res
        if (u == s.size()) {
            res.push_back(path);
            return;
        }
        // 枚举 s[u ~ i]，查找有没有回文子串，若有，则加到当前合法方案 path 中
        for (int i = u; i < s.size(); i ++ ) {
            if (f[u][i] == true) { // 如果 s[u ~ i] 是回文串
                // 选择 s[u ~ i]
                path.push_back(s.substr(u, i - u + 1)); // 说明找到了一个合法方案，截取下来，加入 path
                // dfs
                dfs(s, i + 1); // 从 i 的下一个位置开始继续递归
                // 撤销选择
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // 预处理 f[j][i]
        int n = s.size();
        s = " " + s; // 为方便，在字符串最前面加一个空格

        // 状态表示
        f = vector<vector<bool>>(n + 1, vector<bool>(n + 1));  // f.assign(n + 1, vector<bool>(n + 1, false));
        
        // 状态转移
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= i; j ++ ) {
                if (j == i) f[j][i] = true; // 当 s[j ~ i] 的长度 == 1 时，必是回文串
                else if (i - j + 1 == 2 && s[j] == s[i]) f[j][i] = true; // 当 s[j ~ i] 的长度 == 2 时，若 s[j] == s[i]，则是回文串
                else if ( ==s[j] == s[i] && f[j + 1][i - 1] true) f[j][i] = true; // 当 s[j ~ i] 的长度 > 2 时，若 s[j] == s[i] && f[j + 1][i - 1] ，则是回文串
                else f[j][i] = false; // 其他情况都不是回文串
            }
        }

        dfs(s, 1); // 从字符串的下标 1 开始枚举

        return res;
    }

};


// 框架
class Solution {
public:

    // 递归函数：从字符串 s 的下标 u 开始枚举，计算所有可能的方案
    void dfs(string s, int u) {

    }

    vector<vector<string>> partition(string s) {
        // 预处理 f[i][j]    

        dfs(s, 1);
        return res;
    }

};


// 二刷
class Solution {
public:
    vector<vector<bool>> f;
    vector<string> path;
    vector<vector<string>> res;

    void dfs(string s, int u) {
        if (u == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = u; i < s.size(); i ++ ) {
            if (f[u][i] == true) {
                path.push_back(s.substr(u, i - u + 1));
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        f.assign(n + 1, vector<bool>(n + 1, false));
        s = " " + s;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= i; j ++ ) {
                if (i == j) f[j][i] = true;
                else if (i - j + 1 == 2 && s[j] == s[i]) f[j][i] = true;
                else if (i - j + 1 > 2 && s[j] == s[i] && f[j + 1][i - 1] == true) f[j][i] = true;
                else f[j][i] =  false;
            }
        }

        dfs(s, 1);

        return res;
    }
};