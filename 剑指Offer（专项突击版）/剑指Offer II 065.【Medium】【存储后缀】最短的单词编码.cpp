// https://leetcode.cn/problems/iSwD2y/solution/zui-duan-de-dan-ci-bian-ma-by-leetcode-s-qjxw/

// 存储后缀
// 由数据范围可知一个单词最多含有 7 个后缀，所以我们可以枚举单词所有的后缀
// 对于每个后缀，如果其存在 words 数组中，我们就将其从数组中删除
// 为了高效删除，我们将 words 用哈希集合来存储

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // 定义一个哈希集合，存字符串数组 words 中的字符串
        unordered_set<string> S; 
        for (string word : words) S.insert(word);
        
        // 遍历所有单词，将是其他单词后缀的单词删掉
        // 例如：word = "time" 截取所有后缀 ime me e 从哈希集合中删掉，即删掉了所有的后缀
        for (string word: words) {
            for (int k = 1; k < word.size(); k ++ ) {
                S.erase(word.substr(k)); // 从哈希集合中删掉 word.substr(k)
            }
        } // 循环结束后，S 中就只保留了所有不是其他单词后缀的单词

        int res = 0;
        // 最后的结果就是集合中剩余的 单词的长度 + 1 的总和
        for (string word: S) {
            res += (word.size() + 1);
        }
        return res;
    }
};


// 无注释版本
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> S; 
        for (string word : words) S.insert(word);
        
        for (string word: words) {
            for (int k = 1; k < word.size(); k ++ ) {
                S.erase(word.substr(k));
            }
        }

        int res = 0;
        
        for (string word: S) {
            res += (word.size() + 1);
        }
        
        return res;
    }
};

