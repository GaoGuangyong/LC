

// 同 LC 191
// 输入一个正整数，计算它在二进制下的 1 的个数
// 注意多组输入输出

#include <iostream>
using namespace std;

int main() {
    int n;
    
    while (cin >> n) {
        int res = 0;
        for (int i = 0; i < 32; i ++ ) {
            if ((n >> i & 1) == 1) res ++ ;
        }
        cout << res << endl;
    }

    return 0;
}

