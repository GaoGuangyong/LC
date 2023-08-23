


// 题意：对输入的字符串进行加解密，并输出

// 加密方法为：
// 当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写：
// 如字母 a 替换为B；字母 Z 替换为 a；
// 当内容是数字时则把该数字加1，如 0 替换 1，1 替换 2，9 替换 0
// 其他字符不做变化


// 查表法

#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
string list1 = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789"; // 加密前的字符 list1
string list2 = "BCDEFGHIJKLMNOPQRSTUVWXYZA bcdefghijklmnopqrstuvwxyza 1234567890"; // 加密后的字符 list2

// 辅助函数：将字符串 s 加密
void encoder(string s) {
    // 用 i 枚举要加密的字符串中的字符，用 j 枚举 list1 的字符，找到相同的位置后，将 s[i] 替换成 list2[j]
    for (int i = 0; i < s.size(); i ++ ) { 
        for (int j = 0; j < list1.size(); j ++ ) { // 找到在 list1 中的位置
            if (s[i] == list1[j]) {
                s[i] = list2[j]; // 加密
                break;
            } 
        }
    }
    cout << s << endl;
}

// 辅助函数：将字符串 s 解密
void decoder(string s) {
    // 用 i 枚举要解密的字符串中的字符，用 j 枚举 list2 的字符，找到相同的位置后，将 s[i] 替换成 list1[j]
    for (int i = 0; i < s.size(); i ++ ) {
        for (int j = 0; j < list2.size(); j ++ ) { // 找到在 list2 中的位置
            if (s[i] == list2[j]) {
                s[i] = list1[j]; // 解密
                break;
            } 
        }
    }
    cout << s << endl;
}

int main() {
    // 读入要加密的字符串 s1 和要解密的字符串 s2
    string s1, s2;
    while (cin >> s1 >> s2) {
        encoder(s1); // 加密
        decoder(s2); // 解密
    }
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

string list1 = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789";
string list2 = "BCDEFGHIJKLMNOPQRSTUVWXYZA bcdefghijklmnopqrstuvwxyza 1234567890";

void encrypt(string s) {
    for (int i = 0; i < s.size(); i ++ ) {
        for (int j = 0; j < list1.size(); j ++ ) {
            if (s[i] == list1[j]) {
                s[i] = list2[j];
                break;
            }
        }
    }
    cout << s << endl;
}

void decrypt(string s) {
    for (int i = 0; i < s.size(); i ++ ) {
        for (int j = 0; j < list2.size(); j ++ ) {
            if (s[i] == list2[j]) {
                s[i] = list1[j];
                break;
            }
        }
    }
    cout << s << endl;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    encrypt(s1);
    decrypt(s2);

    return 0;
}


