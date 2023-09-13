

// 题意：
// 输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数


// https://blog.csdn.net/m0_51033005/article/details/115707870

// string 类的内置函数
// isalpha()   判断字符是否是字母，是则返回非 0 整数，不是则返回 0
// isdigit()   判断字符是否是数字，是则返回非 0 整数，不是则返回 0
// isspace()   判断字符是否是空格、制表符、换行等标准空白，是则返回非 0 整数，不是则返回 0
// isalnum()   判断字符是否是字母或者数字
// ispunct()   判断字符是标点符号
// islower()   判断字符是否是小写字母（'a'-'z'）
// isupper()   判断字符是否是大写字母（'A'-'Z'）


#include<iostream>
#include<string>

using namespace std;

int main() {
    // 读入一行字符串 str
    string str;
    getline(cin, str);

    int num_e = 0, num_w = 0, num_n = 0, num_o = 0; // 字母、空格、数字、其他字符的数量

    // 遍历字符串 str
    for (int i = 0; i < str.size(); i ++ ) {
        if (isalpha(str[i]) != 0) num_e ++ ;      // 英文字母
        else if (isspace(str[i]) != 0) num_w ++ ; // 空格
        else if (isdigit(str[i]) != 0) num_n ++ ; // 数字
        else num_o ++ ;                           // 其他字符
    }

    // 输出英文字符，空格字符，数字字符，其他字符的个数
    cout << num_e << endl << num_w << endl << num_n << endl << num_o << endl;
    
    return 0;
}



// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int a = 0, b = 0, c = 0, d = 0; // 字母、空格、数字、其他字符的数量

    for (int i = 0; i < s.size(); i ++ ) {
        if (isalpha(s[i])) a ++ ;
        else if (isspace(s[i])) b ++ ;
        else if (isdigit(s[i])) c ++ ;
        else d ++ ;
    }

    cout << a << endl << b << endl << c << endl << d << endl;

    return 0;
}
