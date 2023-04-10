


// 题意：输入一个 > 2 的偶数 x，输出插值最小的两个和为 x 的质数

// 暴力枚举
#include<iostream>
using namespace std;
 
// 试除法判断质数
bool isPrime(int x) {
    
    for (int i = 2; i <= x / i; i ++ ) {
        if (x % i == 0) return false;
    }
    return true; //遍历完都没有就是素数
}


int main(){
    int n;
    cin >> n;
    int mindis = n - 1; // 最小差值
    pair<int, int> res; // 记录两个素数

    // 遍历 2 到 n 找到两个素数：i 和 n - i
    for (int i = 2; i < n; i ++ ) { 
        if (isPrime(i) == true && isPrime(n - i) == true) {
            // 如果当前两个素数的差值 < 最小差值，则更新最小差值
            if (abs(n - i - i) < mindis) {
                res = {i, n - i}; 
                mindis = abs(n - i - i);
            }
        }
    }
    cout << res.first << endl << res.second << endl;
    
    return 0;
}

// 优化解法
#include<iostream>
using namespace std;
 
// 试除法判断质数
bool isPrime(int x) {
    
    for (int i = 2; i <= x / i; i ++ ) {
        if (x % i == 0) return false;
    }
    return true; //遍历完都没有就是素数
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




