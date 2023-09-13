
// 题意：
// 将两个整型数组按照升序合并，并且过滤掉重复数组元素
// 输出时相邻两数之间没有空格


// 输入：
// 3
// 1 2 5
// 4
// -1 0 3 2

// 输出：
// -101235


// 哈希表 + 排序

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    // 读入 n，并将接下来的 n 个数读到 nums 数组中
    int n;
	cin >> n;
    vector<int> nums;
    while (n -- ) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    // 读入 m，并将接下来的 m 个数读到 nums 数组中
    int m;
    cin >> m;
    while (m -- ) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    
    // 对 nums 进行排序
    sort(nums.begin(), nums.end());

    // 定义一个哈希表，用于表示 nums[i] 是否被遍历（1 表示已遍历）
    unordered_map<int, int> hash;

    // 保存最终结果的数组
    vector<int> res;

    // 遍历 nums 数组，如果一个元素还没遍历过，则标记为已遍历，并加入 res 数组
    for (int x: nums) {
        if (hash[x] == 0) {
            hash[x] = 1; // 更新标记
            res.push_back(x);
        }
    }

    // 遍历 res 数组，输出结果
    for (int x: res) cout << x;
    
    cout << endl;
	
	return 0;
}



// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums;

    while (n -- ) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    
    int m;
    cin >> m;
    while (m -- ) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    sort(nums.begin(), nums.end());

    unordered_map<int, int> hash; // 0 表示未遍历过，1 表示已遍历过
    
    vector<int> res;

    for (int x: nums) {
        if (hash[x] == 0) {
            res.push_back(x);
            hash[x] = 1;
        }
    }

    for (int x: res) cout << x;

    cout << endl;

    return 0;
}


