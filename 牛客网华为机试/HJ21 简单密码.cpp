#include <iostream>
using namespace std;

// 根据题意，将所有输入字符对应的输出字符预先定义好
const string dict1="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // 解密前字典
const string dict2="bcdefghijklmnopqrstuvwxyza22233344455566677778889999"; // 解密后字典

int main() {
    string str;
    while (cin >> str) {
        // 用 i 遍历输入字符串 str，用 j 遍历解密前字典
        for (int i = 0; i < str.size(); i ++ ) {
            for (int j = 0; j < dict1.size(); j ++ ) {
                // 如果当前字符 == 解密前字典里的字符，则将其替换为解密后字典里的字符
                if (str[i] == dict1[j]) {
                    str[i] = dict2[j];
                    break;
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}


