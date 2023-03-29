
// 滑动窗口

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 定义一个哈希表，记录当前滑动窗口内各字母的个数
        unordered_map<char, int> hash;
        
        int res = 0;
        
        // 维护一个滑动窗口
        for (int i = 0, j = 0; i < s.size(); i ++) {
            hash[s[i]] ++ ; // 右指针 i 所指的字母的数量 + 1

            // 如果 i 右移后导致出现了重复字母，则 j 不断向右移动，直到滑动窗口内不再有重复字母
            while (hash_w[s[i]] == 2) {
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
            while (hash[s[i]] == 2) {
                hash[s[j]] -- ;
                j ++ ;
            }
            res = max(res, i - j + 1);
        }

        return res;
    }
};
