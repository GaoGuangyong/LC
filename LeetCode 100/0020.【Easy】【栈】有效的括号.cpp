
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。


// 模拟

// '(' 的 ASCII 码为 40
// ')' 的 ASCII 码为 41
// '{' 的 ASCII 码为 123
// '}' 的 ASCII 码为 125
// '[' 的 ASCII 码为 91
// ']' 的 ASCII 码为 93
// ASCII 码关系: ( 和 ) 差 1，[ 和 ] 以及 { 和 } 差 2

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; // 用栈来模拟

        // 遍历字符串
        for (char c: s) {
            // 如果是左括号的话，入栈
            if ( c == '(' || c == '[' || c == '{') stk.push(c);
            // 如果是右括号的话，判断
            else { 
                // 如果栈不空 且 栈顶括号 与 当前括号的 ASCII 值差距 <= 2，则可以匹配，将栈顶弹出
                if (stk.size() && abs(c - stk.top()) <= 2) 
                    stk.pop();
                else // 否则，不匹配
                    return false; 
            }
        }
        
        return stk.empty(); // 如果循环结束后，栈为空，则匹配成功，返回true
    }
};


// 无注释版本
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                if (stk.size() && abs(c - stk.top()) <= 2) stk.pop();
                else return false;
            }
        }

        return stk.empty();
    }
};

