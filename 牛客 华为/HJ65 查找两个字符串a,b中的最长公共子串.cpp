
// 题意：
// 输入两个字符串，输出这两个字符串的最长公共子串

// 输入：
// abcdefghijklmnop
// abcsafjklmnopqrstuvw

// 输出：
// jklmnop



// DP -> 类似 LC 1143，但输出的是子串，而不是子串的长度

#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // 使较短的字符串为 s1
    if (s1.size() > s2.size()) swap(s1, s2);

    int m = s1.size();
    int n = s2.size();
    
    s1 = ' ' + s1;
    s2 = ' ' + s2;

    vector<vector<int>> f(m + 1, vector<int>(n + 1)); // f[i][j] 表示 s1 的 [1 ~ i] 和 s2 的 [1 ~ j] 的公共子串长度（下标从 1 开始）

    int maxLen = 0; // 最长公共子串的长度
    int end = 0; // 最长公共子串的结尾下标，则起点下标为 end - maxLen + 1

    for (int i = 1; i <= m; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            // 只有当第 i 个字符和第 j 个字符相同时，最长公共子串才能 + 1
            if (s1[i] == s2[j]) f[i][j] = f[i - 1][j - 1] + 1;
            // 如果第 i 个字符和第 j 个字符不同，则以他们结尾的子串不可能相同
            else f[i][j] = 0;

            // 更新最大长度 及结尾下标
            if (f[i][j] > maxLen) {
                maxLen = f[i][j];
                end = i;
            }
        }
    }

    cout << s1.substr(end - maxLen + 1, maxLen) << endl; // 输出最长子串
    
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() > s2.size()) swap(s1, s2);  // 注意 ！！！！！ 一定要先判断，再求长度

    int m = s1.size();
    int n = s2.size();

    s1 = " " + s1;
    s2 = " " + s2;

    vector<vector<int>> f(m + 1, vector<int>(n + 1));

    int len = 0;
    int end = 0;

    for (int i = 1; i <= m; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            if (s1[i] == s2[j]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = 0;

            if (f[i][j] > len) {
                len = f[i][j];
                end = i;
            }
        }
    }

    cout << s1.substr(end - len + 1, len) << endl;

    return 0;
}

