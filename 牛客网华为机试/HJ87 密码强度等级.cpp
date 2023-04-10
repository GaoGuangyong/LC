

// 模拟

#include <iostream>
#include <string>
using namespace std;

string password;
int upper = 0;  // 大写字母个数
int lower = 0;  // 小写字母个数
int digit = 0;  // 数字个数
int symbol = 0; // 符号个数

// 统计大小写字母、数字、符号出现的个数
void init(string s) {
    password = s;
    for (int i = 0; i < s.size(); i ++ ) { 
        if (islower(s[i])) lower ++ ;
        else if (isupper(s[i])) upper ++ ;
        else if (isdigit(s[i])) digit ++ ;
        else symbol ++ ;
    }
}

// 计算长度得分
int scoreOfLen() { 
    if (password.size() <= 4) return 5;
    else if (password.size() <= 7) return 10;
    return 25;
}

// 计算字母得分
int scoreOfAlpha() { 
    if (upper == 0 || lower == 0) return 10;
    else if (upper > 0 && lower > 0) return 20;
    return 0;
}

// 计算数字得分
int scoreOfDigit() { 
    if (digit == 1) return 10;
    else if (digit > 1) return 20;
    return 0;
}

// 计算符号得分
int scoreOfSymbol() { 
    if (symbol == 1)  return 10;
    else if (symbol > 1) return 25;
    return 0;
}

// 计算奖励分数
int award() { 
    if (upper > 0 && lower > 0 && digit > 0 && symbol > 0) return 5;
    else if (upper + lower > 0 && digit > 0 && symbol > 0) return 3;
    else if (upper + lower > 0 && digit > 0)  return 2;
    return 0;
}

int main() {
    // 读入字符串 s
    string s;
    cin >> s;
    // 统计 s 中各个字符的个数
    init(s);
    // 计算总分
    int score = scoreOfLen() + scoreOfAlpha() + scoreOfDigit() + scoreOfSymbol() + award();  
    // 按照总分输出对应的密码强度等级
    if (score >= 90) cout << "VERY_SECURE" << endl;
    else if (score >= 80) cout << "SECURE" << endl;
    else if (score >= 70) cout << "VERY_STRONG" << endl;
    else if (score >= 60) cout << "STRONG" << endl;
    else if (score >= 50) cout << "AVERAGE" << endl;
    else if (score >= 25) cout << "WEAK" << endl;
    else cout << "VERY_WEAK" << endl;
    
    return 0;
}

