
// 题意：
// 输入 n 个整数，找出其中最小的 k 个整数并按升序输出
// 

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    // 读入 n 和 k
    int n, k;
    cin >> n >> k;

    // 读入 nums 数组
    vector<int> nums;
    for (int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    sort(nums.begin(), nums.end());  // 排序

    // 输出前 k 个小的数字
    for (int i = 0; i < k; i ++ ) {  
        cout << nums[i] << " ";
    }

    return 0;
}


// 二刷
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < k; i ++ ) cout << nums[i] << " ";

    cout << endl;
}

