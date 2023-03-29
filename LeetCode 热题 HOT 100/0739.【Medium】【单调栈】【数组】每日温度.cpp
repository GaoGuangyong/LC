// 模板题，数组中找到一个数右边第一个比它大的数（AcWing 算法基础课 第二章 830 单调栈）
// 栈模拟的过程见链接
// https://leetcode-cn.com/problems/daily-temperatures/solution/mei-ri-wen-du-by-leetcode-solution/

// 单调栈

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk; // 维护一个单调栈，因为要返回下标，所以栈里存放数字的下标
        int n = temperatures.size();
        vector<int> res(n); // 定义结果数组

        // 从前往后枚举，维护单调栈
        for (int i = 0; i < n; i ++ ) {
            // 当栈不为空，且当前下标 > 栈顶下标，说明找到了比当前栈顶下标更大的，计算差值，然后将栈顶下标出栈
            while (stk.size() && temperatures[i] > temperatures[stk.top()]) {
                // 计算当前下标 i 与栈顶下标 stk.top() 相差的天数，更新到结果数组中
                res[stk.top()] = i - stk.top(); // 本题核心代码 !!!!!!!
                stk.pop(); // 栈顶出栈
            }
            // 若栈为空 或 当前元素 <= 栈顶元素，将当前下标 i 入栈
            stk.push(i);
        }
        return res;
    }
};

// 无注释版本
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        
        stack<int> stk;

        for (int i = 0; i < n; i ++ ) {
            while (stk.size() && temperatures[i] > temperatures[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        
        return res;
    }
};



