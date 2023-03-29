// 滑动窗口，图示见笔记


class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        
        unordered_map<char, int> hash_t; // 字符串 t 中的字母及其个数
        unordered_map<char, int> hash_w; // 滑动窗口中的字母及其个数
        
        for (char c: t) hash_t[c] ++ ;
        
        int cnt = 0; // cnt 表示当前滑动窗口内有效字母（即在字符串 t 中存在的字母）的个数

        // 在字符串 s 中维护一个滑动窗口
        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            // 将字母 s[i] 加入滑动窗口
            hash_w[s[i]] ++ ; 
            // 如果字母 s[i] 加入滑动窗口后，滑动窗口中字母 s[i] 的个数仍然 <= 字符串 t 中字母 s[i] 的个数，则对应有效字母个数 + 1
            if (hash_w[s[i]] <= hash_t[s[i]]) cnt ++ ;

            // 当滑动窗口中字母 s[j] 的个数超过了字符串 t 中字母 s[j] 的个数
            // 则将 j 指针不断右移，直到滑动窗口中字母 s[j] 的个数 <= 字符串 t 中字母 s[j]
            while (hash_w[s[j]] > hash_t[s[j]]) {
                hash_w[s[j]] -- ;
                j ++ ;
            }

            // 如果有效字母的个数正好等于字符串 t 中字母的个数，则找到了一个滑动窗口 s[j ~ i] 包含字符串 t 中的所有字母
            if (cnt == t.size()) {
                // 如果是第一个符合条件的窗口 || 当前窗口的长度 < res 的长度，则把 s[j ~ i] 更新为新的 res
                if (res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};


// 无注释版本

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        
        unordered_map<char, int> hash_t;
        unordered_map<char, int> hash_w;
        
        for (char c: t) hash_t[c] ++ ;
        
        int cnt = 0;

        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            hash_w[s[i]] ++ ; 
            if (hash_w[s[i]] <= hash_t[s[i]]) cnt ++ ;

            while (hash_w[s[j]] > hash_t[s[j]]) {
                hash_w[s[j]] -- ;
                j ++ ;
            }

            if (cnt == t.size()) {
                if (res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};

