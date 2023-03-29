
// 枚举

class Solution {
public:
    vector<int> constructArr(const vector<int>& A) {
        if (A.empty()) return {}; // 如果数组 A 为空，则返回空数组

        int n = A.size();
        vector<int> B(n); // 结果数组，长度为 n，默认值为 0

        // 从前往后遍历，用 p 存前 i 个数的乘积
        // B[i] = p，即 B[i] 表示前 i 个数的乘积：B[i] = A[0] * A[1] * ... * A[i - 1] 
        int p = 1; 
        for (int i = 0; i < n; i ++ ) {
            B[i] = p;
            p *= A[i];
        }

        // 从后向前遍历，用 p 存后 n - i - 1 个数的乘积
        // B[i] *= p，即 B[i] 再乘上后 n - i - 1 个数的乘积
        p = 1;
        for (int i = n - 1; i >= 0; i -- ) {
            B[i] *= p;
            p *= A[i];
        }

        // 最终，B[i] = A[0] * A[1] * ... * A[i - 1] * A[i + 1] * ... * A[n - 1]
        return B;
    }
};



// 无注释版本
class Solution {
public:
    vector<int> constructArr(const vector<int>& A) {
        if (A.empty()) return {};

        int n = A.size();
        vector<int> B(n);

        int p = 1; 
        for (int i = 0; i < n; i ++ ) {
            B[i] = p;
            p *= A[i];
        }

        p = 1;
        for (int i = n - 1; i >= 0; i -- ) {
            B[i] *= p;
            p *= A[i];
        }

        return B;
    }
};


