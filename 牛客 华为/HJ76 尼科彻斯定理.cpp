

// 题意：
// 已知任何一个整数 m 的立方 = m 个连续奇数的和
// 输入一个 int 整数，输出分解后的 string

// 输入：
// 6

// 输出：
// 31+33+35+37+39+41


// 枚举
// 计算从 i 开始的连续 m 个奇数的和：
// 第 1 个奇数为 i，第 2 个奇数为 i + 2，第 3 个奇数为 i + 4，...，直到第 m 个奇数为 i + 2 * (m - 1)
// sum = i + (i + 2) + (i + 4) + ... + (i + 2 * (m - 1)) = (i + m - 1) * m      m * i + m * (m - 1)

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
        // 计算从 i 开始的连续 m 个奇数的和是否等于 pow，若相等则从 i 开始输出连续 m 个奇数
        if ((i + m - 1) * m == pow) {
            cout << i; // 先输出 i 
            for (int j = 1; j < m; j ++ ) { // 再输出连续 m - 1 个
                cout << '+' << i + 2 * j;
            }
            cout << endl;
            break;
        }
    }
    
    return 0;
}



