

// 哈希表 + 枚举

class Solution {
public:
    char firstUniqChar(string s) {
        char res = ' '; // 无解时返回什么，res 就初始化成什么

        // 定义一个哈希表，存字符串中每个字符及其出现的次数
        unordered_map<char, int> hash;
        for (char c: s) hash[c] ++ ;

        // 再次遍历字符串，找到第一个哈希值为 1 的字符
        for (char c: s) {
            if (hash[c] == 1){
                res = c;
                break;
            }
        }
        return res;
    }
};


// 无注释版本
class Solution {
public:
    char firstUniqChar(string s) {
        char res = ' ';

        unordered_map<char, int> hash; 

        for (char c: s) hash[c] ++ ;

        for (char c: s) {
            if (hash[c] == 1){
                res = c;
                break;
            }
        }

        return res;
    }
};
