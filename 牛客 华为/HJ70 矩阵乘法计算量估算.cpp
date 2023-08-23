

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
    vector<PII> matrix;
    for (int i = 0; i < n; i ++ ) { 
        int m, n;
        cin >> m >> n;
        matrix.push_back({m, n});
    }

    // 读入矩阵乘法顺序
    string str;
    cin >> str;

    stack<PII> stk; // 辅助栈，栈中存的是矩阵相乘后得到的矩阵的 <行数, 列数>

    int res = 0; // 需要进行的乘法总数
    int k = 0; // 当前遍历的矩阵下标

    // 遍历矩阵乘法顺序
    for (int i = 0; i < str.size(); i ++ ) { 
        // 如果遍历到右括号，则从栈中取出两个矩阵计算 x * y
        if (str[i] == ')') { 
            auto y = stk.top(); // 先弹出的是 y
            stk.pop();
            auto x = stk.top(); // 后弹出的是 x
            stk.pop();
            res += x.first * x.second * y.second; // 累加当前矩阵乘法的计算量

            stk.push({x.first, y.second}); // 相乘得到的矩阵的大小入栈
        }
        // 如果遍历到矩阵，则将当前矩阵的 <行数, 列数> 入栈
        else if (isalpha(str[i])) {
            stk.push(matrix[k]); // 当前为字母时，矩阵进栈
            k ++ ;
        }
    }

    cout << res << endl;
    return 0;
}



