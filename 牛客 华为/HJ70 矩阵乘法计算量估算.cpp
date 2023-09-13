

// 题意：
// 例如 A 是一个 50 × 10 的矩阵，B 是 10 × 20 的矩阵，C 是 20 × 5 的矩阵
// 计算 A*B*C 有两种顺序：((AB)C)或者(A(BC))，前者需要计算 15000 次乘法，后者只需要 3500 次
// 编写程序计算不同的计算顺序需要进行的乘法次数

// 第一行输入要计算乘法的矩阵个数 n
// 第二行开始的 n 行，每行输出一个矩阵的 行数 和 列数，空格隔开
// 最后输入要计算的法则，例如 -> (A(BC))



// 用栈模拟
//   (50 * 10) * [(10 * 20) * (20 * 5)] 
// = (50 * 10) * (10 * 5)  // 需要计算 10 * 20 * 5 = 1000 次
// = (50 * 5) // 需要计算 50 * 10 * 5 = 2500 次
// 总共需要进行 3500 次计算


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> PII;
 
int main() {
    // 读入 n
    int n;
    cin >> n;
    
    // 读入 n 个矩阵的行数和列数
    vector<PII> matrix; // 小技巧 ！！！！！读入俩俩由空格隔开的数据 -> pair
    for (int i = 0; i < n; i ++ ) { 
        int m, n;
        cin >> m >> n;
        matrix.push_back({m, n});
    }

    // 读入矩阵乘法顺序
    string s;
    cin >> s;

    stack<PII> stk; // 辅助栈，栈中存的是矩阵相乘后得到的矩阵的 <行数, 列数>

    int res = 0; // 需要进行的乘法总数
    int idx = 0; // 当前遍历的矩阵下标

    // 遍历矩阵乘法顺序，用栈实现计算（栈中存的是矩阵的 {行数，列数} ）
    for (int i = 0; i < s.size(); i ++ ) { 
        // 如果遍历到右括号，则从栈中取出两个矩阵计算 x * y
        if (s[i] == ')') { 
            auto y = stk.top(); // 先弹出的是矩阵 y
            stk.pop();
            auto x = stk.top(); // 后弹出的是矩阵 x
            stk.pop();

            res += x.first * x.second * y.second; // 累加当前矩阵乘法的计算量（x 的行数 * x 的列数 * y 的列数）

            stk.push({x.first, y.second}); // 将 相乘得到的矩阵的大小 {行数, 列数 } 入栈
        }
        // 如果遍历到矩阵，则将当前矩阵的大小 {行数, 列数} 入栈
        else if (isalpha(s[i])) {
            stk.push(matrix[idx]);
            idx ++ ;
        }
    }

    cout << res << endl;
    return 0;
}



