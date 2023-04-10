

// 模拟

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int x; // 矩阵 A 的行数
    int y; // 矩阵 A 的列数 / 矩阵 B 的行数
    int z; // 矩阵 B 的列数
    cin >> x >> y >> z;

    vector<vector<int>> A(x, vector<int>(y, 0)); // 矩阵 A：x * y
    vector<vector<int>> B(y, vector<int>(z, 0)); // 矩阵 B：y * z
    vector<vector<int>> C(x, vector<int>(z, 0)); // 矩阵 C：x * z

    // 读入矩阵 A
    for (int i = 0; i < x; i ++ )
        for (int j = 0; j < y; j ++ )
            cin >> A[i][j];

    // 读入矩阵 B
    for (int i = 0; i < y; i ++ )
        for (int j = 0; j < z; j ++ )
            cin >> B[i][j];

    // 计算 C[i][j] 的值
    for (int i = 0; i < x; i ++ )
        for (int j = 0; j < z; j ++ )
            for (int k = 0; k < y; k ++ )
                C[i][j] += A[i][k] * B[k][j]; // 注意是 += 累加

    // 输出 C
    for (int i = 0; i < x; i ++ ) { 
        for (int j = 0; j < z; j ++ ) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}


