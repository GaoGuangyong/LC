/*

// 高精度乘法
// 巧妙的方法：先不考虑进位，最后再加进位（好处：代码好写）


         1    2    3      A[]
     ×   4    5    6      B[]
 —————————————————————
         6    12   18
     5   10   15
 4   8   12
 —————————————————————
 4   13  28   27   18
 —————————————————————
 5   6   0    8    8      C[]

[4,  3,  2,   1,   0]     下标


*/

class Solution {
public:
    string multiply(string num1, string num2) {
        // 定义数组 A 和 B 来记录数字 num1 和 num2，注意存到数组中时要反过来
        vector<int> A;
        vector<int> B;
        int n = num1.size();
        int m = num2.size();
        for (int i = n - 1; i >= 0; i --) A.push_back(num1[i] - '0');
        for (int j = m - 1; j >= 0; j --) B.push_back(num2[j] - '0');

        // 先不考虑进位
        vector<int> C(n + m);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                C[i + j] += A[i] * B[j]; // 如上面例子所示，A[i] 乘 B[j] 的结果最终被加到了 C[i + j] 的位置

        // 再加上进位 t
        int t = 0;
        for (int i = 0; i < C.size(); i ++ ) {
            t += C[i]; // 每次先把当前的 c[i] 加到上一位的进位 t 上
            C[i] = t % 10; // t % 10 就是当前位置的数
            t /= 10; // t / 10 就是进位
        }

        // 去掉高位的 0
        int k = C.size() - 1;
        while (k > 0 && C[k] == 0)
            k --;

        // 从高位到低位插入到字符串 res 中得到答案
        string res;
        while (k >= 0) {
            res += C[k] + '0'; // 将每一位整数转化成字符后插入 res
            k --;
        }

        return res;
    }
};

