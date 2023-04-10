
// 模拟、分情况讨论
#include <iostream>
using namespace std;
 
int main() {
    // 读入若干组矩阵的行与列
    int m, n;
    while (cin >> m >> n) { 
        //【1】行数 m ≤ 9 且 列数 n ≤ 9
        if (m <= 9 && n <= 9) cout << 0 << endl;
        else cout << -1 << endl;

        //【2】读入要交换位置的两个坐标
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; 
        // 0 ≤ 横坐标 < m 且 0 ≤ 纵坐标 < n
        if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && x2 >= 0 && x2 < m && y2 >= 0 && y2 < n)
            cout << 0 << endl;
        else
            cout << -1 << endl;

        //【3】读入要插入的行号 x
        int x;
        cin >> x; 
        // 0 ≤ 要插入的行号 < m，且插入后总行数 ≤ 9
        if (x >= 0 && x < m && m + 1 <= 9) cout << 0 << endl;
        else cout << -1 << endl;

        //【4】读入要插入的列号 y
        int y;
        cin >> y; 
        // 0 ≤ 要插入的列号 < n，且插入后总列数 ≤ 9
        if (y >= 0 && y < n && n + 1 <= 9) cout << 0 << endl;
        else cout << -1 << endl;

        //【5】读入要查找的位置 (x, y)
        cin >> x >> y;
        // 0 ≤ 要查找的行号 < m 且 0 ≤ 要查找的列号 < n
        if (x >= 0 && x < m && y >= 0 && y < n) cout << 0 << endl;
        else cout << -1 << endl;
    }

    return 0;
}



