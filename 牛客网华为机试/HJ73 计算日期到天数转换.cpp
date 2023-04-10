




// 同 LC 1154

#include <iostream>
#include <vector>
using namespace std;

// 辅助函数：输入年份，判断是否为润年
int is_leap(int year) {
    if ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0))
        return 1;
    return 0;
}

int main() {
    int year, month, day;
    cin >> year >> month >> day;

    int res = 0; // 统计天数

    // 为了数组下标和月份对应，在最前面随便补一个数占位
    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

    // 先从 1 月遍历到 month - 1 月，将天数累加
    for (int i = 1; i < month; i ++ ) { 
        res += days[i];
        // 如果是二月，额外判断一步，闰年 + 1，非闰年 + 0
        if (i == 2) 
            res += is_leap(year);
    }
    
    // 再加上 month 月的天数
    res += day; 

    cout << res << endl;
}


