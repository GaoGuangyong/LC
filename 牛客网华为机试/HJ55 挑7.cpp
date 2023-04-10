

// 题意：枚举 1 ~ 7，输出和 7 有关的树的个数


// 解法一：
#include<iostream>
#include<string>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int res = 0;

    // 枚举 7 到 n，如果能整除 7 或者转化成字符串后能找到字符 7，则 res ++ 
    for (int i = 7; i <= n; i ++ )
        if (i % 7 == 0 || to_string(i).find('7', 0) != -1) 
            res ++ ;
    cout << res << endl;
    
    return 0;
}

// 解法二：
#include<iostream>
using namespace std;
 
bool select7(int i) {
    // 如果是 7 的倍数
    if (i % 7 == 0) 
        return true;
    // 连除法，判断数字里是否包含 7
    while (i != 0) { 
        // 每次取模，判断个位是否为 7
        if (i % 10 == 7) return true;
        // 丢弃个位
        i /= 10;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int res = 0;

    // 枚举 7 到 n，如果符合条件，则 res ++ 
    for (int i = 7; i <= n; i ++ ) {
        if (select7(i) == true)
            res ++ ;
    }
    cout << res << endl;
    
    return 0;
}

