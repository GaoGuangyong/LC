

// 题意：

// 输入一个字符串
// 输出字符串中最长的数字字符串和它的长度，中间用逗号间隔。如果有相同长度的串，则要一块儿输出（中间不要输出空格）

// 本题含有多组样例输入



// 双指针

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int maxLen = 0; // 最长连续数字子串的长度

        vector<int> idx; // 定义一个数组来记录最长数字子串的起始下标，如果有多个相同长度的，则记录多个起始下标

        // 遍历字符串，如果是数字，则用 j 向后找到数字的结尾
        for (int i = 0; i < s.size(); i ++ ) {
            if (isdigit(s[i])) {
                // j 从 i + 1 开始，不断向后遍历，找到一个连续的数字子串 [i ~ j - 1]
                int j = i + 1;
                while (isdigit(s[j])) j ++ ;

                // 如果当前子串的长度 = 最大子串的长度，则追加当前子串的起始下标
                if ((j - i) == maxLen) {
                    idx.push_back(i);
                }

                // 如果当前子串的长度 > 最大子串的长度，则更新最长连续数字子串的长度
                if ((j - i) > maxLen) {
                    maxLen = j - i;
                    idx.clear(); // ！！！！！ 清空 idx 数组
                    idx.push_back(i); // 再记录当前最长连续数字子串的起始下标
                }

                i = j; // 把 i 移动到 j，因为循环后会 i ++ 
            } 
        }

        // 遍历 idx 数组，输出所有的 <最长连续数字子串,长度>
        // 先输出子串
        for (int i = 0; i < idx.size(); i ++ ) {
            // 从 s[idx[i]] 开始，输出连续 maxLen 个字符
            for (int k = 0; k < maxLen; k ++ ) {
                cout << s[idx[i] + k];
            }
        }
        // 然后输出 , + 长度
        cout << ',' << maxLen << endl;
    }

    return 0;
}



