

// DP -> 类似 LC 1143
// f[i][j] 表示 s1 的 [1 ~ i] 和 s2 的 [1 ~ j] 的公共子串长度（下标从 1 开始）

#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // 使较短的字符串为 s1
    if (s1.size() > s2.size()) swap(s1, s2);

    int n = s1.size();
    int m = s2.size();
    
    s1 = ' ' + s1;
    s2 = ' ' + s2;

    vector<vector<int> > f(n + 1, vector<int>(m + 1));

    int maxLen = 0; // 最长公共子串的长度
    int end = 0; // 最长公共子串的结尾下标

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            if (s1[i] == s2[j]) 
                f[i][j] = f[i - 1][j - 1] + 1;
            // 如果第 i 个字符和第 j 个字符不同，则以他们结尾的子串不可能相同
            else 
                f[i][j] = 0;

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

