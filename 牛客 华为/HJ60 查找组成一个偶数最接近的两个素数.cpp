


// 题意：
// 任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况
// 输入一个 > 2 的偶数 x，输出差最小的两个和为 x 的质数

// 暴力枚举
#include <iostream>
using namespace std;
 
// 试除法判断质数
bool isPrime(int x) {
    for (int i = 2; i <= x / i; i ++ ) {
        if (x % i == 0) return false;
    }
    return true; // 遍历完都没有就是素数
}

int main(){
    int n;
    cin >> n;

    int mindis = n - 1; // 最小差值

    pair<int, int> res; // 记录两个素数

    // 遍历 2 到 n 找到素数 i 和 n - i
    for (int i = 2; i < n; i ++ ) { 
        if (isPrime(i) == true && isPrime(n - i) == true) {
            // 如果当前两个素数的差值 < 最小差值，则更新最小差值
            if (abs((n - i) - i) < mindis) {
                res = {i, n - i}; 
                mindis = abs(n - i - i);
            }
        }
    }

    cout << res.first << endl << res.second << endl;
    
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    for (int i = 2; i <= x / i; i ++ ) {  // 注意 i 从 2 开始
        if (x % i == 0) return false;
    }

    return true;
} 

int main() {
    int n;
    cin >> n;

    int min_diff = n;

    vector<int> res(2);

    for (int i = 2; i < n; i ++ ) {
        if (isPrime(i) && isPrime(n - i)) {
            if (abs(n - i - i) < min_diff) {
                res = {i, n - i};
                min_diff = abs(n - i - i);
            }
        }
    }

    cout << res[0] << endl << res[1] << endl;

    return 0;
}




// 优化解法
#include<iostream>
using namespace std;
 
// 模板函数：试除法判断质数
bool isPrime(int x) {
    for (int i = 2; i <= x / i; i ++ ) {
        if (x % i == 0) return false;
    }
    return true; // 遍历完都没有就是素数
}

int main() {
    int n;
    cin >> n;

    int mindis = n - 1;
    pair<int, int> res; //记录两个素数

    // 从中间开始往前枚举第一个质数 i，当第一次遇见两个数都是质数的时候差值最小
    for (int i = n / 2; i > 1; i -- ) { 
        if (isPrime(i) == true && isPrime(n - i) == true) {
            cout << i << endl << n - i << endl;
            break;
        }
    }
    
    return 0;
}




