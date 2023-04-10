

// 哈希表

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
 
int main() {
    string str;
    getline(cin, str);

    // 定义哈希表，记录字符串中的字符及其个数
    unordered_map<char, int> hash;
    for (int i = 0; i < str.size(); i ++ ) hash[str[i]] ++ ;

    int find = 0;
    // 遍历字符串，找到第一个只出现一次的字母
    for (int i = 0; i < str.size(); i ++ ) {
        if (hash[str[i]] == 1) {
            cout << str[i] << endl;
            find = 1;
            break;
        }
    }

    // 如果不存在，则输出 -1
    if (find == 0) cout << -1 << endl;

    return 0;
}

