// 滑动窗口
// 使用两个哈希表 hash_p, hash_w 来分别记录字符串 p 中每个字母的个数 和 滑动窗口中每个字母的个数
// 先记录字符串 p 中每个字母的个数
// 再在字符串 s 中维护一个滑动窗口，计算在这个滑动窗口内每个字母的个数，并用一个计数器 cnt 来实时检查当前滑动窗口内和 p 中字母匹配的个数（匹配：字母在 p 中存在，且个数相同）
// 如果 cnt 等于 p 中元素的个数，则说明找 s2 包含 s1 的排列之一的子串，返回 true 即可

class Solution {
public:
    unordered_map<char, int> hash_p; // 字符串 p 中每个字母及其个数
    unordered_map<char, int> hash_w; // 滑动窗口 中每个字母及其个数

    // 判断是否匹配，即：检查的滑动窗口中的字母 c 是否在 p 中存在，且个数相同
    bool check(char c) {
        if (hash_p.count(c) == 1 && hash_p[c] == hash_w[c]) {
            return true;
        }
        return false;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res; // 定义结果数组

        // 记录字符串 p 中每个字母的个数
        for (char c: p) hash_p[c] ++ ;
        

        // 在字符串 s 中维护一个滑动窗口
        int  cnt = 0; // cnt 表示当前滑动窗口内和 p 匹配的字母个数
        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            // 如果当前字母 s[i] 加入滑动窗口之前，其已经是匹配的了，则加入后就不匹配了，匹配的个数 cnt - 1
            if (check(s[i]) == true) cnt -- ;
            hash_w[s[i]] ++ ; // 将当前字母 s[i] 加入滑动串口（滑动窗口中，s[i] 的个数 + 1）
            // 如果当前字母 s[i] 加入滑动窗口之后，变成了匹配的了，则匹配的个数 cnt + 1
            if (check(s[i]) == true) cnt ++ ;

            // 如果 i 指针右移后，滑动窗口的大小超过了 p 中字母的个数，则需要将 j 指针右移，删除 s[j]
            if (i - j + 1 > p.size()) {
                // 如果删除前字母 s[j] 是匹配的，则删除后就不匹配了，匹配的个数 cnt - 1
                if (check(s[j]) == true) cnt -- ;
                hash_w[s[j]] -- ; // 将字母 s[j] 从滑动串口中删除（滑动窗口中，s[j] 的个数 - 1）
                // 如果删除后，字母 s[j] 是匹配的，则匹配的个数 cnt + 1
                if (check(s[j]) == true) cnt ++ ;
                j ++ ;
            }

            // 如果此时滑动窗口 [j, i] 中，匹配的字母个数等于 p 中的字母个数
            // 则所有的字母均匹配成功，那么也就是在 s 中找到了该子串，是字符串 p 的异位词
            if (cnt == hash_p.size()) res.push_back(j);
            
        }
        return res;
    }
};

// 无注释版本
class Solution {
public:
    unordered_map<char, int> hash_p;
    unordered_map<char, int> hash_w;

    bool check(char c) {
        if (hash_p.count(c) && hash_p[c] == hash_w[c]) return true;
        return false;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        for (auto c: p) hash_p[c] ++ ;
        
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            if (check(s[i]) == true) cnt -- ;
            hash_w[s[i]] ++ ;
            if (check(s[i]) == true) cnt ++ ;

            if (i - j + 1 > p.size()) {
                if (check(s[j]) == true) cnt -- ;
                hash_w[s[j]] -- ;
                if (check(s[j]) == true) cnt ++ ;
                j ++ ;
            }

            if (cnt == hash_p.size()) res.push_back(j);
        }

        return res;
    }

    
};
