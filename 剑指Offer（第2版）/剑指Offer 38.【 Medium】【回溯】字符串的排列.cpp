
// DFS + 回溯
// 模仿 LC 47 题做法

class Solution {
public:
    // 全局变量
    string path; // 当前方案
    vector<string> res; // 所有方案
    vector<bool> visit; // 访问数组，标记哪些字符被使用过
    
    // DFS 函数：u 代表枚举的下标
    void dfs(string str, int u) {
        // 递归出口：一组枚举结束，将 path 中存的字符串加到结果中
        if (path.size() == str.size()) {
            res.push_back(path);
            return;
        }

        // 否则，从 0 开始枚举每一个位置
        for (int i = 0; i < str.size(); i ++ ) {
            // 减枝：如果 s[i] 是重复字母，且 s[i - 1] 没被用过，则跳过
            if (i > 0 && str[i] == str[i - 1] && visit[i - 1] == false) continue;

            // 如果当前的字母 s[i] 没有被用到过
            if (visit[i] == false) {
                // 选择当前元素
                path.push_back(str[i]);
                visit[i] = true;
                // 递归
                dfs(str, u + 1);
                // 撤销选择
                visit[i] = false;
                path.pop_back();
            }
        }
    }

    // 主函数
    vector<string> permutation(string s) {
        sort(s.begin(), s.end()); // 先对字符串进行排序，这样一来，在枚举的时候就是按序枚举
        visit.assign(s.size(), false); // 初始化 visit 数组，全部赋值为 false，代表每一个都没有被使用过
        
        dfs(s, 0);

        return res;
    }
};


// 无注释版本
class Solution {
public:
    string path;
    vector<string> res; 
    vector<bool> visit; 
    
    void dfs(string str, int u) {
        if (path.size() == str.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < str.size(); i ++ ) {
            if (i > 0 && str[i] == str[i - 1] && visit[i - 1] == false) continue;

            if (visit[i] == false) {
                path.push_back(str[i]);
                visit[i] = true;

                dfs(str, u + 1);

                visit[i] = false;
                path.pop_back();
            }
        }
    }

    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        visit.assign(s.size(), false);
        
        dfs(s, 0);

        return res;
    }
};

