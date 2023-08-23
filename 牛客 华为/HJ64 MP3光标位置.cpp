

// 滑动窗口

// 知识点：循环数组的下标移动问题：
// 设 n = nums.size()，则 
// i 的后一个下标为 (i + 1) % n
// i 的前一个下标为 (i - 1 + n) % n
// 因为本题的下标从 1 开始，则
// i 的后一个下标为 (i + 1 - 1) % n + 1
// i 的前一个下标为 (i - 1 - 1 + n) % n + 1

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // 读入歌曲数量 n 和操作序列 str
    int n;
    string str;
    cin >> n >> str;

    int res = 1; // 当前选中的歌曲
    int win_b = 1; // 页面的起始（下标从 1 开始）
    int win_e = min(4, n); // 页面的末位置

    // 遍历操作序列
    for (int i = 0; i < str.size(); i ++ ) {
        // 如果要向上移动一格（相当于向前）
        if (str[i] == 'U') { 
            res = (res - 1 - 1 + n) % n + 1;
        } 
        // 如果要向下移动一格（相当于向后）
        else if (str[i] == 'D') { 
            res = (res + 1 - 1) % n + 1;
        }
        // 如果移动后当前歌曲在窗口前，则将窗口往前移动
        if (res < win_b) { 
            win_b = res;
            win_e = win_b + 3;
        } 
        // 如果移动后当前歌曲在窗口后，则将窗口往后移动
        else if (res > win_e) { 
            win_e = res;
            win_b = win_e - 3;
        }
    }

    // 输出当前页面
    for (int i = win_b; i <= win_e; i++) { 
        cout << i << ' ';
    }

    cout << endl;

    // 输出选中的歌曲
    cout << res << endl; 
    
    return 0;
}


