


#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    // 读入 n 和 k
    int n = 0;
    int k = 0;
    cin >> n >> k;

    // 读入 nums 数组
    vector<int> nums;
    for (int i = 0; i < n; i ++ ) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());  // 排序

    // 输出前 k 个小的数字
    for (int i = 0; i < k; i ++ ) {  
        cout << nums[i] << " ";
    }

    return 0;
}

