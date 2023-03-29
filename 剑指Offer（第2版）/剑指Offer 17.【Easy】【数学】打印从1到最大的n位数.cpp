// 数学
// 最大的 n 位数 max 与 n 的关系： max = 10^n - 1
// 先求出 t = 10^n，然后将 1 ~ t - 1 加入结果数组 

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;

        // 计算 t = 10^n
        int t = 1;
        while (n -- ) {
            t *= 10;
        }

        // 打印 [1 ~ t - 1] 即 1 到最大的 n 位数
        for (int i = 1; i <= t - 1; i ++ ) {
            res.push_back(i);
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;

        int t = 1;
        while (n -- ) t *= 10;
    
        for (int i = 1; i <= t - 1; i ++ ) {
            res.push_back(i);
        }

        return res;
    }
};


