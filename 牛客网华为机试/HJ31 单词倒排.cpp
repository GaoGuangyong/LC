

// 模拟：正向统计，逆向输出
// 题意：将给定字符串中的单词倒过来排，除大小写以外的字母都被当做分隔符

// 写法一：用 stringstream + 数组

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // 读入一行字符串
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i ++ ) {
        if (!isalpha(s[i])) s[i] = ' ';
    }

    // 读取字符串 s 中空格分开的单词到 ssin 字符串流
    stringstream ssin(s);

    string word;
    vector<string> res;

    while (ssin >> word) {
        res.push_back(word);
    }

    for (int i = res.size() - 1; i >= 0; i -- ) {
        cout << res[i] << " ";
    }

    return 0;
}


// 写法二：用 stringstream + 栈

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    // 读入一行字符串
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i ++ ) {
        if (!isalpha(s[i])) s[i] = ' ';
    }

    // 读取字符串 s 中空格分开的单词到 ssin 字符串流
    stringstream ssin(s);

    string word;
    stack<string> stk;

    while (ssin >> word) {
        stk.push(word);
    }

    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}




