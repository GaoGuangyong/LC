

// 题意：
// 输入两行字符串，求两个字符串的最少编辑距离

// DP -> LC 72

// 状态表示：
// f[i][j] 表示将 s1[1 ~ i] 变成 s2[1 ~ j] 所有按顺序操作的方案里，操作次数的最小值

// 初始化：
// 当某个字符串的长度为 0，则需要操作的次数为另一个字符串的长度

// 状态转移：
// 对于 s1 有三种情况
//【删】删除 s1[i] 后 s1 和 s2 相等，说明删之前 s1[1 ~ i - 1] 和 s2[1 ~ j] 已经相等了
//      f[i][j] = f[i - 1][j] + 1
//【插】在 s1[i] 后插入 s2[j] 后 s1 和 s2 相等，说明插入之前 s1[1 ~ i] 和 s2[1 ~ j - 1] 已经相等了
//      f[i][j] = f[i][j - 1] + 1
//【改】修改 s1[i] 后 s1 和 s2 相等，说明修改之前 s1[1 ~ i - 1] 和 s2[1 ~ j - 1] 已经相等了
//      f[i][j] = f[i - 1][j - 1] + 1 (当 s1[i] != s2[j])
//      f[i][j] = f[i - 1][j - 1] + 0 (当 s1[i] == s2[j]，则不需要修改，操作次数 + 0)
// 最终结果为上述三种情况取 min

// 同理，对于 s2 也有三种情况

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int m = s1.size();
    int n = s2.size();

    s1 = ' ' + s1;
    s2 = ' ' + s2;

    // 定义状态数组
    vector<vector<int>> f(m + 1, vector<int>(n + 1));

    // 初始化：当某个字符串的长度为 0，则需要操作的次数为另一个字符串的长度
    for (int i = 1; i <= m; i ++ ) f[i][0] = i;
    for (int j = 1; j <= n; j ++ ) f[0][j] = j;

    // 状态转移
    for (int i = 1; i <= m; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            int op1 = f[i - 1][j] + 1; // 删
            int op2 = f[i][j - 1] + 1; // 插
            int op3 = f[i - 1][j - 1]; // 改
            if (s1[i] != s2[j]) op3 ++ ;
            
            f[i][j] = min(min(op1, op2), op3); // 替换操作和删除操作取最小
        }
    }

    cout << f[m][n] << endl;
}



// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int m = s1.size();
    int n = s2.size();

    s1 = ' ' + s1;
    s2 = ' ' + s2;

    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i ++ ) f[i][0] = i;
    for (int j = 1; j <= n; j ++ ) f[0][j] = j;

    for (int i = 1; i <= m; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            int op1 = f[i - 1][j] + 1;
            int op2 = f[i][j - 1] + 1;
            int op3 = f[i - 1][j - 1];
            if (s1[i] != s2[j]) op3 ++ ;

            f[i][j] = min(op1, min(op2, op3));
        }
    }

    cout << f[m][n] << endl;

    return 0;
}


