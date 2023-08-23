
// 纵向扫描

// AcWing
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;

        int len = strs[0].size();

        for (int i = 0; i < len; i ++ ) {
            if (i >= strs[0].size()) return res; // 如果第一个字符串不存在 i 位，则结束比较
                
            char c = strs[0][i]; // 取出第一个字符串中的 i 位字符

            // 扫描其余字符串，进行比较
            for (string& str : strs) {
                if (str.size() <= i || str[i] != c) return res;
            }

            res += c;
        }

        return res;
    }
};


// 官方题解改写（推荐）
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;

        int len = strs[0].size();

        for (int i = 0; i < len; i ++ ) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j ++ ) {
                // 在剩余的字符中，若发现 i 超过其下标，或下标 i 的字符与 c 不同，则结束比较，此时的 res 即为最长公共前缀
                if (i == strs[j].size() || strs[j][i] != c) {
                    return res;
                }
            }
            res += c; // 如果当前下标 i 的字符都相同，则把当前字符 c 加入 res 中
        }

        return res;
    }
};
