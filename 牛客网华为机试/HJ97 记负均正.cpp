

// 枚举

#include <iostream>
using namespace std;

int main() {
    // 读入数字个数 n
    int n;
    cin >> n;

    int cnt1 = 0; // 负数个数
    int cnt2 = 0; // 正数个数
    int sum = 0; // 正数的和

    // 读入 n 个数
    for (int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;

        if (x < 0) cnt1 ++ ;
        
        else if (x > 0) {
            sum += x; //正数
            cnt2 ++ ;
        }
    }

    // 输出答案
    if (cnt2 == 0)
        printf("%d %.1f", cnt1, 0);
    else 
        printf("%d %.1f", cnt1, (double)sum / cnt2);

    return 0;
}


