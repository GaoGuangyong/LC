

// 题意：在 N 位同学中，去掉几位，使得剩下的同学身高呈现先递增，后递减的趋势，求最少去掉的同学人数

// f[i] 表示 h1 ~ hi 中，以 hi 结尾的最长上升子序列的长度
// 从前往后遍历，对于每一个遍历的位置 i，都在其前面找一个 j
// 当 h[j] >= h[i] 时：h[i] 无法接在 h[j] 之后，此情况上升子序列不成立，跳过
// 当 h[j] < h[i]  时：h[i] 可以接在 h[j] 之后，此情况下最长上升子序列长度为 f[j] + 1
// 每次更新该序列长度的最大值，即：if (h[j] < h[i]) f[i] = max(f[i], f[j] + 1)

// g[i] 表示 hi ~ hn 中，以 hi 开头的最长下降子序列的长度
// 从后往前遍历，对于每一个遍历的位置 i，都在其后面找一个 j
// 当 h[j] >= h[i] 时：h[i] 无法接在 h[j] 之前，此情况下降子序列不成立，跳过
// 当 h[j] < h[i]  时：h[i] 可以接在 h[j] 之前，此情况下最长下降子序列长度为 g[j] + 1
// 每次更新该序列长度的最大值，即：if (h[j] < h[i]) g[i] = max(g[i], g[j] + 1)


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3010;
int n;
int h[N];
int f[N], g[N];

int main() {
    // 读入数组长度 n
    cin >> n;
    // 将入 n 个数到数组 h
    for (int i = 0; i < n; i ++ ) {
        cin >> h[i];
    }

    // 从前往后遍历，求以 hi 结尾的最长上升子序列的长度
    for (int i = 0; i < n; i ++ ) {
        f[i] = 1; // 子序列的长度至少为 1
        for (int j = 0; j < i; j ++ ) {
            if (h[j] < h[i])
                f[i] = max(f[i], f[j] + 1);
        }
    }

    // 从后往前遍历，求以 hi 开头的最长下降子序列的长度
    for (int i = n - 1; i >= 0; i -- ) {
        g[i] = 1; // 子序列的长度至少为 1
        for (int j = n - 1; j > i; j -- ) {
            if (h[j] < h[i])
                g[i] = max(g[i], g[j] + 1);
        }
    }

    int res = 0;
    // 遍历所有的分界点 i，此时的最长合唱队形长度为 f[i] + g[i] - 1
    for (int i = 0; i < n; i ++ ) {
        res = max(res, f[i] + g[i] - 1); // -1 是因为 hi 被计算了 2 次 
    }

    // 出队的同学人数 = 总人数 - 剩余人数
    cout << n - res << endl;
    return 0;
}

