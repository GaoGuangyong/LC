
// 题意：
// 一个 DNA 序列由 A/C/G/T 四个字母的排列组合组成
// 定义 GC-Ratio 为：序列中 G 和 C 两个字母的总的出现次数除以总的字母数目
// 第一行输入一个表示 DNA 序列的字符串
// 第二行输入限定的子串长度 N 
// 请帮助研究人员在给出的 DNA 序列中从左往右找出 GC-Ratio 最大 且 长度为 N 的第一个子串

// 题目描述类似 LC 433，但问题不一样

// 双指针
#include <iostream>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n; 
    
    int max = 0; // 维护所有长度为 n 的区间中 C、G 的最大数量
    int idx = 0 ; // 记录答案字符串的起始下标
    
    // 枚举左端点
    for (int i = 0; i + n < s.size(); i ++ ) {
        int cnt = 0; // 维护当前区间 [i ~ i + n] 中的 C、G 的数量
        for (int j = 0; j < n; j ++ ) { // 从左端点开始，向右枚举 n 个长度
            if (s[i + j] == 'C' || s[i + j] == 'G') cnt ++ ;
        }

        if (cnt > max) { // 如果当前窗口中的 C、G 数量 > 最大值，则将当前区间 [i ~ i + n] 作为备选答案
            idx = i;
            max = cnt;
        }
    }

    cout << s.substr(idx, n) << endl; // 最后，输出 [idx ~ idx + n] 作为答案
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;

    cin >> s >> n;

    int max = 0;
    int idx = 0;

    for (int i = 0; i + n < s.size(); i ++ ) {
        int cnt = 0;
        
        for (int j = 0; j < n; j ++ ) {
            if (s[i + j] == 'C' || s[i + j] == 'G') cnt ++ ;
        }

        if (cnt > max) {
            idx = i;
            max = cnt;
        }
    }

    cout << s.substr(idx, n) << endl;

    return 0;
}


// 滑动窗口

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int k;
    cin >> str >> k;

    int n = str.size();

    int index = 0; // 记录答案字符串的起始下标
    int max = 0; // 维护所有窗口中 C、G 的最大数量
    int cnt = 0; // 维护当前窗口中 C、G 的数量

    // 计算第一个窗口中 C、G 的数量
    for (int i = 0; i < k; i ++ ) {
        if (str[i] == 'C' || str[i] == 'G') cnt ++ ;
    }

    max = cnt; // 录下第一个窗口的 CG 数量作为最大

    int l = 1, r = k; // 从录入窗口的左右点右移一位开始
    while (r < n) { // 直到右窗口结束
        if (str[l - 1] == 'C' || str[l - 1] == 'G') // 窗口左边出去的是CG
            cnt -- ;
        if (str[r] == 'C' || str[r] == 'G') // 窗口右边进来的是CG
            cnt ++ ;
        if (cnt > max) { // 更新，取最大值
            max = cnt;
            index = l;
        }
        l ++ ;
        r ++ ;
    }

    cout << str.substr(index, k) << endl; // 根据下标和 n 输出
    
    return 0;
}




