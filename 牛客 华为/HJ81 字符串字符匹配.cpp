
// 题意：
// 判断短字符串 S 中的所有字符是否在长字符串 T 中全部出现。
// 输入两个字符串。第一个为短字符串，第二个为长字符串。两个字符串均由小写字母组成

// 输入：
// bc
// abc

// 输出：
// true


// 使用 find 库函数模拟

#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main() {
    // 读入两行字符串，s 为短串，t 为长串
    string s, t;
    cin >> s >> t;
    
    bool flag = true; // 用于判断 t 是否在 s 中出现

    // 遍历 s，如果有字符 s[i] 在 t 中没出现，则 flag 标记为 false
    for (int i = 0; i < s.size(); i ++ ) {
        if (t.find(s[i]) == -1) { // find 的结果为 -1 表示没找到
            flag = false;
            break;
        }
    }

    // 若 s 有字符在 t 中没有出现，则为false
    if (flag == true) cout << "true" << endl;
    else cout << "false" << endl;
    
    return 0;
}

