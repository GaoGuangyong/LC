// 套用表达式求职模板 https://www.acwing.com/activity/content/problem/content/3648/
// https://www.acwing.com/solution/content/6429/

// “表达式求值”问题，两个核心关键点：
//（1）双栈，一个操作数栈，一个运算符栈
//（2）运算符优先级：栈顶运算符，和，即将入栈的运算符的优先级比较
// 如果栈顶的运算符优先级低，新运算符直接入栈
// 如果栈顶的运算符优先级高，先出栈计算，新运算符再入栈

class Solution {
public:
    stack<int> num; // 数字栈
    stack<char> op; // 运算符栈
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*',2}, {'/', 2}}; // 定义一个哈希表，记录一下所有运算符的优先级

    // 求值函数：从数字栈弹出 2 个元素与运算符栈的栈顶进行运算
    void eval() {
        int b = num.top(); // 第二个操作数
        num.pop();

        int a = num.top(); // 第一个操作数
        num.pop();

        char p = op.top(); // 运算符
        op.pop();

        int res; // 结果
        if (p == '+') res = a + b;
        if (p == '-') res = a - b;
        if (p == '*') res = a * b;
        if (p == '/') res = a / b;

        num.push(res); // 结果入栈
    }

    int calculate(string s) {
        // 从前往后枚举表达式 s
        for (int i = 0; i < s.size(); i ++ ) {
            char c = s[i]; // 当前枚举到的字符 c
            if (c == ' ') continue; // 跳过空格
            // 如果枚举到的是数字，就把这个完整的数取出来（因为可能有多位），加入数字栈
            if (isdigit(c)) {
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
            }
            else {
                // 当前运算符的优先级 <= 栈顶运算符的优先级，就把栈顶的先计算一下
                while (op.size() && pr[c] <= pr[op.top()])
                    eval();
                op.push(c); // 计算完成后将当前运算符加入运算符栈
            }
        }
        // 最后要把剩余的没有操作完的运算算完，因为之前都是遇到运算符才算的，如果是a + b + c这种那么就实际上还是没计算呢
        while (op.size())
            eval();
        return num.top(); // 最终栈顶元素就是答案
    }
};

