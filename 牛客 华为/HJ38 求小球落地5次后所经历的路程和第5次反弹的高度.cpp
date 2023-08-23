

// 解法一：模拟
// 注意：是第 5 次落地时的距离，第五次反弹回去的不算


#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
    int n = 5;

    // 读入起始高度 h
    double h;
    cin >> h;

    double dis = 0; // 总距离

    // 循环 5 次
    for (int i = 0; i < n; i ++ ) {
        dis += h; // 加上落下来的距离
        h /= 2; // 弹起距离缩短一半
        // 当最后一次下落时，输出结果
        if (i == n - 1) {
            cout << setprecision(6) << dis << endl;
            cout << setprecision(6) << h << endl;
        }
        dis += h; // 加上弹上去走的距离
    }
    return 0; 
}


