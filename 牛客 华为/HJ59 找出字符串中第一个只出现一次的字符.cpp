

// 题意：输入一个字符串，输出字符串中第一个只出现一次的字符，如果不存在输出 -1

// 哈希表

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
 
int main() {
    string s;
    getline(cin, s);

    // 定义哈希表，记录字符串中的字符及其个数
    unordered_map<char, int> hash;
    for (int i = 0; i < s.size(); i ++ ) hash[s[i]] ++ ;

    bool flag = false; // 标记位

    // 遍历字符串，找到第一个只出现一次的字母
    for (int i = 0; i < s.size(); i ++ ) {
        if (hash[s[i]] == 1) {
            cout << s[i] << endl;
            flag = true;
            break;
        }
    }

    // 如果不存在，则输出 -1
    if (flag == false) cout << -1 << endl;

    return 0;
}

// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> hash;
    for (int i = 0; i < s.size(); i ++ ) hash[s[i]] ++ ;

    bool flag = false;

    for (int i = 0; i < s.size(); i ++ ) {
        if (hash[s[i]] == 1) {
            cout << s[i] << endl;
            flag = true;
            break;
        }
    }

    if (flag == false) cout << -1 << endl;

    return 0;
}
