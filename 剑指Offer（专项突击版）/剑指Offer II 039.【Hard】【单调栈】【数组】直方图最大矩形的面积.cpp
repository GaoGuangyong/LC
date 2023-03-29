
// 单调栈
// 把所有的数放入栈中，只要入栈的数比栈顶小，就不断把栈顶删掉，直到当前要入栈的数比栈顶大
// 此题的本质是找到每个柱形条左边和右边，离它最近的比它低的矩形条，然后用宽度乘上当前柱形条的高度作为备选答案
// 即对于每个数，从左扫描一遍找到这个数左边离它最近的比它小的数的位置，从右扫描一遍找到这个数右边离它最近的比它小的数的位置

// 举例说明，为方便，将图中每个矩形右侧那条边定义为当前数字的下标，故整个矩形的下标就可以写成 [-1, 0, 1, 2, 3, 4, 5, 6] 
// heights = [    2, 1, 5, 6, 2, 3   ]
//  index = [-1, 0, 1, 2, 3, 4, 5, 6]
// 设当前遍历到了 heights[i] = 5 (index = 2)
// 其左边离它最近的比它小的数是 1 (index = 1)，因此 left[i] = 1
// 其右边离它最近的比它小的数是 2 (index = 4)，因此 right[i] = 4
// 所围城的矩形面积就是 (right[i] - left[i] - 1) * heights[i] = (4 - 1 - 1) * 5 = 10

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n); // 记录每个数字左边离当前数字最近的那个数的位置
        vector<int> right(n); // 记录每个数字右边离当前数字最近的那个数的位置
        stack<int> stk; // 单调栈，存放每个数字的下标

        // 从前往后扫描，找到每个数字左边离它最近的比它小的数字的位置 left[i]
        for (int i = 0; i < n; i ++ ) {
            // 当前数字 <= 栈顶下标对应的数字，就不断把栈顶删掉（保证栈不空）
            while (stk.size() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            // 如果此时栈空了，则说明当前数字比左边所有的数字都大，故可以取到最左边的左边一个位置（设为 -1）
            if (stk.empty()) left[i] = -1;
            // 否则，如果此时栈里还有元素(下标)，则此时栈顶下标就是当前数字左边离它最近的比它小的数字的位置
            else left[i] = stk.top();
            // 最后将当前下标入栈
            stk.push(i);
        }

        // 把栈清空
        stk = stack<int>();

        // 从后往前扫描，找到每个数字右边离它最近的比它小的数字 right[i]
        for (int i = n - 1; i >= 0; i -- ) {
            // 当前数字 <= 栈顶下标对应的数字，就不断把栈顶删掉（保证栈不空）
            while (stk.size() && heights[stk.top()] >= heights[i]) { 
                stk.pop();
            }
            // 如果此时栈空了，则说明当前数字比右边所有的数字都大，故可以取到最右边的右边一个位置（设为 n）
            if (stk.empty()) right[i] = n;
            // 否则，如果此时栈里还有元素(下标)，则此时栈顶下标对应的数字就是当前数字右边离它最近的比它小的数字的位置
            else right[i] = stk.top();
            // 最后将当前下标入栈
            stk.push(i);
        }

        // 遍历每个数字，更新答案（长 * 高）的最大值
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> stk;

        for (int i = 0; i < n; i ++ ) {
            while (stk.size() && heights[stk.top()] >= heights[i]) 
                stk.pop();
            if (stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
            
        }

        stk = stack<int>();

        for (int i = n - 1; i >= 0; i -- ) {
            while (stk.size() && heights[stk.top()] >= heights[i]) 
                stk.pop();
            if (stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
            
        }

        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res = max(res, heights[i] * (right[i] - 1 - left[i]));
        }

        return res;
    }
};


// 框架版本
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {

        // 记录每个数字左边离当前数字最近的那个数的位置
        // 记录每个数字右边离当前数字最近的那个数的位置
        // 单调栈，存放每个数字的下标

        // 从前往后扫描，找到每个数字左边离它最近的比它小的数字的位置 left[i]
        
            // 当前数字 <= 栈顶下标对应的数字，就不断把栈顶删掉（保证栈不空）

            // 如果此时栈空了，则说明当前数字比左边所有的数字都大，故可以取到最左边的左边一个位置（设为 -1）

            // 否则，如果此时栈里还有元素(下标)，则此时栈顶下标就是当前数字左边离它最近的比它小的数字的位置
            
            // 最后将当前下标入栈
            


        // 把栈清空


        // 从后往前扫描，找到每个数字右边离它最近的比它小的数字 right[i]
        
            // 当栈不空 且 当前数字 <= 栈顶下标对应的数字，就不断把栈顶删掉（保证栈不空）
            
            // 如果此时栈空了，则说明当前数字比右边所有的数字都大，故可以取到最右边的右边一个位置（设为 n）
            
            // 否则，如果此时栈里还有元素(下标)，则此时栈顶下标对应的数字就是当前数字右边离它最近的比它小的数字的位置
            
            // 最后将当前下标入栈
        


        // 遍历每个数字，更新答案（宽 * 高）的最大值

    }
};



