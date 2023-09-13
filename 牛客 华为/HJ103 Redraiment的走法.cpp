

// 题意：
// Redraiment 是走梅花桩的高手。Redraiment可以选择任意一个起点，从前到后，但只能从低处往高处的桩子走
// 他希望走的步数最多，你能替 Redraiment 研究他最多走的步数吗？

// 数据共 2 行，第 1 行先输入数组的个数，第 2 行再输入梅花桩的高度


// DP -> 类似 LC 300 求最长上升子序列

// 状态表示
// f[i] 表示以 nums[i] 结尾的最长上升子序列的长度

// 初始化
// 每个元素都至少可以单独成为子序列，长度至少为 1
// f[0] = f[1] = ... = f[n - 1] = 1

// 状态转移
// 对于每一个遍历的位置 i，都在其前面找一个 j
// 当 nums[j] >= nums[i] 时：nums[i] 无法接在 nums[j] 之后，此情况上升子序列不成立，跳过
// 当 nums[j] < nums[i]  时：nums[i] 可以接在 nums[j] 之后，此情况下最长上升子序列长度为 f[j] + 1
// 每次更新该序列长度的最大值，即：f[i] = max(f[i], f[j] + 1);

#include <iostream>
#include <vector>
using namespace std;
 
int LTS(vector<int>& nums) {
    int n = nums.size();
    int res = 1; // 最长递增子序列的长度至少是 1

    // 定义状态数组
    vector<int> f(n + 1);

    // 初始化 + 状态转移
    for (int i = 0; i < n; i ++ ) {
        f[i] = 1;
        for (int j = 0; j < i; j ++ ) {
            if (nums[j] < nums[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        // 当每个 f[i] 计算完后，更新 res 的最大值
        res = max(res, f[i]);
    }
    
    return res;
}
 
int main() {
    // 读入数组长度 n
    int n;
    cin >> n;

    // 读入 n 个数字
    vector<int> nums(n);
    for (int i = 0; i < n; i ++ ) cin >> nums[i];
    
    cout << LTS(nums) << endl; // 计算最长上升子序列长度
    
    return 0;
}

