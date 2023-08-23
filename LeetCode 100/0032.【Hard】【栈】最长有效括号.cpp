
// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。


// 合法的括号序列需满足的两条性质：
// 1、左右括号数相等
// 2、任意前缀中，左括号数 >= 右括号数

// 用栈维护当前待匹配的左括号的位置
// 用 start 记录每段第一次遇到不合法的括号序列时的右括号的位置（当右括号数第一次大于左括号数时的那个右括号的位置），初始设为 -1
// 即用 start 将整个括号序列划分成若干个不合法的子序列（start 位于每一段子序列的前一个位置，也就是上一个子序列的最后一个位置）

// 从每个子序列的最后一个右括号开始枚举所有的右括号，找与之匹配的最远的左括号

//【1】遇到左括号，当前下标进栈
//【2】遇到右括号，且当前栈不空，则当前栈顶出栈。

//【2-1】出栈后，如果栈不空，说明还有左括号，更新答案 i - stk.top()
// 例："(()()"，假如此时 i 匹配到了最后一个 ) 的位置 4，此时栈为 {0, 3}
// 首先第一步先把栈顶弹出去，此时栈为 {0}，那么 s[0(栈顶) + 1 ~ 4] 是一个合法序列，长度 = i - stk.top() = 4 - 0  = 4

//【2-2】出栈后，如果栈为空，说明没有左括号，更新答案 i - start                 
// 例："()()"， 假如此时 i 匹配到了最后一个 ) 的位置 3，此时栈为 {2}
// 首先第一步先把栈顶弹出去，此时栈为 {}，那么 s[-1(start) ~ 3] 是一个合法序列，长度 = i - start = 3 - (-1)  = 4

//【3】遇到右括号，且当前栈为空，则当前的子序列不再可能为合法序列了，当前右括号的下标就是 start，更新 start = i

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;

        int start = -1; // start 表示上一段第一次出现不合法的括号序列时的右括号的位置
        
        for (int i = 0; i < s.size(); i ++ ) {
            // 如果遇到左括号，则下标入栈
            if (s[i] == '(') stk.push(i);
            // 否则，如果遇到右括号
            else { 
                // 若此时栈不为空，将当前右括号匹配掉
                if (!stk.empty()) { 
                    // 栈顶左括号出栈，匹配掉当前右括号
                    stk.pop(); 
                    // 如果栈不空，说明栈中还有左括号，更新答案 i - stk.top() 的最大值
                    if (!stk.empty()) res = max(res, i - stk.top());
                    // 如果栈为空，如果栈中没有左括号，更新答案 i - start 的最大值
                    else if (stk.empty()) res = max(res, i - start);
                } 
                // 若此时栈为空，则不可能匹配成功，此时的右括号位置就是 start
                else {
                    start = i;
                }
            }
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;

        int start = -1;

        int res = 0;

        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] == '(') stk.push(i);
            else {
                if (!stk.empty()) {
                    stk.pop();
                    if (!stk.empty()) res = max(res, i - stk.top());
                    else res = max(res, i - start);
                }
                else {
                    start = i;
                }
            }
        }

        return res;
    }
};