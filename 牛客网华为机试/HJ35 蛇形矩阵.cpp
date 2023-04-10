

// 题意：输入 n，给出长度为 n 的上三角矩阵


// 方法：按斜线遍历
// 某条斜线上的元素下标特点：行下标 + 列下标 相等 

#include <iostream>
#include <vector>
using namespace std;

int N = 101;

int main() {
    int n;
    cin >> n;
    
    // 1、维护 matrix 数组
    vector<vector<int>> matrix(N, vector<int>(N));
    int num = 1;

    // 枚举下标总和
    for (int i = 0; i < n; i ++ ) {
        // 枚举列下标
        for (int j = 0; j <= i; j ++ ) {
            matrix[i - j][j] = num ++ ; //行下标 = 下标总和 - 列下标
        }
    }

    // 2、按要求输出
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n - i; j ++ ) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

