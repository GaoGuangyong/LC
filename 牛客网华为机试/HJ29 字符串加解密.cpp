
// 查表法

#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
string list1 = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789"; // 加密前的字符 list1
string list2 = "BCDEFGHIJKLMNOPQRSTUVWXYZA bcdefghijklmnopqrstuvwxyza 1234567890"; // 加密后的字符 list2

// 辅助函数：将字符串 str 加密
void encoder(string str) {
    // 用 i 枚举要加密的字符串中的字符，用 j 枚举 list1 的字符，找到相同的位置后，将 str[i] 替换成 list2[j]
    for (int i = 0; i < str.size(); i ++ ) { 
        for (int j = 0; j < list1.size(); j ++ ) { // 找到在 list1 中的位置
            if (str[i] == list1[j]) {
                str[i] = list2[j]; // 加密
                break;
            } 
        }
    }
    cout << str << endl;
}

// 辅助函数：将字符串 str 解密
void decoder(string str) {
    // 用 i 枚举要解密的字符串中的字符，用 j 枚举 list2 的字符，找到相同的位置后，将 str[i] 替换成 list1[j]
    for (int i = 0; i < str.size(); i ++ ) {
        for (int j = 0; j < list2.size(); j ++ ) { // 找到在 list2 中的位置
            if (str[i] == list2[j]) {
                str[i] = list1[j]; // 解密
                break;
            } 
        }
    }
    cout << str << endl;
}

int main() {
    // 读入要加密的字符串 str1 和要解密的字符串 str2
    string str1, str2;
    while (cin >> str1 >> str2) {
        encoder(str1); // 加密
        decoder(str2); // 解密
    }
    return 0;
}

