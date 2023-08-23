
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

// 递归
// 括号的对数为 n，即共有 n 个左括号和 n 个右括号

// 合法的括号序列:
// [1] 左括号数 == 右括号数
// [2] 序列的任意前缀中，左括号数 >= 右括号数

// 因为本题自动满足条件 [1] 所以只需要关注条件 [2]
// 方法：
// 对于每个位置，判断一下是能填左括号还是右括号
// 能填左括号：需要满足 左括号数 < n，即随时可以填左括号
// 能填右括号：需要满足 右括号数 < n 且 左括号数 > 右括号数，即只有左括号数 > 右括号数时，可以填右括号 

class Solution {
public:
    vector<string> res; // 最终结果：字符串数组

    // DFS 函数：总共有 n 对括号可用，当前括号序列 path 中包含 l_count 个左括号，r_count 个右括号，生成所有可能的括号序列
    void dfs(int n, int l_count, int r_count, string path) {
        // 递归出口：如果左括号和右括号都用完了，则把 path 加到结果数组 res 中
        if (l_count == n && r_count == n) res.push_back(path);
        
        // 如果左括号没填完，则填左括号（l_count + 1）
        if (l_count < n) {
            dfs(n, l_count + 1, r_count, path + '(');
        }
        // 如果右括号没填完，且当前括号序列中的左括号数 > 右括号数，则填右括号（r_count + 1）
        if (r_count < n && l_count > r_count) {
            dfs(n, l_count, r_count + 1, path + ')');
        }
    }

    // 主函数：给定 n，返回所有可能的合法括号序列
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, ""); // 初始时，括号序列中的左右括号的数量均为 0，括号序列 path 为空 ""
        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> res;

    void dfs(int n, int l_count, int r_count, string path) {
        if (l_count == n && r_count == n) res.push_back(path);
        
        if (l_count < n) dfs(n, l_count + 1, r_count, path + '(');
        if (r_count < n && l_count > r_count)  dfs(n, l_count, r_count + 1, path + ')');
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }
};


// 二刷
class Solution {
public:
    vector<string> res;
    void dfs(int n, int l_cnt, int r_cnt, string path) {
        if (l_cnt == n && r_cnt == n) res.push_back(path);
        if (l_cnt < n) dfs(n, l_cnt + 1, r_cnt, path + '(');
        if (r_cnt < n && l_cnt > r_cnt) dfs(n, l_cnt, r_cnt + 1, path + ')');
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }
};
