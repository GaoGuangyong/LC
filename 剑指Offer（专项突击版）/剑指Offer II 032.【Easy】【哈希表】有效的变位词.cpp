// 使用两个哈希表，分别存两个字符串中出现的字符及其个数，最后在对比两个哈希表是否相同

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 特判：如果 s 和 t 完全相同，则不行
        if (s == t) return false;

        unordered_map<char, int> hash_s, hash_t;
        
        for (char c: s) hash_s[c] ++ ;
        for (char c: t) hash_t[c] ++ ;

        if (hash_s == hash_t) return true;
        
        return false;
    }
};

// 类似：LC 242（可以完全相同）
class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> hash_s, hash_t;
        
        for (char c: s) hash_s[c] ++ ;
        for (char c: t) hash_t[c] ++ ;

        if (hash_s == hash_t) return true;
        
        return false;
    }
};
