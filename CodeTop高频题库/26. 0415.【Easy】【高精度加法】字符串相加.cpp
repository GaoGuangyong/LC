// 高精度加法

// 高精度加法模板函数（数组A + 数组B = 数组C）
vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size() || t != 0; i ++ ) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

class Solution {
public:


    string addStrings(string num1, string num2) {
        vector<int> A, B;
        string res;

        for (int i = num1.size() - 1; i >= 0; i -- ) A.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; i -- ) B.push_back(num2[i] - '0');

        vector<int> C = add(A, B);
        for (int i = C.size() - 1; i >= 0; i -- ) res += to_string(C[i]);
        
        return res;
    }
};

