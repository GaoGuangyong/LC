

#include <iostream>
using namespace std;
 
// 欧几里得算法，求 a 和 b 的最大公约数
int gcd(int a, int b) {
    if (b != 0) return gcd(b, a % b);
    else return a;
}
 
int main() {
    // 读入 a, b
    int a, b;
    cin >> a >> b;
    
    // 最小公倍数 = 两数乘积 / 最大公约数
    cout << a * b / gcd(a, b) << endl; 
    
    return 0;
}

