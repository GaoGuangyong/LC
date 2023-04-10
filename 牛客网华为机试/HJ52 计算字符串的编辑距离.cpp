

// DP -> LC 72

// 状态表示：
// f[i][j] 表示将 str1[1 ~ i] 变成 str2[1 ~ j] 所有按顺序操作的方案里，操作次数的最小值

// 初始化：
// 当某个字符串的长度为 0，则需要操作的次数为另一个字符串的长度

// 状态转移：
// 对于 str1 有三种情况
//【删】删除 str1[i] 后 str1 和 str2 相等，说明删之前 str1[1 ~ i - 1] 和 str2[1 ~ j] 已经相等了
//      f[i][j] = f[i - 1][j] + 1
//【插】在 str1[i] 后插入 str2[j] 后 str1 和 str2 相等，说明插入之前 str1[1 ~ i] 和 str2[1 ~ j - 1] 已经相等了
//      f[i][j] = f[i][j - 1] + 1
//【改】修改 str1[i] 后 str1 和 str2 相等，说明修改之前 str1[1 ~ i - 1] 和 str2[1 ~ j - 1] 已经相等了
//      f[i][j] = f[i - 1][j - 1] + 1 (当 str1[i] != str2[j])
//      f[i][j] = f[i - 1][j - 1] + 0 (当 str1[i] == str2[j]，则不需要修改，操作次数 + 0)
// 最终结果为上述三种情况取 min

// 同理，对于 str2 也有三种情况

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    str1 = ' ' + str1;
    str2 = ' ' + str2;

    // 定义状态数组
    vector<vector<int>> f(n + 1, vector<int>(m + 1));

    // 初始化：当某个字符串的长度为 0，则需要操作的次数为另一个字符串的长度
    for (int i = 1; i <= n; i ++ ) f[i][0] = i;
    for (int j = 1; j <= m; j ++ ) f[0][j] = j;

    // 状态转移
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            int op1 = f[i - 1][j] + 1; // 删
            int op2 = f[i][j - 1] + 1; // 插
            int op3 = f[i - 1][j - 1]; // 改
            if (str1[i] != str2[j]) op3 ++ ;
            
            f[i][j] = min(min(op1, op2), op3); // 替换操作和删除操作取最小
        }
    }

    cout << f[n][m] << endl;
}

