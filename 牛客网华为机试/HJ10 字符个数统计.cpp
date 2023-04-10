

// 考察有序集合 set 的去重性质

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    // 读入字符串 s
    string s;
    cin >> s;

    // 定义一个有序集合，存 s 中的字符
    set<char> S; 
    
    // 遍历字符串，将字符插入有序集合中，自动实现去重
    for (int i = 0; i < s.size(); i ++ ) {
        S.insert(s[i]);
    }
    
    cout << S.size();
    return 0;
}

