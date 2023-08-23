// 解法二：O(n^3) 推荐写法
// 参考 https://leetcode-cn.com/problems/word-break/solution/dan-ci-chai-fen-by-leetcode-solution/

// DP
// 状态表示：
// f[i] 表示 s[0 ~ i - 1] 是否为合法的单词拆分方案，则答案是 f[n]

// 初始化：
// f[0] = true 表示空串合法

// 状态转移：
// 在 0 ~ i - 1 之间枚举分割点 j，看 s1 = s[0 ~ j - 1] 和 s2 = s[j ~ i - 1] 是否都合法
// 字符串 s1 是否合法可以直接由 f[j] 得到
// 字符串 s2 是否合法则需要判断 s2[j ~ i - 1] 是否在字典中出现

// 因此 f[i] = f[j] && hash.count(s.substr(j, i - j))

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        // 定义哈希集合，存 wordDict 中的每个 word
        unordered_set<string> S;
        for (auto word: wordDict) S.insert(word);

        // 定义状态数组
        vector<bool> f(n, false);

        // 初始化
        f[0] = true;

        // 状态转移
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 0; j < i; j ++ ) {
                if (f[j] == true && S.count(s.substr(j, i - j))) {
                    f[i] = true;
                    break;
                }
            }
        }

        return f[n];
    }
};

// 无注释版本
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> S;
        for (auto word: wordDict) S.insert(word);

        vector<bool> f(n);

        f[0] = true;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 0; j < i; j ++ ) {
                if (f[j] == true && S.count(s.substr(j, i - j))) {
                    f[i] = true;
                    break;
                }
            }
        }

        return f[n];
    }
};


