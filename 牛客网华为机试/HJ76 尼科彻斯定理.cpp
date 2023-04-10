

// 题意：任何一个整数 m 的立方 = m 个连续奇数的和

// 枚举

// 计算从 i 开始的连续 m 个奇数的和：
// 第 1 个奇数为 i，第 2 个奇数为 i + 2，第 3 个奇数为 i + 4，...，直到第 m 个奇数为 i + 2 * (m - 1)
// sum = (i + 0) + (i + 2) + (i + 4) + ... + (i + 2 * (m - 1)) = m * i + m * (m - 1)

#include <iostream>
#include <string>
using namespace std;
 
int main() {
    // 读入 m
    int m;
    cin >> m;

    int pow = m * m * m; // 先获取三次方的值

    // 枚举 1 到 pow 的所有奇数（靠 i += 2 实现）
    for (int i = 1; i < pow; i += 2) { 
        // 计算从 i 开始的连续 m 个奇数的和是否等于 pow
        if (m * i + m * (m - 1) == pow) {
            // 若相等则从 i 开始输出连续 m 个奇数
            cout << i; 
            for (int j = 1; j < m; j ++ ) { // 再输出连续 m - 1 个
                cout << '+' << i + 2 * j;
            }
            cout << endl;
            break;
        }
    }
    
    return 0;
}



