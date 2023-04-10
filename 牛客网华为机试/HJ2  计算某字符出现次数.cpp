


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    // 读入一行字符串 s
    string s;
    getline(cin, s);

    // 读入要查找的字符 c
    char c;
    cin >> c;

    // 定义一个哈希表，存字符串中的字符及其个数
    unordered_map<char, int> hash;
    for (char c: s) {
        hash[tolower(c)] ++ ; // 所有字符转换成小写
    }

    // 输出字符 c 的个数
    cout << hash[tolower(c)] << endl;
}

