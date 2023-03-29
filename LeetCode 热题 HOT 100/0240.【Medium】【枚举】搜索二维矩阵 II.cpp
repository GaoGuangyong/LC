
// 查找
// 双指针
// 从二维矩阵的右上角那个数 t 开始枚举，用 i 枚举行，用 j 枚举列
// 如果 t = target, 则找到了答案
// 如果 t > target, 则说明 t 所在列下面的所有数都比 target 大, 因此当前这一列一定没有答案，故可以 j--, 直接去掉当前列
// 如果 t < target, 则说明 t 所在行左面的所有数都比 target 小, 因此当前这一行一定没有答案，故可以 i++, 直接去掉当前行

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 特判：必须先判空，再计算行数与列数，否则报错：runtime error
        if (matrix.empty()) return false; 
        int m = matrix.size(); // 行数
        int n = matrix[0].size(); // 列数

        // 设置行，列指针的初始下标（从右上角开始枚举）
        int i = 0;
        int j = n - 1; 
        // 设置行、列指针的移动范围
        while (i < m && j >= 0) {
            int t = matrix[i][j];
            if (t == target) return true;
            else if (t < target) i ++ ; // 如果比查找目标小，则跳到下一行
            else if (t > target) j -- ; // 如果比查找目标大，则跳到前一列
        }
        return false;
    }
};

// 无注释版本
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n - 1; 
        
        while (i < m && j >= 0) {
            int t = matrix[i][j];
            if (t == target) return true;
            else if (t < target) i ++ ;
            else if (t > target) j -- ;
        }
        return false;
    }
};
