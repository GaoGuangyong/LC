
// 题意：输入一行字符串，将其按 ASCII 码值从小到大排序后输出

// 考察 ASCII 码的相关知识

// A ~ Z  65 ~ 90
// a ~ z  97 ~ 122
// 0 ~ 9  48 ~ 57

// ASCII 码从小到大的顺序是：数字、大写字母、小写字母

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
    string s;
    cin >> s;
        
    sort(s.begin(), s.end());
    cout << s << endl;

    return 0;
}


