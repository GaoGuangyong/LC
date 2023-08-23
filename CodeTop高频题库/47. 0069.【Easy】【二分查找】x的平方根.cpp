// 二分

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return x;
        
        int l = 1;
        int r = x;
        
        while (l <= r) {
            int mid = l + (r - l) / 2; // 这样不会整型溢出
            int sqrt = x / mid;
            if (sqrt == mid)
                return mid;
            else if (mid > sqrt)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        
        return r;
    }
};


// 解法二：AcWing 模板
// 二分出最大的 mid，满足 mid^2 <= x 则 mid 就是答案
// mid 的取值范围：[0 ~ x]
// 注意 l + r 可能爆 int

class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        
        while (l < r) {
            int mid = l + r + 1ll >> 1;
            // 如果 mid^2 <= x，则答案在 mid 右边或 mid 就是答案
            if (mid <= x / mid) 
                l = mid;
            else 
                r = mid - 1;
        }

        return r;
    }
};



// 二刷
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;

        while (l < r) {
            long long mid = l + r + 1ll >> 1;
            if (mid <= x / mid) 
                l = mid;
            else 
                r = mid - 1;
        }

        return l;
    }
};