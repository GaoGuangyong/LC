
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // 读入浮点数 x
    float x;
    cin >> x;

    // 得到 x 的整数部分
    int y = x / 1;

    // 四舍
    if (x - (float)y < 0.5) cout << y << endl; 
    // 五入
    else cout << y + 1 << endl;
    
    return 0;
}

