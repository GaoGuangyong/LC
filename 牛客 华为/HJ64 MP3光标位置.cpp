

// 题意：
// 第一行输入歌曲数目：n
// 第二行输入操作序列：s（U 表示上，D 表示下）
// 设初始时光标在第 1 首歌曲上，一页可以放下 4 首歌曲，则
// 第一行输出当前页面的 4 首歌曲的编号
// 第二行输出经过 s 的操作后，光标在第几首歌曲上


// 滑动窗口：循环数组的下标移动问题：

// 设 n = nums.size()，则 
// i 的后一个下标为 (i + 1) % n
// i 的前一个下标为 (i - 1 + n) % n

// 因为本题的下标从 1 开始，则
// i 的后一个下标为 (i + 1 - 1) % n + 1
// i 的前一个下标为 (i - 1 + n - 1) % n + 1


#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    // 读入歌曲数量 n 和操作序列 s
    int n;
    string s;
    cin >> n >> s;
 
    int res = 1; // 初始时，光标在第一首歌曲
    int win_b = 1;         // 页面的起始位置（下标从 1 开始）
    int win_e = min(4, n); // 页面的结尾位置  ---- 关键 ！！！！！
 
    // 遍历操作序列
    for (int i = 0; i < s.size(); i ++ ) {
        // 先确定移动后的光标位置 res
        if (s[i] == 'U') { // 如果要向上移动一格
            res = (res - 1 + n - 1) % n + 1;
        }
        else if (s[i] == 'D') { // 如果要向下移动一格
            res = (res + 1 - 1) % n + 1;
        }

        // 如果移动后的歌曲编号 < 当前页面的起始位置，则将页面往前移动，即起点更新为 res
        if (res < win_b) {
            win_b = res;
            win_e = win_b + 3;
        }
        // 如果移动后的歌曲编号 > 当前页面的结尾位置，则将页面往后移动，即终点更新为 res
        else if (res > win_e) {
            win_e = res;
            win_b = win_e - 3;
        }
    }
 
    // 第一行：输出当前页面的歌曲编号：[wib_b ~ win_e]
    for (int i = win_b; i <= win_e; i++) {
        cout << i << ' ';
    }
 
    cout << endl;
 
    // 第二行：输出选中的歌曲
    cout << res << endl;
     
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int win_b = 1; 
    int win_e = min(4, n);

    int res = 1;

    for (int i = 0; i < s.size(); i ++ ) {
        if (s[i] == 'U') res = (res - 1 + n - 1) % n + 1; 
        else if (s[i] == 'D') res = (res + 1 - 1) % n + 1;

        if (res < win_b) {
            win_b = res;
            win_e = win_b + 3;
        }
        else if (res > win_e) {
            win_e = res;
            win_b = win_e - 3;
        }
    } 

    for (int i = win_b; i <= win_e; i ++ ) cout << i << ' ';
    
    cout << endl;

    cout << res << endl;

    return 0;
}


