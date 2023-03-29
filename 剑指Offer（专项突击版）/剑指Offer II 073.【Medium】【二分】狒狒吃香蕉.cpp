
// 问题抽象：求 ⌈piles[0] / k⌉ + ⌈piles[1] / k⌉ + ... + ⌈piles[n-1] / k⌉ <= h 时 k 的最小值
// ⌈ ⌉ 表示上取整
// 注意到 k 越小，所花费的时间越长，我们要找到一个最小的 k 满足花费的时间 <= h
// 二分查找这个 k 值，如果花费的时间 <= h，我们就继续减小 k，否则我们增大 k
// k 的取值范围为：1 ~ piles[i] 的最大值

class Solution {
public:
    // 辅助函数：求表达式 ⌈piles[0] / k + ⌈piles[1] / k + ... + ⌈piles[n-1] / k 的和
    int get(vector<int> piles, int k) {
        int res = 0;
        for (int i = 0; i < piles.size(); i ++ ) {
            res += (piles[i] + k - 1) / k;
        }
        return res;
    }

    // 主函数
    int minEatingSpeed(vector<int>& piles, int h) {
        // k 的取值范围为：1 ~ piles[i] 的最大值
        int l = 1;
        int r = 1e9;

        // 二分速度 k    
        while (l < r) {
            int mid = l + r >> 1;
            // 如果当前二分的值 mid 能使表达式 <= h，则答案比 mid 小，或者就是 mid
            if (get(piles, mid) <= h) 
                r = mid;
            else 
                l = mid + 1;
        }
        
        return l;
    }


};



// 无注释版本
class Solution {
public:
    int get(vector<int> piles, int k) {
        int res = 0;
        for (int i = 0; i < piles.size(); i ++ ) {
            res += (piles[i] + k - 1) / k;
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1e9;

        while (l < r) {
            int mid = l + r >> 1;
            if (get(piles, mid) <= h)
                r = mid;
            else 
                l = mid + 1;
        }

        return l;
    }
};


