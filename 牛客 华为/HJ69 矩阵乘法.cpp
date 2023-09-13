

// 题意：
// 求两个矩阵的乘积

// 输入描述：
// 第一行包含一个正整数x，代表第一个矩阵的行数
// 第二行包含一个正整数y，代表第一个矩阵的列数和第二个矩阵的行数
// 第三行包含一个正整数z，代表第二个矩阵的列数
// 之后x行，每行y个整数，代表第一个矩阵的值
// 之后y行，每行z个整数，代表第二个矩阵的值

// 输出描述：
// 对于每组输入数据，输出x行，每行z个整数，代表两个矩阵相乘的结果


// 模拟

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int x; // 矩阵 A 的行数
    int y; // 矩阵 A 的列数（矩阵 B 的行数）
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
                C[i][j] += A[i][k] * B[k][j]; // 注意是 += 累加 ！！！！！

    // 输出 C
    for (int i = 0; i < x; i ++ ) { 
        for (int j = 0; j < z; j ++ ) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}


