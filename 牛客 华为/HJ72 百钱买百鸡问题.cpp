
// 鸡翁 1 个 5 元，鸡母 1 个 3 元，鸡雏 3 个 1 元
// 任意输入一个整数
// 分成 n 行输出所有花 100 元买 100 鸡的可能方案，按 鸡翁、母鸡、鸡雏 的顺序输出

// 暴力枚举

#include <iostream>
using namespace std;
 
int main() {
    // 遍历所有可能的公鸡、母鸡、小鸡可能的数量
    for (int i = 0; i <= 20; i ++ ) {
        for (int j = 0; j <= 33; j ++ ) {
            for (int k = 0; k <= 100; k ++ ) { 
                // 鸡的总数等于 100，且总共花了 100 元
                if (i + j + k == 100 && 5 * i + 3 * j + double(k) / 3 == 100) { 
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    return 0;
}

