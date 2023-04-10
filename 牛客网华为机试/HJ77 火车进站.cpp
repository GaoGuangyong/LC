
// 全排列 + 栈 -> 类似 LC 946
// 根据描述：只有后进站的火车出站了，先进站的才能出站，符合栈的特性
// 题意：输入进栈顺序，输出所有可能的出栈顺序

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 辅助函数
bool check(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk; // 辅助栈

    // 用 j 遍历 poped 序列
    int j = 0; 

    // 用 i 遍历 pushed 序列
    for (int i = 0; i < pushed.size(); i ++ ) { 
        // 将 pushed[i] 入栈
        stk.push(pushed[i]);
        // 当栈不空，且栈顶元素 == 出栈元素 poped[j]，则栈顶元素出栈
        while (stk.size() && stk.top() == popped[j]) { 
            stk.pop();
            j ++ ; // 每出栈一个元素，j 指向下一个位置
        }
    }

    // 如果最后辅助栈为空，则说明是合法的序列
    return stk.empty(); 
}

int main() {
    // 读入 n 
    int n;
    cin >> n;
    // 读入进栈序列到 nums 数组
    vector<int> nums(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> nums[i];
    }
    
    vector<int> pushed(nums); // 将进栈序列 nums 用 pushed 数组保存

    sort(nums.begin(), nums.end()); // 对进栈序列排序，得到字典序最小的序列

    vector<vector<int>> poped; // 存所有的出栈序列（按字典序）
    poped.push_back(nums); // 将字典序最小的序列加入 poped 数组

    // 使用 next_permutation 库函数，找到 nums 的下一个排列，加入 poped 数组
    while (next_permutation(nums.begin(), nums.end()) == true) {
        poped.push_back(nums);
    }

    // 遍历 poped 数组中的出栈序列，逐一和进栈序列比较，如果合法，就输出对应的出栈序列
    for (int i = 0; i < poped.size(); i ++ ) {
        if (check(pushed, poped[i]) == true) {
            for (int j = 0; j < n; j ++ ) {
                cout << poped[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}


