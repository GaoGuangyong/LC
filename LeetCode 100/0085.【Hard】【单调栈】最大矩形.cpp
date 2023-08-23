

// 单调栈（示意图见笔记）
class Solution {
public:
    // 辅助函数：给定高度数组 height，返回所能围城的矩形的最大面积
    int help(vector<int>& heights) {
        int n = heights.size();

        stack<int> stk;
        vector<int> left(n);
        vector<int> right(n);

        // 从前往后扫描，找到每个数字左边离它最近的比它小的数字的位置 left[i]
        for (int i = 0; i < n; i ++ ) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) stk.pop();
            if (stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>(); // 把栈清空

        // 从后往前扫描，找到每个数字右边离它最近的比它小的数字 right[i]
        for (int i = n - 1; i >= 0; i -- ) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) stk.pop();
            if (stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }

        // 遍历每个数字，更新答案（宽 * 高）的最大值
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res = max(res, (right[i] - 1 - left[i]) * heights[i]);
        }

        return res;
    }

    // 主函数：
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(); // 行数
        int n = matrix[0].size(); // 列数

        // 定义二维数组，记录每个格子上面有多少个连续的值为 1 的格子
        vector<vector<int>> heights(m, vector<int>(n));

        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                // 如果当前遍历到的是值为 '1' 的格子
                if (matrix[i][j] == '1') {
                    if (i == 0) heights[i][j] = 1; // 如果是第一行中值为 '1' 的格子，则高度为 1
                    else if (i >= 1) heights[i][j] = heights[i - 1][j] + 1; // 否则，从第二行开始，高度为其上面的格子的高度 + 1
                }
                // 否则，如果当前遍历到的是值为 '0' 的格子，则将高度清空
                else heights[i][j] = 0;
            }
        }

        // 枚举每一行的所有各自构成的高度数组 heights[i]，更新结果的最大值
        int res = 0;
       
        for (int i = 0; i < m; i ++ ) res = max(res, help(heights[i]));
        
        return res;
    }
};



// 无注释版本
class Solution {
public:
    int help(vector<int>& heights) {
        int n = heights.size();

        stack<int> stk;
        vector<int> left(n);
        vector<int> right(n);

        // 从前往后扫描，找到每个数字左边离它最近的比它小的数字的位置 left[i]
        for (int i = 0; i < n; i ++ ) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) stk.pop();
            if (stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>(); // 把栈清空

        // 从后往前扫描，找到每个数字右边离它最近的比它小的数字 right[i]
        for (int i = n - 1; i >= 0; i -- ) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) stk.pop();
            if (stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }

        // 遍历每个数字，更新答案（宽 * 高）的最大值
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res = max(res, (right[i] - 1 - left[i]) * heights[i]);
        }

        return res;
    }

    // 主函数：
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> heights(m, vector<int>(n));

        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (matrix[i][j] == '1') {
                    if (i == 0) heights[i][j] = 1;
                    else if (i >= 1) heights[i][j] = 1 + heights[i - 1][j];
                }
                else heights[i][j] = 0;
            }
        }

        int res = 0;
       
        for (int i = 0; i < m; i ++ ) res = max(res, help(heights[i]));
        
        return res;
    }
};


