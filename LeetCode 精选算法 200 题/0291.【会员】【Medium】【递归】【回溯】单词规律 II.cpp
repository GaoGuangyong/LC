
// DFS + 回溯

class Solution {
public:
    unordered_map<char, string> hash; // 定义一个哈希表，存字母->单词的映射
    string pattern; // 将字符串 pattern 声明成全局变量

    // DFS 函数：从 pattern 的下标 index 开始匹配，返回是否匹配成功（true/false）
    bool dfs(int index, string s) {
        // 递归出口：index 指向 pattern 最后一个字符的下一个位置，此时 s 为空串则匹配成功
        if (index == pattern.size()) return s == "";
        // 获取当前要映射的字母
        char c = pattern[index];
        // 如果已经有映射的字符串，则判断该字符串是否 = s[0 ~ hash[c].size())，如果相等，则继续递归
        if (hash[c] != "") {
            if (hash[c] == s.substr(0, hash[c].size()))
                return dfs(index + 1, s.substr(hash[c].size()));
            return false;
        }
        // 如果没有映射，开始探索
        else {   
            string str; // 当前字符映射的字符串
            // 遍历字符串 s
            for (int i = 0; i < s.size(); i ++ ) {
                str += s[i];
                hash[c] = str; // 当前字符 c 映射的字符串就是 str

                // 不同的字符不能映射相同的字符串，因此要重复检测
                // 遍历哈希表，如果发现存在和 c 不同的字符，也映射到了 str，则跳过
                bool back1 = true;
                for (auto [k, v]: hash) {
                    if (k != c && v == str) {
                        back1 = false;
                        break;
                    }
                }
                if (back1 == false) continue;

                // 确定后续使用正确：在 s 中截去 c 映射的字符串
                bool back2 = dfs(index + 1, s.substr(hash[c].size()));
                if (back2 == true) return true;
            }

            // 结束探索一定要恢复现场
            hash[c] = "";
        }

        return false;
    }
    // 主函数
    bool wordPatternMatch(string _pattern, string s) {
        pattern = _pattern;
        return dfs(0, s); // 从 pattern 的下标 0 开始匹配
    }
};

