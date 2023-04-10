
// 解法一：递归
#include <iostream>
using namespace std;

int dfs(int n) {
    // 递归出口：剩 1 瓶，则没法喝到，剩 2 瓶，借 1 瓶，喝完换 1 瓶还老板
    if (n == 1) return 0;
    if (n == 2) return 1;
    // 否则继续递归，每次拿 3 瓶，换 1 瓶：即每次消耗 2 瓶，喝到汽水 + 1
    return dfs(n - 2) + 1;
}

int main() {
    int n;
    while (cin >> n, n != 0) {
        cout << dfs(n) << endl;
    }

    return 0;
}


// 解法二：迭代
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n, n != 0) {
        int cnt = 0;
        while (n > 2) {
            cnt ++ ;
            n -= 2;
        }
        if (n == 2) cout << ++ cnt << endl;
        else cout << cnt << endl;
    }

    return 0;
}

// 解法三：数学规律
#include<iostream>
using namespace std;
 
int main() {
    int n;
    while (cin >> n, n != 0) {
        cout << n / 2 << endl; // 直接输出 n / 2
    }
    return 0;
}

