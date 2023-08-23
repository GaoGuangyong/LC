

// 字符串版本的高精度加法

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string add(string s1, string s2) {
    // 先把两个字符串类型的数字逆序存到数组中
    vector<int> A;
    vector<int> B;
    for (int i = s1.size() - 1; i >= 0; i -- ) A.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i -- ) B.push_back(s2[i] - '0');
    
    // 计算答案
    vector<int> C;
    int t = 0; // 进位
    for (int i = 0; i < A.size() || i < B.size() || t != 0; i ++ ) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10); // 相加后结果的个位数即为 C[i]
        t /= 10; // 计算进位
    }

    // 把数组 C 逆序转换成字符串返回
    string res;
    for (int i = C.size() - 1; i >= 0; i -- ) {
        res += to_string(C[i]);
    }
    return res;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    
    cout <<  add(str1, str2) << endl;
    
    return 0;
}


