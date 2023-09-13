
// 题意;
// 输入一个ip地址，保证不包含空格，返回判断的结果YES or NO


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// 辅助函数：判断 ip 地址每段是否合法
bool check(string s) {
    // 判断是否含有非数字
    for (char c: s) {
        if (!isdigit(c)) return false;
    }
    // 判断是否为空
    if (s.empty()) return false;
    // 判断是否越界
    else if (stoi(s) > 255) return false;
    // 判断是否含有前导 0（注意：必须是在 长度 > 1 的情况下）
    else if (s.size() > 1 && s[0] == '0') return false;

    return true;
}


int main() {
    string ip;
    getline(cin, ip);

    // 把字符串 ip 拆成几个由空格分开的字符串
    int cnt = 0;
    for (int i = 0; i < ip.size(); i ++ ) {
        if (ip[i] == '.') {
            ip[i] = ' ';
            cnt ++ ;
        }
    }
    // 如果字符串 ip 不是由 4 段字符串构成的，则不合法
    if (cnt != 3) cout << "NO" << endl;
    else {
        stringstream ssin(ip);
        string a, b, c, d;
        ssin >> a >> b >> c >> d;

        // 判断数字范围
        if (check(a) && check(b) && check(c) && check(d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    
    }

    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    for (char c: s) {
        if (!isdigit(c)) return false;
    }

    if (s.empty()) return false;
    else if (stoi(s) > 255) return false;
    else if (s.size() > 1 && s[0] == '0') return false;

    return true;
}

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.size(); i ++ ) {
        if (s[i] == '.') {
            s[i] = ' ';
            cnt ++ ;
        }
    }

    if (cnt != 3) cout << "NO" << endl;
    else {
        stringstream ssin(s);
        string a, b, c, d;
        ssin >> a >> b >> c >> d;

        if (check(a) && check(b) && check(c) && check(d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

