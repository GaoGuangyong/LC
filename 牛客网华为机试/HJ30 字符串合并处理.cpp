
// 查表法

// 题目已经给了 "abcdef" -> "5D37BF"，故只需把 0 ~ 9 的转化结果算出来
// 0    0000    0000    0
// 1    0001    1000    8
// 2    0010    0100    4
// 3    0011    1100    C
// 4    0100    0010    2
// 5    0101    1010    A
// 6    0110    0110    6
// 7    0111    1110    E
// 8    1000    0001    1
// 9    1001    1001    9

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

string help1 = "0123456789 abcdef ABCDEF";
string help2 = "084C2A6E19 5D3B7F 5D3B7F";

int main() {
    // 读入两个字符串，并将两个字符串拼接
    string str1, str2;
    cin >> str1 >> str2;
    string s = str1 + str2;

    string s1, s2; // 分别存奇数位字符串 && 偶数位字符串
    for (int i = 0; i < s.size(); i ++ ) {
        if (i % 2 == 0) s1 += s[i];
        else s2 += s[i];
        
    }
    sort(s1.begin(), s1.end()); // 奇数位字符串排序
    sort(s2.begin(), s2.end()); // 偶数位字符串排序

    // 遍历 s 数组，把排序好的字符串放回去
    for (int i = 0, j = 0, k = 0; i < s.size(); i ++ ) {
        // 如果是奇数位，则把 s1[j] 放回去
        if (i % 2 == 0) s[i] = s1[j ++ ]; 
        // 如果是偶数位，则把 s2[k] 放回去    
        else s[i] = s2[k ++ ];
    }

    // 定义一个哈希表，存 help1 中的字符及其下标
    unordered_map<char, int> hash;
    for (int i = 0; i < help1.size(); i ++ ) hash[help1[i]] = i;
        
    // 遍历字符串 s，如果是需要转换的字符，则转换
    for (int i = 0; i < s.size(); i ++ ) { 
        if (hash.count(s[i])) {
            s[i] = help2[hash[s[i]]];
        }
    }
    cout << s << endl;
    
    return 0;
}

