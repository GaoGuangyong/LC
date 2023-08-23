

// 滑动窗口
// 相似题目：LC 438 此类问题都是在长串中维护一个滑动窗口，用来匹配短串

// 使用两个哈希表 hash_s1, hash 来分别记录字符串 s1 中每个字母的个数 和 滑动窗口中每个字母的个数
// 先统计字符串 s1 中每个字母的个数，再在字符串 s2 中维护一个滑动窗口
// 计算在这个滑动窗口内每个字母的个数，并用一个计数器 cnt 来实时检查当前滑动窗口内和 s1 中字母匹配的个数
// 如果 cnt 等于 s1 中元素的个数，则说明 s2 包含 s1 的排列之一的子串，返回 true

class Solution {
public:
    unordered_map<char, int> hash_s1; // 字符串 s1 中的字母及其个数
    unordered_map<char, int> hash; // 滑动窗口 中的字母及其个数

    // 辅助函数：判断是否匹配，即判断滑动窗口中的字母 c 是否在 s1 中存在，且个数相同
    bool check(char c) {
        if (hash_s1.count(c) && hash_s1[c] == hash[c]) {
            return true;
        }
        return false;
    }


    bool checkInclusion(string s1, string s2) {
        // 计算短串 s1 中每个字母的个数
        for (char c: s1) hash_s1[c] ++ ;
        
        int cnt = 0; // 表示当前滑动窗口内和 s1 匹配的字母个数

        // 在长串 s2 中维护一个滑动窗口
        for (int i = 0, j = 0; i < s2.size(); i ++ ) {
            if (check(s2[i]) == true) cnt -- ; // 如果当前字母 s2[i] 加入滑动窗口之前，其已经是匹配的了，则加入后就不匹配了，匹配的个数 cnt - 1
            hash[s2[i]] ++ ; // 将当前字母 s2[i] 加入滑动串口，即哈希表 hash 中这个字母的个数的个数 + 1
            if (check(s2[i]) == true) cnt ++ ; // 如果当前字母 s2[i] 加入滑动窗口之后，变成了匹配的了，则匹配的个数 cnt + 1

            // 如果 i 指针右移后，滑动窗口的大小超过了 s1 中元素的个数，则需要将 j 指针右移，删除 s2[j]
            while (i - j + 1 > s1.size()) {
                if (check(s2[j]) == true) cnt -- ; // 如果删除前字母 s2[j] 是匹配的，则删除后就不匹配了，匹配的个数 cnt - 1
                hash[s2[j]] -- ; // 将字母 s2[j] 从滑动串口中删除，即哈希表 hash 中这个字母的个数的个数 - 1
                if (check(s2[j]) == true) cnt ++ ; // 如果删除后，字母 s2[j] 是匹配的，则匹配的个数 cnt + 1
                j ++ ;
            }

            // 如果此时滑动窗口中，匹配的字母个数等于 s1 中的字母个数，即在 s2 中找到了 s1 的排列之一的子串
            if (cnt == hash_s1.size()) return true;
        }

        return false;
    }
};


// 无注释版本
class Solution {
public:
    unordered_map<char, int> hash_s1;
    unordered_map<char, int> hash;

    bool check(char c) {
        return hash_s1.count(c) && hash_s1[c] == hash[c];
    }

    bool checkInclusion(string s1, string s2) {
        for (char c: s1) hash_s1[c] ++ ;

        int cnt = 0;
        for (int i = 0, j = 0; i < s2.size(); i ++ ) {
            if (check(s2[i]) == true) cnt -- ;
            hash[s2[i]] ++ ;
            if (check(s2[i]) == true) cnt ++ ;

            while (i - j + 1 > s1.size()) {
                if (check(s2[j]) == true) cnt -- ;
                hash[s2[j]] -- ;
                if (check(s2[j]) == true) cnt ++ ;
                j ++ ;
            }

            if (cnt == hash_s1.size()) return true;
        }

        return false;
    }
};


// 二刷
class Solution {
public:
    unordered_map<char, int> hash_s1;
    unordered_map<char, int> hash;

    bool check(char c) {
        return (hash_s1.count(c) && hash_s1[c] == hash[c]);
    }

    bool checkInclusion(string s1, string s2) {
        for (char c: s1) hash_s1[c] ++ ;

        int cnt = 0;
        for (int i = 0, j = 0; i < s2.size(); i ++ ) {
            if (check(s2[i]) == true) cnt -- ;
            hash[s2[i]] ++ ;
            if (check(s2[i]) == true) cnt ++ ;
            
            while (i - j + 1 > s1.size()) {
                if (check(s2[j]) == true) cnt -- ;
                hash[s2[j]] -- ;
                if (check(s2[j]) == true) cnt ++ ;
                j ++ ;
            }

            if (cnt == hash_s1.size()) return true;
        }

        return false;
    }
};
