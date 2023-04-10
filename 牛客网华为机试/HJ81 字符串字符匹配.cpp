

// 使用 find 库函数模拟

#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main() {
    // 读入两行字符串，str1 为短串，str2 为长串
    string str1;
    string str2;
    cin >> str1 >> str2;
    
    bool flag = true; // 用于判断 str2 是否在 str1 中出现

    // 遍历 str1，如果有字符 str1[i] 在 str2 中没出现，则 flag 标记为 false
    for (int i = 0; i < str1.size(); i ++ ) {
        if (str2.find(str1[i]) == -1) {
            flag = false;
            break;
        }
    }

    // 若 str1 有字符在 str2 中没有出现，则为false
    if (flag == true) cout << "true" << endl;
    else cout << "false" << endl;
    
    return 0;
}

