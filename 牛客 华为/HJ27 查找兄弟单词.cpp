

// 输入： 
// 先输入字典中单词的个数 n，再输入 n 个单词。然后输入一个单词 x 最后后输入一个整数 k
// 输出：
// 第一行输出查找到 x 的兄弟单词的个数 m 
// 第二行输出查找到的按照字典顺序排序后的第 k 个兄弟单词，没有符合第 k 个的话则不用输出

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 辅助函数：判断 s1 和 s2 是否是兄弟单词
bool isbrother(string s1, string s2) {
    if (s1.size() == s2.size()) { // 兄弟单词一定要长度相等
        if (s1 == s2) return false; // 不能相同
        // 对两个字符串按字符字典序排序，排序后相同则是兄弟单词
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2) return true;
    }
    // 其他情况都不是兄弟单词
    return false;
}

int main() {
    // 读入 n
    int n;
    cin >> n;

    // 读入 n 个字典单词 到 字符串数组 strs 
    vector<string> strs(n);
    for (int i = 0; i < n; i ++ ) cin >> strs[i];
    
    // 读入 判断单词 x
    string x;
    cin >> x;
    
    // 读入 k
    int k;
    cin >> k;

    // 枚举字符串数组 strs，逐个与 x 判断是不是兄弟单词，如果是加入 brothers 数组
    vector<string> brothers;
    for (int i = 0; i < n; i ++ ) {
        if (isbrother(x, strs[i]) == true) {
            brothers.push_back(strs[i]);
        }
    }

    // 先输出 brothers 数组中的单词个数
    cout << brothers.size() << endl;
    
    // 对 brothers 数组排序，如果单词个数 >= k 的话，输出第 k 个单词 brothers[k - 1]
    sort(brothers.begin(), brothers.end());
    if (brothers.size() >= k) cout << brothers[k - 1] << endl;
    
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

bool check(string s1, string s2) {
    if (s1 == s2) return false;
    if (s1.size() == s2.size()) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i ++ ) cin >> strs[i];
    
    string x;
    cin >> x;
    
    int k;
    cin >> k;

    vector<string> brothers;

    for (int i = 0; i < n; i ++ ) {
        if (check(x, strs[i]) == true) brothers.push_back(strs[i]);
    }

    cout << brothers.size() << endl;

    sort(brothers.begin(), brothers.end());

    if (brothers.size() >= k) cout << brothers[k - 1] << endl;

    return 0;
}

