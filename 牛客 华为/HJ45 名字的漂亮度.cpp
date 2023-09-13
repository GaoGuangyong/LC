

// 题意：
// 每个字母都有一个“漂亮度”，范围在 1 到 26 之间。没有任何两个不同字母拥有相同的 “漂亮度”。字母忽略大小写。
// 给出一个字符串，该字符串仅由小写字母组成，定义这个字符串的 “漂亮度” 是其所有字母“漂亮度”的总和。

// 第一行一个整数 N，接下来 N 行每行一个字符串
// 求每个字符串可能的最大漂亮度

// 根据题意，需要使频率越高的字母 * 越大的数（漂亮度）



// 模拟
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 辅助函数：计算字符串 s 的最大漂亮度
int getMaxValue(string s) {
    // ！！！ 技巧：定义一个数组，记录名字中不同字母出现的次数，alphabet[0] -> a/A，alphabet[1] -> b/B 以此类推
    vector<int> alphabet(26, 0);

    // 定义一个数组，按照 1 ~ 26 升序记录漂亮度
    vector<int> Price{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26}; 

    int maxVal = 0; // 初始化最大漂亮度
    
    // 遍历字符串 s，记录每个字母出现的次数（不区分大小写）
    for (int i = 0; i < s.size(); i ++ ) {
        // 如果是大写字母
        if (isupper(s[i])) alphabet[s[i] - 'A'] ++ ;
        // 如果是小写字母
        else if (islower(s[i])) alphabet[s[i] - 'a'] ++ ;
    }

    // 将 alphabet 数组排序，这样一来 alphabet 和 Price 都是升序的，相同下标相乘即可
    sort(alphabet.begin(), alphabet.end());
    
    for (int i = 0; i < 26; i ++ ) {
        maxVal += alphabet[i] * Price[i]; 
    }

    return maxVal; // 返回一个名字的最大可能价钱（即漂亮度）
}


// 主函数
int main () {
    // 读入 n 
    int n;
    cin >> n;

    // 读入所有的名字，输出每个名字的最大可能漂亮度
    string s;
    while (cin >> s) {
        cout << getMaxValue(s) << endl;
    }
    
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int get(string s) {
    vector<int> cnt(26, 0);
    vector<int> val = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

    int res = 0;

    for (int i = 0; i < s.size(); i ++ ) {
        if (isupper(s[i])) cnt[s[i] - 'A'] ++ ;
        else if (islower(s[i])) cnt[s[i] - 'a'] ++ ;
    }

    sort(cnt.begin(), cnt.end());

    for (int i = 0; i < 26; i ++ ) res += cnt[i] * val[i];

    return res;
}

int main() {
    int n;
    cin >> n;

    while (n -- ) {
        string s;
        cin >> s;
        cout << get(s) << endl;
    }

    return 0;
}


