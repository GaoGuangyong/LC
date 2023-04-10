// 哈希表 + 排序

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


 
int main() {
    vector<int> nums;

    // 读入 n，并将接下来的 n 个数读到 nums 数组中
    int n;
	cin >> n;
    for (int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    // 读入 m，并将接下来的 m 个数读到 nums 数组中
    int m;
    cin >> m;
    for (int i = 0; i < m; i ++ ) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    
    // 对 nums 数组进行排序
    sort(nums.begin(), nums.end());

    // 定义一个哈希表，用于表示 nums[i] 是否被遍历（1 表示已遍历）
    unordered_map<int, int> hash;
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