

// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

// 递归
class Solution {
public:
    string path; // 当前方案
    vector<string> res; // 所有方案

    // 先把每个数字对应的字母记录下来，因为 "abc" 代表的是数字 2，所以在前面随便补上两个字符串
    vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    // DFS 函数：从字符串 s 的下标 u 开始判断，将合法序列加入 res
    void dfs(string& s, int u) {
        // 递归出口：如果已经枚举到头了，则将这轮枚举的结果放到最终结果数组中
        if (u == s.size()) { 
            res.push_back(path);
            return;
        }

        int num = s[u] - '0'; // 获取当前枚举的数字（将 char 型数字转变为 int 型数字）

        // 枚举当前数字可能对应的所有字母，将其插入 path 后面，然后递归下一个数字可能对应的字母
        for (char c: keyboard[num]) {
            // 选择
            path.push_back(c);
            // dfs
            dfs(s, u + 1); 
            // 撤销选择
            path.pop_back();
        }
    }

    // 主函数：返回数字字符串 digits 所能表示的所有字母组合
    vector<string> letterCombinations(string digits) {
        if (digits.empty())  return {}; // 特判：若是空字符串，返回空数组 

        dfs(digits, 0);

        return res;
    }
};


// 无注释版本
class Solution {
public:
    string path;
    vector<string> res;

    vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void dfs(string& s, int u) {
        if (u == s.size()) {
            res.push_back(path);
            return;
        }

        int num = s[u] - '0';

        for (char c: keyboard[num]) {
            path.push_back(c);
            dfs(s, u + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())  return {}; 

        dfs(digits, 0); 

        return res;
    }
};


// 二刷
class Solution {
public:
    string path;
    vector<string> res;

    vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string s, int u) {
        if (u == s.size()) {
            res.push_back(path);
            return;
        }

        int num = s[u] - '0';

        for (char c: keyboard[num]) {
            path += c;
            dfs(s, u + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        dfs(digits, 0);
        return res;
    }
};

