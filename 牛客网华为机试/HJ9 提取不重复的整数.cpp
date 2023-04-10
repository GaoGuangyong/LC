

// 考察有序集合 set 的去重性质

#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main() {
    // 读入字符串 s
    string s;
    cin >> s;

    // 定义一个有序集合，存所有出现过的字符
    set<char> S; 
    
    // 从后往前遍历字符串 s，加入有序集合，如果集合中已存在，则跳过
    for (int i = s.size() - 1; i >= 0; i -- ) {
        // 如果当前字符在哈希集合中已经存在了，则跳过
        if (S.count(s[i])) continue; 
        // 否则，输出，并将其插入哈希集合
        else { 
            cout << s[i];
            S.insert(s[i]);
        }
    }

    return 0;
}

