
// 模拟
// 画图分析

// pushed = [1,2,3,4,5]
// popped = [4,5,3,2,1]

// 遍历 pushed 序列，将其元素压入辅助栈，并且判断当前要弹出的 poped[i] 是否为辅助站的栈顶：
// 是：弹出 stk.pop()
// 否：继续遍历 pushed 序列

// 当 pushed 序列已遍历完时
// 若仍未找到，则不匹配
// 若辅助栈为空，则说明匹配


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk; // 辅助栈

        int j = 0; // 用 j 遍历 poped 序列

        // 用 i 遍历 pushed 序列
        for (int i = 0; i < pushed.size(); i ++ ) {
            stk.push(pushed[i]); // 将 pushed[i] 入栈
            // 当栈不空 && 栈顶元素 == 出栈元素 poped[j]，则匹配，栈顶元素出栈
            while (stk.size() && stk.top() == popped[j]) { 
                stk.pop();
                j ++ ; // 每匹配（出栈）一个元素，就将 j 指向下一个位置
            }
        }

        // 如果最后辅助栈为空，则说明是合法的序列
        return stk.empty(); 
    }
};


// 无注释版本
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk; 
        
        int j = 0; 
        for (int i = 0; i < pushed.size(); i ++ ) { 
            stk.push(pushed[i]);
            while (stk.size() && stk.top() == popped[j]) { 
                stk.pop();
                j ++ ;
            }
        }

        return stk.empty(); 
    }
};
