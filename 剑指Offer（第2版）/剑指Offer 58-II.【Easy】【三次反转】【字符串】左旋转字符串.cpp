
// 三次倒转法

// abcdefg, k = 2
// 1. 将前 k 个字符倒转：    bacdefg
// 2. 后面 n - k 个字符倒转：bagfedc
// 3. 将整个字符串倒转:      cdefgab

class Solution {
public:
    string reverseLeftWords(string s, int k) {
        reverse(s.begin(), s.begin() + k);
        reverse(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};


