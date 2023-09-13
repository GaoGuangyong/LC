

// 题意：
// 输入 n 
// 输出从 2 开始的以 3 为公差的等差数列的前 n 项和  ->  2 + 5 + 8 + ... 共 n 个数的和

// 解法一：累加求和
#include<iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    int x = 2; // 数组第一个元素
    int sum = 0;
    
    for (int i = 0; i < n; i ++ ) { // 遍历数组前 n 项
        sum += x + 3 * i; // 累加
    }
    
    cout << sum << endl;
    
    return 0;
}


// 解法二：等差数列求和公式
// 首项：2，末项：2 + 3*(n-1)
#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;

    int sum = (2 + (2 + 3 * (n - 1)) ) * n / 2;  // 等差数列求和公式
    
    cout << sum << endl;
    
    return 0;
}

