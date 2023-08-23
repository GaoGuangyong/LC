

// 考察字符串的截取，转义符 \ 的使用

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 读入一行字符串
    string s;
    getline(cin, s);

    vector<string> output;

    int p = 0; // 记录参数的起始位置，用于截取字符串 s[p ~ i-1]
    bool flag = false; // 单独利用一个变量判断当前参数是否在引号中

    for (int i = 0; i < s.size(); i ++ ) {
        // 如果遇到引号
        if (s[i] == '\"') { // 注意要转义
            // 如果 flag 为 false，则是第一个引号，只标记 flag 即可
            if (flag == false) flag = true;
            // 否则，是第二个引号，截取两个引号之间的内容
            else { 
                flag = false;
                output.push_back(s.substr(p, i - p)); // 截取字符串加入
            }
            // 将 p 指向引号的下一个位置 
            p = i + 1; 
        } 

        // 如果遇到引号外的空格
        else if (s[i] == ' ' && flag == false) { 
            // 字符串非空，才截取
            if (i - p >= 1) {
                output.push_back(s.substr(p, i - p)); // 截取字符串加入
            }
            // 将 p 指向引号的下一个位置 
            p = i + 1;
        } 

        // 如果 i 指向了 s.size() - 1，则截取最后一个参数字符串
        else if (i == s.size() - 1) 
            output.push_back(s.substr(p, i - p + 1));
    }

    // 输出参数个数
    cout << output.size() << endl; 
    // 输出所有参数
    for (int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
    
    return 0;
}



