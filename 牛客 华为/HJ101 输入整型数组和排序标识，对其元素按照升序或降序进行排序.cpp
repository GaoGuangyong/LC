

// 自定义排序 -> 类似 HJ 68

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    // 读入数组长度 n
    int n;
    cin >> n;

    // 读入 n 个数字到 nums 数组
    vector<int> nums;
    for (int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    // 读入排序方式：0 表示升序 1 表示降序
    int flag;
    cin >> flag;

    if (flag == 0) sort(nums.begin(), nums.end());
    else if (flag == 1) sort(nums.begin(), nums.end(), greater<int>());

    for (int x: nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}



