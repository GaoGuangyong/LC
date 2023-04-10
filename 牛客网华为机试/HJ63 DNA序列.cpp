

// 题目描述类似 LC 433，但问题不一样

// 双指针
#include<iostream>
using namespace std;

int main() {
    string str;
    int k;
    cin >> str >> k; 
    
    int max = 0; // 维护所有窗口中 C、G 的最大数量
    int index = 0 ; // 记录答案字符串的起始下标
    
    // 枚举左端点
    for (int i = 0; i + k < str.size(); i ++ ) {
        int cnt = 0; // 维护当前窗口中 C、G 的数量
        // 从左端点开始，向右枚举 k 个长度
        for (int j = 0; j < k; j ++ ) {
            if (str[i + j] == 'C' || str[i + j] == 'G') {
                cnt ++;
            }
        }
        if (cnt > max) {
            index = i;
            max = cnt;
        }
    }
    cout << str.substr(index, k) << endl;
}



// 滑动窗口
// 输入字符串 str 和长度 k
// 输出字符串中，G 和 C 的比例最高的长度为 k 的子串，如果有多个，则输出从左到右的第一个

#include<iostream>
#include<string>
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
        if (str[i] == 'C' || str[i] == 'G')
            cnt ++ ;
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




