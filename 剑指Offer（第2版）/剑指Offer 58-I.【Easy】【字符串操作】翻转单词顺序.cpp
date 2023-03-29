

// 字符串操作
// 主要考察如何处理前后的空格 + 两次倒转法


class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        // 遍历字符串，去除多余空格（去除第一个空格，去除连续多个的空格）
        int idx = 0; // idx 表示非空格字符当前要写入的位置
        for (int i = 0; i < n; i ++ ) {
            // 如果是非空格，则保留（写入 s[idx]），继续遍历下一个
            if (s[i] != ' ') {
                s[idx] = s[i];
                idx ++ ;
            }
            // 否则，如果是空格
            else {
                // 如果空格前一个不是空格的话，则保留，继续遍历下一个
                if (idx > 0 && s[idx - 1] != ' ') { 
                    s[idx] = s[i];
                    idx ++ ;
                }
            }
        } // 循环结束后，idx ++ 所以 idx 指向了字符串的最后一个位置的下一个位置

        // 处理最末尾的字符（s[idx - 1]）是一个空格的情况，需单独删掉
        if (idx > 0 && s[idx - 1] == ' ') idx -- ;

        // 只保留 s[0, idx)，将 s[idx, s.end()) 删掉
        s.erase(s.begin() + idx, s.end());

        // 两次倒转法思想：先反转整个字符串，再反转每个单词

        //【1】将整个字符串反转
        reverse(s.begin(), s.end()); 

        //【2】将每个单词反转
        for (int i = 0; i < s.size(); i ++ ) { 
            // 先将 j 指向当前单词的开头
            int j = i; 

            // 只要 j 还没到空格就一直右移，直到 j 指向空格，则当前单词为 s[i ~ j - 1]
            while (j < s.size() && s[j] != ' ') j ++ ; 

            // 将 s[i ~ j) 反转
            reverse(s.begin() + i, s.begin() + j); 

            i = j; // 将 i 指向 j（此时 i 指向的是空格，然后会 i ++ ，因此 i 会继续指向下一个单词的开头）
        }
        
        return s;
    }
};



// 解法二：(笔试推荐)

class Solution {
public:
    string reverseWords(string s) {
        string res;
        string path;

        // 读取字符串 s 中空格分开的单词到 ssin 数据流
        stringstream ssin(s); 

        // 从 ssin 中读入单字到 path
        while (ssin >> path) { 
            // 在 res 的开头不断插入 path + 空格
            res = path + " " + res;
        }

        // 最后会从 ssin 中读入一个空串，所以 res 会 += ' '，需要删掉这个空格
        res.pop_back();

        return res;
    }
};







