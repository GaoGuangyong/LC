

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


#include <bits/stdc++.h>
using namespace std;

int N = 3010;
vector<int> h(N); // 输入的身高数组
vector<int> f(N); // f[i] 表示 s[0 ~ i] 中以 h[i] 结尾的最长上升子序列的长度
vector<int> g(N); // g[i] 表示 s[i ~ n  - 1] 中以 h[i] 开头的最长上升子序列的长度

int main() {
    int n;
    cin >> n; // 读入数组长度 n
    
    for (int i = 0; i < n; i ++ ) { // 读入 n 个数到数组 h
        cin >> h[i];
    }

    // 从前往后遍历，求以 h[i] 结尾的最长上升子序列 s[j ~ i] 的长度
    for (int i = 0; i < n; i ++ ) {
        f[i] = 1; // 子序列的长度至少为 1
        for (int j = 0; j < i; j ++ ) {
            if (h[j] < h[i]) f[i] = max(f[i], f[j] + 1);
        }
    }

    // 从后往前遍历，求以 h[i] 开头的最长下降子序列 s[i ~ j] 的长度
    for (int i = n - 1; i >= 0; i -- ) {
        g[i] = 1; // 子序列的长度至少为 1
        for (int j = n - 1; j > i; j -- ) {
            if (h[j] < h[i]) g[i] = max(g[i], g[j] + 1);
        }
    }

    int maxLen = 0; // 维护最长的合唱队形长度，对于分界点 h[i]，合唱队形长度为 f[i] + g[i] - 1

    // 遍历 h[i]，计算最长的合唱队形长度
    for (int i = 0; i < n; i ++ ) {
        maxLen = max(maxLen, f[i] + g[i] - 1); // -1 是因为 h[i] 被计算了 2 次 
    }

    cout << n - maxLen << endl; // 出队的同学人数 = 总人数 - 剩余人数
    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int N = 3010;

int main() {
    int n;
    cin >> n;

    vector<int> h(N);
    for (int i = 0; i < n; i ++ ) cin >> h[i];

    vector<int> f(N);
    for (int i = 0; i < n; i ++ ) {
        f[i] = 1;
        for (int j = 0; j < i; j ++ ) {
            if (h[j] < h[i]) f[i] = max(f[i], f[j] + 1);
        }
    }

    vector<int> g(N);
    for (int i = n - 1; i >= 0; i -- ) {
        g[i] = 1;
        for (int j = n - 1; j > i; j -- ) {
            if (h[j] < h[i]) g[i] = max(g[i], g[j] + 1);
        }
    }
    
    int maxLen = 0;
    for (int i = 0; i < n; i ++ ) {
        maxLen = max(maxLen, f[i] + g[i] - 1);
    }
    
    cout << n - maxLen << endl;

    return 0;
}
