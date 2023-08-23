
// 位运算
// 原理：设数字 n 的二进制表示中，最多有连续 x 个 1
// 则每次 n & (n << 1) 后，连续 1 的个数会 - 1（即 x -- ）
// 进行 x 次 按位与操作后，n == 0

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0; // 统计能够进行几次按位与操作

    while (n != 0) { 
        n &= (n << 1);
        cnt ++ ;
    }

    cout << cnt << endl;
    
    return 0;
}


