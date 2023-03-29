// 单调栈（示意图见笔记）
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(); // 行数
        int n = matrix[0].size(); // 列数

        // 定义一个二维数组，存每个格子上面有多少个连续的值为 1 的格子
        vector<vector<int>> height(m, vector<int>(n));

        // 枚举二维数组，求出每个格子上面有多少个连续的值为 1 的格子
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (matrix[i][j] == '1') {  
                    if (i >= 1) height[i][j] = 1 + height[i - 1][j];
                    // 特别的，如果是第一行中值为 '1' 的格子
                    else if (i == 0) height[i][j] = 1;
                }
                else if (matrix[i][j] == '0') height[i][j] = 0;
            }
        }

        int res = 0;
        // 枚举每一行的所有格子，更新结果的最大值
        for (int i = 0; i < m; i ++ ) {
            res = max(res, largestRectangleArea(height[i]));
        }
        return res;
    }

    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        vector<int> left(n); // 记录每个数字左边离当前数字最近的那个数的位置
        vector<int> right(n); // 记录每个数字右边离当前数字最近的那个数的位置
        stack<int> stk; // 单调栈，存放每个数字的下标

        // 从前往后扫描，找到每个数字左边离它最近的比它小的数字的位置 left[i]
        for (int i = 0; i < n; i ++ ) {
            // 当栈不空 且 当前数字 <= 栈顶下标对应的数字，就不断把栈顶删掉
            while (!stk.empty() && height[i] <= height[stk.top()]) stk.pop();
            // 如果此时栈空了，则说明当前数字比左边所有的数字都大
            // 故可以取到最左边的左边一个位置（设为 -1）
            if (stk.empty()) left[i] = -1;
            // 否则，如果此时栈里还有元素(下标)
            // 则此时栈顶下标对应的数字就是当前数字左边离它最近的比它小的数字的位置
            else left[i] = stk.top();
            stk.push(i);
        }
        // 把栈清空
        stk = stack<int>();
        // 从后往前扫描，找到每个数字右边离它最近的比它小的数字 right[i]
        for (int i = n - 1; i >= 0; i -- ) {
            // 当栈不空 且 当前数字 <= 栈顶下标对应的数字，就不断把栈顶删掉
            while (!stk.empty() && height[i] <= height[stk.top()]) stk.pop();
            // 如果此时栈空了，则说明当前数字比右边所有的数字都大
            // 故可以取到最右边的右边一个位置（设为 n）
            if (stk.empty()) right[i] = n;
            // 否则，如果此时栈里还有元素(下标)
            // 则此时栈顶下标对应的数字就是当前数字右边离它最近的比它小的数字的位置
            else right[i] = stk.top();
            stk.push(i);
        }
        int res = 0;
        // 遍历每个数字，计算答案
        for (int i = 0; i < n; i ++ ) {
            res = max(res, height[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};




// 无注释版本

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size();

        vector<vector<int>> height(m, vector<int>(n));

        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (matrix[i][j] == '1') {
                    if (i >= 1) height[i][j] = 1 + height[i - 1][j];
                    else if (i == 0) height[i][j] = 1;
                }
                else if (matrix[i][j] == '0') height[i][j] = 0;
            }
        }

        int res = 0;
        for (int i = 0; i < m; i ++ ) {
            res = max(res, largestRectangleArea(height[i]));
        }
        return res;
    }

    // 辅助函数
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