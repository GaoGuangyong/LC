

// 题意：按照如下规则对输入的字符串进行处理
// 第一步：将输入的两个字符串 str1 和 str2 进行前后合并
// dec fab -> decfab

// 第二步：将第一步得到的字符串按照下标的奇偶分别排序
// d c a  -> a c d
//  e f b  -> b e f 
// decfab -> abcedf 

// 第三步：对第二步得到的字符串中的 '0'~'9'、'A'~'F' 和 'a'~'f' 进行转换操作：
// 将上述字符所代表的十六进制用二进制表示并倒序，然后再转换成对应的十六进制大写字符
// 注：字符 a~f 的十六进制对应十进制的10~15，大写也同样

// 如字符 '4'，其二进制为 0100 ，则翻转后为 0010 ，也就是 2，转换后的字符为 '2'
// 如字符 ‘7’，其二进制为 0111 ，则翻转后为 1110 ，也就是 14，转换为十六进制的大写字母为 'E'
// 如字符 'C'，代表的十进制是 12 ，其二进制为 1100 ，则翻转后为 0011，也就是 3，转换后的字符是 '3'

// 查表法 -> 根据题目要求，将所有的字符给出正确的映射全系

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

string list1 = "0123456789 abcdef ABCDEF";
string list2 = "084C2A6E19 5D3B7F 5D3B7F";

int main() {
    // 读入两个字符串，并将两个字符串拼接
    string str1, str2;
    cin >> str1 >> str2;
    string s = str1 + str2;

    string s1, s2; // s1 存偶数位字符，s2 存奇数位字符
    for (int i = 0; i < s.size(); i ++ ) {
        if (i % 2 == 0) s1 += s[i];
        else s2 += s[i];
    }

    sort(s1.begin(), s1.end()); // 偶数位字符串排序
    sort(s2.begin(), s2.end()); // 奇数位字符串排序

    // 遍历 s 数组，把排序好的字符串放回去
    for (int i = 0, j = 0, k = 0; i < s.size(); i ++ ) {
        if (i % 2 == 0) s[i] = s1[j ++ ]; // 如果是偶数位，则把 s1[j] 放回去
        else s[i] = s2[k ++ ]; // 如果是奇数位，则把 s2[k] 放回去 
    }

    // 定义一个哈希表，存 list1 中的字符及其下标
    unordered_map<char, int> hash;
    for (int i = 0; i < list1.size(); i ++ ) hash[list1[i]] = i;
        
    // 遍历字符串 s，如果是需要转换的字符，则转换
    for (int i = 0; i < s.size(); i ++ ) { 
        if (hash.count(s[i])) {
            s[i] = list2[hash[s[i]]];
        }
    }

    cout << s << endl;
    
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

string list1 = "0123456789 abcdef ABCDEF";
string list2 = "084C2A6E19 5D3B7F 5D3B7F";

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string s = s1 + s2;

    string t1, t2;
    for (int i = 0; i < s.size(); i ++ ) {
        if (i % 2 == 0) t1 += s[i];
        else t2 += s[i];
    }

    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());

    int j = 0, k = 0;
    for (int i = 0; i < s.size(); i ++ ) {
        if (i % 2 == 0) s[i] = t1[j ++ ];
        else s[i] = t2[k ++ ];
    }

    unordered_map<char, int> hash;
    for (int i = 0; i < list1.size(); i ++ ) hash[list1[i]] = i;

    for (int i = 0; i < s.size(); i ++ ) { 
        if (hash.count(s[i])) {
            s[i] = list2[hash[s[i]]];
        }
    }

    cout << s << endl;

    return 0;
}
