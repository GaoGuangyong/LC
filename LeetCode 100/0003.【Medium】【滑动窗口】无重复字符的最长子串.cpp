
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

// 滑动窗口

class Solution {
public:
    int lengthOfLongestSubstring(string s) {      
        unordered_map<char, int> hash; // 定义一个哈希表，记录滑动窗口中的字母及其个数
        
        int res = 0;
        
        // 维护一个滑动窗口
        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            hash[s[i]] ++ ; // 将 s[i] 加入滑动窗口，其个数 + 1

            // 如果 i 右移后导致 s[i] 出现了重复，则 j 不断向右移动，直到 s[i] 在滑动窗口内的个数 < 2
            while (hash[s[i]] >= 2) {
                hash[s[j]] -- ;
                j ++ ;
            } // 该循环结束后就得到了一个不含重复字母的子串 [j, i]

            res = max(res, i - j + 1); // 更新子串长度的最大值
        }

        return res;
    }
};



// 无注释版本
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0;

        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            hash[s[i]] ++ ;
            while (hash[s[i]] >= 2) {
                hash[s[j]] -- ;
                j ++ ;
            }
            res = max(res, i - j + 1);
        }

        return res;
    }
};

