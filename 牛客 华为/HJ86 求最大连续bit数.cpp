
// 题意：
// 求一个 int 类型数字对应的二进制数字中 1 的最大连续数，例如 3 的二进制为 00000011，最大连续 2 个 1

// 输入：
// 200

// 输出：
// 2

// 说明：
// 200 的二进制表示是 11001000，最多有 2 个连续的 1



// 位运算
// 原理：设数字 n 的二进制表示中，最多有连续 x 个 1
// 则每次 n & (n << 1) 后，连续 1 的个数会 -1
// 进行 x 次 按位与操作后，n == 0

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int res = 0; // 统计能够进行几次按位与操作

    while (n != 0) { 
        n &= (n << 1);
        res ++ ;
    }

    cout << res << endl;
    
    return 0;
}


// 二刷（采用传统解法）
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int res = 1;
    int cur = 1;

    // 枚举 n 的二进制表示的每一位
    for (int i = 0; i < 32; i ++ ) {
        if ((n >> i & 1) == 1) {
            if ((n >> (i - 1) & 1) == 1) cur ++ ;
            else cur = 1;
            
            res = max(res, cur);
        }
    }

    cout << res << endl;

    return 0;
}

