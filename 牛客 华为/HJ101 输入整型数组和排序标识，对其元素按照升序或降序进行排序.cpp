

// 题意：
// 输入整型数组和排序标识，对其元素按照升序或降序进行排序

// 第一行输入数组元素个数
// 第二行输入待排序的数组，每个数用空格隔开
// 第三行输入一个整数0或1。0代表升序排序，1代表降序排序



// 输入：
// 8
// 1 2 4 9 3 55 64 25
// 0

// 输出：
// 1 2 3 4 9 25 55 64




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
    vector<int> nums(n);
    for (int i = 0; i < n; i ++ ) cin >> nums[i];

    // 读入排序方式：0 表示升序 1 表示降序
    int flag;
    cin >> flag;

    if (flag == 0) sort(nums.begin(), nums.end());
    else if (flag == 1) sort(nums.rbegin(), nums.rend()); // 等价于 sort(nums.begin(), nums.end(), greater<int>());

    for (int x: nums) cout << x << " ";
    
    cout << endl;

    return 0;
}



