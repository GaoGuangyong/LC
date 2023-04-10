
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
    vector<int> weight(n); // 砝码重量
    for (int i = 0; i < n; i ++ ) 
        cin >> weight[i];
    // 读入 n 种砝码的数量
    vector<int> nums(n); // 砝码数量
    for (int i = 0; i < n; i ++ ) 
        cin >> nums[i];

    unordered_set<int> S; // 定义一个哈希集合，存可能的称重结果，自动去重
    S.insert(0); // 0 也是一种

    for (int i = 0; i < n; i ++ ) { // 遍历每一种砝码 i，其个数为 nums[i]
        for (int j = 1; j <= nums[i]; j ++ ) { // 将当前砝码从 1 个一直累加到 nums[i] 个
            // 定义一个临时集合 T，复制 S 的值（避免陷入死循环）
            unordered_set<int> T(S);
            // 遍历集合 T，将集合 T 的值 + weight[i] 加入 S，如果有重复值，S 会自动去重
            for (auto it = T.begin(); it != T.end(); it ++ ) {
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


