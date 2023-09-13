
// 题意：求如下的杨辉三角的第 n 行的第一个偶数出现的位置，若没有偶数，则输出 -1
// 1            1 
// 2          1 1 1
// 3        1 2 3 2 1         2
// 4      1 3 6 7 6 3 1       3
// 5    1 4 10 16 ...         2
// 6  1 5 15 30 ...           4

// 例如，输入 3 则输出 2

// 找规律

#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;

    // 前两行没有偶数
    if (n <= 2) cout << -1 << endl;
    else {
        // 奇数行 偶数在第 2 个
        if(n % 2 == 1) cout << 2 << endl; 
        // 偶数行 行数整除 4 的在第 3 个
        else if (n % 4 == 0) cout << 3 << endl;
        // 偶数行 行数除 4 余 2 的在第 4 个
        else if (n % 4 == 2) cout << 4 << endl;
    }
    
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 2) cout << -1 << endl;
    else {
        if (n % 2 == 1) cout << 2 << endl;
        else if (n % 4 == 0) cout << 3 << endl;
        else if (n % 4 == 2) cout << 4 << endl;
    }


    return 0;
}
