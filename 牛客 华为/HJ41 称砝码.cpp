

// 题意：
// 现有 n 种砝码，重量互不相等，分别为 m1, m2, m3, ..., mn
// 每种砝码对应的数量为 x1, x2, x3, ..., xn 
// 现在要用这些砝码去称物体的重量(放在同一侧)，问能称出多少种不同的重量。

// 输入描述：
// 第一行：n                  --- 砝码的种数         (范围[1,10])
// 第二行：m1 m2 m3 ... mn    --- 每种砝码的重量     (范围[1,2000])
// 第三行：x1 x2 x3 .... xn   --- 每种砝码对应的数量 (范围[1,10])


// 解法一：哈希集合

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    // 读入 n 
    int n;
    cin >> n;

    // 读入 n 种砝码的重量
    vector<int> weight(n);
    for (int i = 0; i < n; i ++ ) cin >> weight[i];

    // 读入 n 种砝码的数量
    vector<int> nums(n);
    for (int i = 0; i < n; i ++ ) cin >> nums[i];
    
    unordered_set<int> S; // 定义一个哈希集合，存可能的称重结果，会自动去重

    S.insert(0); // 重量 0 也是答案的一种

    // 遍历每一种砝码，其个数为 nums[i]，重量为 weight[i]
    for (int i = 0; i < n; i ++ ) { 
        for (int j = 1; j <= nums[i]; j ++ ) { // 将当前砝码从 1 个一直累加到 nums[i] 个
            unordered_set<int> T(S); // 定义一个临时集合 T，复制 S 的值（避免陷入死循环，或者说迭代器失效）
            for (auto it = T.begin(); it != T.end(); it ++ ) { // 遍历临时集合 T 中的重量，将现有重量 + weight[i] 加入集合 S
                S.insert(*it + weight[i]);
            }
        }
    }

    cout << S.size() << endl; // 最后集合的大小就是可能的称重结果数
    return 0;
}

/* 关于避免陷入死循环的说明
    如果直接遍历原来的 S，假如 S 里面是 0，1，2；你现在 weight[i] 是 1，那么应该对 S 插入 1，2，3，   
    当你插入 3 的时候 S.size() 增加 1，变成 0，1，2，3；这时候会继续遍历 S 最后一位 3，
    S 插入 3 + 1，S 变成 0，1，2，3，4；S.size() 再增加 1，S 继续插入 4 + 1，之后无限循环不会停止
*/


// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weight(n);
    for (int i = 0; i < n; i ++ ) cin >> weight[i];

    vector<int> cnt(n);
    for (int i = 0; i < n; i ++ ) cin >> cnt[i];

    unordered_set<int> S;
    S.insert(0);

    for (int i = 0; i < n; i ++ ) {
        for (int j = 1; j <= cnt[i]; j ++ ) {
            unordered_set<int> T(S);
            for (auto it = T.begin(); it != T.end(); it ++ ) {
                S.insert(*it + weight[i]);
            }
        }
    }

    cout << S.size() << endl;
    
    return 0;
}


