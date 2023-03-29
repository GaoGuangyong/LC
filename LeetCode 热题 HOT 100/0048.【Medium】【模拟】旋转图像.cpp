
// 解法一：
// 将矩阵顺时针旋转 90 度
// 第一步：沿着对角线翻转
// 第二部：沿着中轴左右翻转

// 总结
// 顺时针 90： 主对角线（从左上到右下）翻转，然后从中间左右翻转
// 逆时针 90： 主对角线翻转，然后从中间上下翻转
// 顺时针 180 和 逆时针 180 都是先主对角线翻转，然后副对角线翻转


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // 获取矩阵的行数
        // 遍历矩阵，沿对角线翻转
        for (int i = 0; i < n; i ++ ) { // 枚举每一行
            for (int j = 0; j < i; j ++ ) { // 枚举每一列：到 i 即可
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 再遍历矩阵，沿中轴左右翻转
        for (int i = 0; i < n; i ++ ) { // 枚举每一行
            for (int j = 0, k = n - 1; j < k; j ++, k -- ) { // 枚举每一列：从前往后 && 从后往前
                swap(matrix[i][j], matrix[i][k]);
            }
        }
    }
};


// 无注释版本
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 遍历矩阵，沿对角线翻转
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < i; j ++ ) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 再遍历矩阵，沿中轴左右翻转
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0, k = n - 1; j < k; j ++ , k -- ) {
                swap(matrix[i][j], matrix[i][k]);
            }
        }
    }
};





// 解法二：找规律（不推荐）
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //按圈处理
        for(int L = n; L > 0; L -= 2){
            int row = (n - L) / 2; //当前圈的行号
            int col = row; //当前圈的列号
            //当前这一圈，只需处理最上面那行的前 L-1 个元素
            for(int k = 0; k < L-1; k++){
                //获取当前元素的坐标 (r,c)
                int r = row;
                int c = col + k;
                //备份一下第一个元素的值
                int temp = matrix[r][c];
                //从 (r,c) 开始找循环节，循环节长度是4 !!!!!
                for(int i = 0; i < 4; i++){
                    //得到循环节下一个位置元素的坐标 (rr,cc)
                    int rr = c;
                    int cc = n - 1 - r;
                    //【1】将 matrix[r][c] 的值 -> matrix[rr][cc]
                    //【2】备份 matrix[rr][cc]
                    swap(temp, matrix[rr][cc]);
                    //移动坐标
                    r = rr;
                    c = cc;
                }
            }
        }
    }
};