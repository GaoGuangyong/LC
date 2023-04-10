

// 双指针

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int maxLen = 0; // 最长连续数字子串的长度

        // 记录最长数字子串的起始位置，如果有多个相同长度的，则记录多个起始位置
        vector<int> index;

        // 遍历字符串
        for (int i = 0; i < s.size(); i ++ ) {
            if (isdigit(s[i])) {
                int j = i + 1;
                // 找到一个连续的数字子串 [i ~ j - 1]
                while (isdigit(s[j])) j ++ ;
                // 如果当前子串的长度 = 最大子串的长度，则追加当前子串的起始下标
                if ((j - i) == maxLen) {
                    index.push_back(i);
                }
                // 如果当前子串的长度 > 最大子串的长度，则更新最大子串的长度
                if ((j - i) > maxLen) {
                    maxLen = j - i;
                    index.clear(); // 清空 index 数组后
                    index.push_back(i); // 再记录当前子串的起始下标
                }
                i = j; // 把 i 移动到 j，因为循环后会 i ++ 
            } 
        }

        // 遍历 index 数组，输出所有的 {最长连续数字子串}
        for (int i = 0; i < index.size(); i ++ ) {
            // 从 s[index[i]] 开始，输出连续 maxLen 个字符
            for (int k = 0; k < maxLen; k ++ ) {
                cout << s[index[i] + k];
            }
        }
        // 然后输出 , + maxLen
        cout << ',' << maxLen << endl;
    }
    return 0;
}



