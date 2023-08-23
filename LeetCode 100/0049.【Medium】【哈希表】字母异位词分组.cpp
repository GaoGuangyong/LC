

// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
// 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。



// 将每个字符串排序，将排好序的字符串作为 key ，然后将原字符串插入 key 对应的 vector<string> 中

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 定义从 string 映射到 vector<string> 的哈希表    
        unordered_map<string, vector<string>> hash; 

        // 遍历给定字符串数组中的每一个字符串
        for (string str: strs) { 
            string s = str; // 将当前字符串备份
            sort(s.begin(), s.end()); // 对当前字符串排序
            // 将排好序的字符串作为 key，然后将原字符串插入 key (string) 对应的 value (sring 数组) 中
            hash[s].push_back(str);  
        }

        vector<vector<string>> res; // 结果数组

        // 遍历哈希表，将哈希表中每个 key (string) 对应的 value (sring 数组) 加入结果数组
        for (auto [k, v]: hash) {
            res.push_back(v); 
        }

        return res;
    }
};

// 无注释版本
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        for (string str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            hash[s].push_back(str);
        }

        vector<vector<string>> res;
        
        for (auto [k, v]: hash) {
            res.push_back(v);
        }

        return res;
    }
};