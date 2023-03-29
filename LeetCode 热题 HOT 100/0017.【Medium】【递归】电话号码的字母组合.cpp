

// DFS

class Solution {
public:
    string path; // 当前方案
    vector<string> res; // 所有方案

    // 先把每个数字对应的字母记录下来，因为 "abc" 代表的是数字2，所以在前面随便补上两个字符串
    vector<string> list{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    // 递归函数：从字符串 digits 的下标 u 开始判断，将合法序列加入 res
    void dfs(string& digits, int u){
        // 递归出口：如果已经枚举到头了，则将这轮枚举的结果放到最终结果数组中
        if (u == digits.length()){ 
            res.push_back(path);
            return;
        }

        int num = digits[u] - '0'; // 获取当前枚举的数字（将 char 型数字转变为 int 型数字）

        // 枚举当前数字可能对应的所有字母，将其插入 path 后面，然后递归下一个数字可能对应的字母
        for (char c: list[num]) {
            // 选择
            path.push_back(c);
            // dfs
            dfs(digits, u + 1); 
            // 撤销选择
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        // 特判：若是空字符串，返回空数组
        if (digits.empty())  return {}; 

        dfs(digits, 0); 
        return res;
    }
};


// 无注释版本
class Solution {
public:
    string path;
    vector<string> res;

    vector<string> list{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    

    void dfs(string& digits, int u) {
        if (u == digits.length()){ 
            res.push_back(path);
            return;
        }

        int num = digits[u] - '0';

        for (char c: list[num]) {
            path.push_back(c);
            dfs(digits, u + 1); 
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())  return {}; 

        dfs(digits, 0); 
        return res;
    }
};
