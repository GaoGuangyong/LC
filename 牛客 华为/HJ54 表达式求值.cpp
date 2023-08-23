
// 双栈法 -> 在 LC 227 的基础上多了小括号，为了处理负数，要先判断运算符再判断数字
// "表达式求值" 问题，两个核心关键点：
//（1）双栈，一个操作数栈，一个运算符栈
//（2）运算符优先级，栈顶运算符，和，即将入栈的运算符的优先级比较
// 如果栈顶的运算符优先级低，新运算符直接入栈
// 如果栈顶的运算符优先级高，先出栈计算，新运算符再入栈

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// 全局函数
stack<int> num; // 数字栈
stack<char> op; // 运算符栈
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*',2}, {'/', 2}}; // 定义一个哈希表，记录一下所有运算符的优先级

// 计算函数：从数字栈弹出 2 个元素与运算符栈的栈顶进行运算
void compute() { 
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char p = op.top(); //栈顶运算符
    op.pop();

    int res; // 结果
    if (p == '+') res = a + b; // 加
    if (p == '-') res = a - b; // 减
    if (p == '*') res = a * b; // 乘
    if (p == '/') res = a / b; // 除
    num.push(res); // 结果入栈
}


int main() {
    string s;
    cin >> s;

    // 为方便，假设 s 外有括号 ()
    op.push('('); 
    s += ')';

    bool flag = false; // flag 为 true 表示是运算符，flag 为 false 表示是数字

    for (int i = 0; i < s.size(); i ++ ) {
        if (s[i] == '(') op.push('(');
        else if (s[i] == ')') {
            while (op.top() != '(')
                compute();
            op.pop(); //弹出左括号
        } 
        // 如果是运算符
        else if (flag == true) {
            // 当前运算符的优先级 <= 栈顶运算符的优先级，就把栈顶的先计算一下
            while (op.size() && pr[s[i]] <= pr[op.top()])
                compute(); 
            op.push(s[i]); // 计算完成后将当前运算符加入运算符栈
            flag = false;
        } 
        // 如果是数字，就把这个完整的数取出来（因为可能有多位），加入数字栈
        else {
            // 计算数字 x （因为数字可能有好几位）
            int x = 0;
            int j = i;
            while (j < s.size() && isdigit(s[j])) {
                x = x * 10 + (s[j] - '0');
                j ++ ;
            }
            // 数字入栈
            num.push(x);
            i = j - 1; // i = j - 1 配合上 i ++，恰好就可以跳过这个数字了
            flag = true; // 数字结束，下一次 flag 为 true 就是运算符了
        }
    }
    cout << num.top() << endl; //输出
    
    return 0;
}