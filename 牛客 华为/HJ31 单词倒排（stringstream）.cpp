

// 模拟：正向统计，逆向输出
// 题意：将给定字符串中的单词倒过来排，除大小写字母以外的字符都被当做分隔符

// 用 stringstream + 数组

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // 读入一行字符串
    string s;
    getline(cin, s); // 注意和 cin >> s 的区别
    
    // 遍历字符串 s，将所有的非字母转换成空格
    for (int i = 0; i < s.size(); i ++ ) {
        if (!isalpha(s[i])) s[i] = ' ';
    }

    // 从由空格分隔的字符串 s 中读取所有单词到 ssin 字符串流
    stringstream ssin(s);

    // 从字符串流 ssin 中，将所有单词存入数组 res 中
    vector<string> res;
    string str;

    while (ssin >> str) {
        res.push_back(str);
    }

    // 将 res 中的所有单词倒序输出
    for (int i = res.size() - 1; i >= 0; i -- ) {
        cout << res[i] << " ";
    }

    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i ++ ) {
        if (!isalpha(s[i])) s[i] = ' ';
    }

    stringstream ssin(s);

    vector<string> res;
    string str;

    while (ssin >> str) {
        res.push_back(str);
    }

    for (int i = res.size() - 1; i >= 0; i -- ) {
        cout << res[i] << " ";
    }

    return 0;
}


