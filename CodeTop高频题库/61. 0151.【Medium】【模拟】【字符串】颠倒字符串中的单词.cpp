// 模拟
// 主要考察如何处理前后的空格

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        // 去除多余空格
        int idx = 0;
        for (int i = 0; i < n; i ++ ) {
            if (s[i] != ' ') { // 如果是非空格，则保留，继续遍历下一个
                s[idx] = s[i];
                idx ++ ;
            }
            // 如果是空格，但如果不是整个字符串的第一个空格，且空格前一个不是空格的话，则保留，继续遍历下一个
            else if (idx != 0 && s[i] == ' ' && s[idx - 1] != ' ') {
                s[idx] = s[i];
                idx ++ ;
            }
        } // 循环结束后，idx ++ 所以 idx 指向了字符串的最后一个位置的下一个位置

        // 处理最末尾是一个空格的情况
        if (idx != 0 && s[idx - 1] == ' ') idx -- ;
        // 只保留[0, idx)，将[idx, s.end()) 删掉
        s.erase(s.begin() + idx, s.end()); // string.erase(pos,n) //删除从pos开始的n个字符

        // 两次倒转法思想：操作分解：先反转整个字符串，再反转每个单词
        reverse(s.begin(), s.end()); // 【1】将整个字符串反转
        for (int i = 0; i < s.size(); i ++ ) { // 【2】将每个单词反转
            int j = i; // 先将 j 指向当前单词的开头
            while (j < s.size() && s[j] != ' ') j ++ ; // 只要 j 还没到空格就一直右移，直到 j 指向空格
            reverse(s.begin() + i, s.begin() + j); // 将 s[i ~ j) 反转
            i = j; // 将 i 指向 j（此时 i 指向的是空格，但因为循环后会 i ++ ，因此 i 会继续指向下一个单词的开头）
        }
        return s;
    }
};
