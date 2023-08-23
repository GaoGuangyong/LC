

// 找规律

#include<iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    // 前两行没有偶数
    if (n <= 2) cout << -1 << endl;
    else {
        // 奇数行偶数在第 2 个
        if(n % 2) cout << 2 << endl; 
        // 偶数行 除 4 余 2 的在第 4 个
        else if (n % 4 == 2) cout << 4 << endl;
        // 偶数行整除 4 的在第 3 个
        else if (n % 4 == 0) cout << 3 << endl;
    }
    
    return 0;
}

