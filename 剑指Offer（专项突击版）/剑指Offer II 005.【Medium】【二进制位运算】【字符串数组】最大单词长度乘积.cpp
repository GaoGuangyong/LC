// 本题要求快速判断两个单词是否含有相同字母
// 因为仅包含小写字母，共有 26 个，不超过 int 的长度范围，因此可以考虑使用 int 型整数来表示某个单词
// 该整数的二进制表示的第 0 位是 1 表示存在字母 a，第 1 位是 0 表示不存在字母 b，以此类推
// 故只需判断两个单词对应的 int 型整数的二进制表示是否相同，就能判断这两个单词所包含的字母是否相同

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        // 先求一下每个单词包含哪些字母，以 int 型整数的形式存在 state 数组中
        vector<int> state; // stat[i] 表示下标为 i 的单词包含的字母有哪些

        // 枚举 words 数组中的每一个单词 word
        for (string word: words) {
            int s = 0;
            // 枚举当前单词的每一位字母 c，将 state 的对应位 置为 1
            for (char c: word) {
                // 先将 1 左移 c - 'a' 位，再将左移后的结果 | s，就可以将 s 的 c - 'a' 位 置为 1，而其余位置保持不变           
                s |= (1 << (c - 'a')); 
            }
            // 枚举完当前单词后，s 就是当前单词对应的 int 型整数，将 s 插入 state 数组中即可
            state.push_back(s);
        }

        int res = 0;

        // 俩俩比较
        for (int i = 0; i < n; i ++ ) {
            for (int j = i + 1; j < n; j ++ ) {
                // 如果 state[i] & state[j] == 0，则说明 state[i] 和 state[j] 的二进制表示的每一位都不会是两个 1，故不存在相同的字母
                if ((state[i] & state[j]) == 0) 
                    res = max(res, (int)(words[i].size() * words[j].size())); // 计算两个单词的长度乘积，更新长度乘积的最大值
            }
        }
        
        return res;
    }
};

// 无注释版
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> state;

        for (string word: words) {
            int s = 0;
            for (char c: word) {
                s |= (1 << (c - 'a'));
            }
            state.push_back(s);
        }

        int res = 0;
        int n = words.size();

        for (int i = 0; i < n; i ++ ) {
            for (int j = i + 1; j < n; j ++ ) {
                if ((state[i] & state[j]) == 0) {
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
            }
        }

        return res;
    }
};

