

// 遍历所有元素
// 如果当前元素是整数，则压入栈
// 如果是运算符，则将栈顶两个元素弹出做相应运算，再将结果入栈

// 最终表达式扫描完后，栈里的数就是结果

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 定义辅助栈
        stack<int> stk;

        // 遍历字符数组
        for (string s: tokens) {
            // 如果时【运算符】，就出栈两个数来计算，将计算的结果再入栈  
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                // 从栈顶弹出两个数
                int second = stk.top(); // 先出栈的是第 2 个数
                stk.pop();
                int first = stk.top(); // 后出栈的是第 1 个数
                stk.pop();
                // 计算规则：第 1 个数 加/减/乘/除 第 2 个数
                if (s == "+") stk.push(first + second);
                if (s == "-") stk.push(first - second);
                if (s == "*") stk.push(first * second);
                if (s == "/") stk.push(first / second);
            }
            // 如果是【数字】，则直接入栈，记得转换成 int 型
            else stk.push(stoi(s));
        }
        // 最后栈顶元素即是逆波兰表达式的计算结果
        int res = stk.top();

        return res;
    }
};


// 二刷
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                if (s == "+") stk.push(first + second);
                if (s == "-") stk.push(first - second);
                if (s == "*") stk.push(first * second);
                if (s == "/") stk.push(first / second);
            }
            else {
                stk.push(stoi(s));
            }
        }

        int res = stk.top();

        return res;
    }
};

