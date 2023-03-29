
// 三路递归
// 三个序列分别是丑数序列 乘以 2，3，5 的结果

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res; // 丑数序列
        res.push_back(1); // 先将 1 加入丑数序列

        // 初始时，i, j, k 都指向每个序列的第一个数（下标 0）
        int i = 0;
        int j = 0;
        int k = 0;  

        // 循环 n - 1 次（因为第一个数是 1，已经有了，要求第 n 个数，还需要 n - 1 个数）
        while (-- n) { 
            // 每次将三个序列中的最小的数 t 加入丑数序列
            int t = min(res[i] * 2, min(res[j] * 3, res[k] * 5));
            res.push_back(t);

            // 将最小的数对应的 i, j, k 向后移一位
            if (res[i] * 2 == t) i ++ ;
            if (res[j] * 3 == t) j ++ ;
            if (res[k] * 5 == t) k ++ ;
        }

        return res.back(); // 最终，丑数序列的最后一个数就是答案
    }
};


// 无注释版本
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        res.push_back(1);

        int i = 0;
        int j = 0;
        int k = 0;  

        while (-- n) { 
            int t = min(res[i] * 2, min(res[j] * 3, res[k] * 5));
            res.push_back(t);

            if (res[i] * 2 == t) i ++ ;
            if (res[j] * 3 == t) j ++ ;
            if (res[k] * 5 == t) k ++ ;
        }

        return res.back();
    }
};

