
// 滑动窗口 + 哈希表

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // 特判：如果 k == 0，则没有符合条件的子串
        if (k == 0) return 0;

        // 定义一个哈希表，存滑动窗口中的字符及其个数
        unordered_map<char, int> hash;

        int res = 0;
        
        // 枚举字符串，维护长度为 k 的滑动窗口
        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            hash[s[i]] ++ ; // 将 s[i] 滑入窗口

            while (hash.size() > k) {
                hash[s[j]] -- ; // 将 s[j] 滑出窗口
                // 如果 s[j] 滑出窗口后，窗口内 s[j] 个数变为 0，则将 s[j] 从哈希表中删除
                if (hash[s[j]] == 0) {
                    hash.erase(s[j]);
                }
                j ++ ;
            }

            // 更新子串的最大长度
            res = max(res, i - j + 1);
        }

        return res;
    }
};

