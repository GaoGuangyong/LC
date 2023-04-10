

// DFS + 回溯

#include <iostream>
#include <vector>
using namespace std;

// 对于每一个 nums 中的元素，可以选择将其加入数组 g5 或 g3，即一个二叉决策树，可以使用回溯算法
// 参数 dif 表示 g5 - g3 的值
// 加入 g5 时 dif += nums[i]
// 加入 g3 时 dif -= nums[i]
void backtrack(vector<int>& nums, int dif, vector<int>& res) {
    // 退出条件：nums 为空
    if (nums.empty()) {
        res.push_back(dif);
        return;
    }
    // 回溯部分
    // 遍历选择列表
    for (int i = 0; i < 2; i ++ ) {
        // 选择
        int temp = nums[nums.size() - 1];
        nums.pop_back();

        if (i == 0)
            backtrack(nums, dif + temp, res);
        else
            backtrack(nums, dif - temp, res);

        // 撤销选择
        nums.push_back(temp);
    }
}

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        int g5sum=0;
        int g3sum=0;
        vector<int> waiting;
        for (int x: nums) {
            if (x % 5 == 0)
                g5sum += x;
            else if (x % 3 == 0)
                g3sum += x;
            else
                waiting.push_back(x);
        }
        vector<int> res;
        backtrack(waiting, g5sum - g3sum, res);
        bool flag = false;
        for (int x: res)
            if (x == 0)
                flag = true;
        if (flag == true)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}




