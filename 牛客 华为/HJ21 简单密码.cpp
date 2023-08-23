
#include <bits/stdc++.h>
using namespace std;

// 根据题意，将所有输入字符对应的输出字符预先定义好
string dict1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // 解密前字典
string dict2 = "bcdefghijklmnopqrstuvwxyza22233344455566677778889999"; // 解密后字典

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i ++ ) { // 遍历字符串 s
        for (int j = 0; j < dict1.size(); j ++ ) { // 遍历解密前字典 dict1
            // 如果在解密前字典里才找到了当前办理的字符 s[i]，则将其替换为解密后字典里的字符
            if (s[i] == dict1[j]) {
                s[i] = dict2[j];
                break; // 退出内层循环，无需继续查找 dict1 了
            }
        }
    };

    cout << s << endl;

    return 0;
}


