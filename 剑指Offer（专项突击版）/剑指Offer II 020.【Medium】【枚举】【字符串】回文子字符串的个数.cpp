// 每次固定回文子串的中间位置，然后向左右开始扩展
// 每次固定后，分为奇数长度和偶数长度两种情况，然后暴力统计答案

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0; // 结果：回文串的数量

        // 先枚举中心点
        for (int i = 0; i < s.size(); i ++ ) {
            // 枚举字符串长度为奇数的情况，l 从 i 开始向左遍历， r 从 i 开始向右遍历
            for (int l = i, r = i; l >= 0 && r < s.size(); l -- , r ++ ) {
                if (s[l] != s[r]) break;
                res ++ ;
            }

            // 枚举字符串长度为偶数的情况，l 从 i 开始向左遍历， r 从 i 的下一位开始向右遍历
            for (int l = i, r = i + 1; l >= 0 && r < s.size(); l -- , r ++ ) {
                if (s[l] != s[r]) break;
                res ++ ;
            }
        }
        return res;
    }
};

// 无注释版
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.size();

        for (int i = 0; i < n; i ++ ) {
            for (int l = i, r = i; l >= 0 && r < n; l -- , r ++ ) {
                if (s[l] != s[r]) 
                    break;
                else
                    res ++ ;
            }
            for (int l = i, r = i + 1; l >= 0 && r < n; l -- , r ++ ) {
                if (s[l] != s[r]) 
                    break;
                else
                    res ++ ;
            }
        }

        return res;
    }
};

