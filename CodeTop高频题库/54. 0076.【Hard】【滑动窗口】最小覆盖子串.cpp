

// 给你一个字符串 s 和 一个字符串 t
// 返回 s 中涵盖 t 所有字符的最小子串
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"

// 滑动窗口，图示见笔记
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash_t; // 定义哈希表 hash_t，存字符串 t 中的字母及其个数
        for (char c: t) hash_t[c] ++ ;

        unordered_map<char, int> hash; // 定义哈希表 hash，滑动窗口中的字母及其个数
        
        int cnt = 0; // cnt 表示当前滑动窗口内有效字母（即在字符串 t 中存在的字母）的个数
        string res = ""; // 结果字符串

        // 在字符串 s 中维护一个滑动窗口
        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            // 将字母 s[i] 加入滑动窗口
            // 如果字母 s[i] 加入滑动窗口后，滑动窗口中字母 s[i] 的个数仍 <= 字符串 t 中字母 s[i] 的个数，则对应有效字母个数 + 1
            hash[s[i]] ++ ; 
            if (hash[s[i]] <= hash_t[s[i]]) cnt ++ ;

            // 如果字母 s[i] 加入滑动窗口后，滑动窗口中字母 s[j] 的个数超过了字符串 t 中字母 s[j] 的个数
            // 则将 j 指针不断右移，直到滑动窗口中字母 s[j] 的个数 <= 字符串 t 中字母 s[j]
            while (hash[s[j]] > hash_t[s[j]]) {
                hash[s[j]] -- ;
                j ++ ;
            }

            // 如果有效字母的个数正好等于字符串 t 中字母的个数，则找到了一个滑动窗口 s[j ~ i] 包含字符串 t 中的所有字母
            if (cnt == t.size()) {
                // 如果是第一个符合条件的窗口 或 当前窗口的长度 比 res 的长度更小，才把 s[j ~ i] 更新为新的 res
                if (res.empty() || i - j + 1 < res.size()) {
                    res = s.substr(j, i - j + 1);
                }
            }
        }

        return res;
    }
};



// 无注释版本
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash_t;
        for (char c: t) hash_t[c] ++ ;

        unordered_map<char, int> hash;

        int cnt = 0;
        string res = "";

        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            hash[s[i]] ++ ;
            if (hash[s[i]] <= hash_t[s[i]]) cnt ++ ;

            while (hash[s[j]] > hash_t[s[j]]) {
                hash[s[j]] -- ;
                j ++ ;
            }
            
            if (cnt == t.size()) {
                if (res.empty() || i - j + 1 < res.size()) res = s.substr(j, i - j + 1);
            }
        }

        return res;
    }
};


