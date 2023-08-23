#include <iostream>
#include <string>

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) { // 循环读入 N 行字符串，等价于 while (cin >> s)
        int n = s.size();

        // 特判条件 1：若读入字符串的长度 <= 8 则输出 NG，继续判断下一个字符串
        if (n <= 8) {
            cout << "NG" << endl;
            continue;
        }

        // 特判条件 2
        vector<int> flag(4); // 定义一个长度为 4 的数组，标记密码是否包含大写字母、小写字母、数字和其他字符
        for (int i = 0; i < n; i ++ ) { // 遍历密码字符串中的每个字符
            if (s[i] >= 'A' && s[i] <= 'Z') flag[0] = 1; // 标记包含大写字母
            else if (s[i] >= 'a' && s[i] <= 'z') flag[1] = 1; // 标记包含小写字母
            else if (s[i] >= '0' && s[i] <= '9') flag[2] = 1; // 标记包含数字
            else flag[3] = 1; // 标记包含其他字符
        }
        if (flag[0] + flag[1] + flag[2] + flag[3] < 3) { // 若字符类型少于三种，则输出 NG，继续判断下一个
            cout << "NG" << endl;
            continue;
        } 

        // 判断条件 3
        bool repeat = false; // 记录重复子串
        for (int i = 0; i <= n - 6; i ++ ) { // 枚举字符串，检查是否有长度为 3 的相同的字串
            for (int j = i + 3; j < n; j ++ ) {
                if (s.substr(i, 3) == s.substr(j, 3)) { // 判断 s[i ~ i + 3) 和 s[j ~ j + 3) 是否相等
                    repeat = true;
                    break;
                }
            }
        }
        if (repeat == true) cout << "NG" << endl;
        else cout << "OK" << endl;
    }

    return 0;
}

