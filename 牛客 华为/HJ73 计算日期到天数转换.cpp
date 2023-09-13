

// 题意：
// 根据输入的日期，计算是这一年的第几天

// 输入：
// 2012 12 31

// 输出：
// 366



// 同 LC 1154

#include <iostream>
#include <vector>
using namespace std;

// 辅助函数：判断 year 是否为润年：能被 4 整除但不能被 100 整除 or 能被 400 整除
bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int year, month, day;
    cin >> year >> month >> day;

    int res = 0; // 统计天数

    // 定义数组存每个月的天数（为了使数组下标和月份对应，在最前补一个数占位）
    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

    // 先将 1 月到 month - 1 月的天数累加
    for (int i = 1; i < month; i ++ ) { 
        res += days[i];
        // 如果是二月，额外判断一步，闰年 + 1，非闰年 + 0
        if (i == 2) {
            if (is_leap(year)) res += 1;
        }
    }
    
    // 再加上 month 月的天数
    res += day; 

    cout << res << endl;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;


bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int year, month, day;
    cin >> year >> month >> day;

    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int res = 0;

    for (int i = 1; i < month; i ++ ) {
        res += days[i];
        if (i == 2) {
            if (is_leap(year)) res ++ ;
        }
    }

    res += day;
    
    cout << res << endl;
    
    return 0;
}

