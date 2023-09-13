
// 题意：
// 读入 4 个 [1,10] 的整数，数字允许重复
// 输出一行表示能否得到 24 点，能输出 true，不能输出 false


// 递归 -> 类似 LC 679

#include <iostream>
#include <vector>
using namespace std;

// 递归函数：检查用 nums 数组里的数能不能计算得到 24，当前计算结果是 res
bool check(vector<double> nums, double res) {
    // 递归出口：当数组为空时，判断运算的结果是不是 24
    if (nums.empty()) return res == 24;

    // 遍历 nums 数组，每次选择 nums[i] 在 res 的基础上进行四则运算
    for (int i = 0; i < nums.size(); i ++ ) { 
        // 定义临时数组 temp，存 nums 数组中删去一个数字后剩余的数字
        vector<double> temp(nums);
        temp.erase(temp.begin() + i); // 删除 nums[i]
        // 分别 递归地 进行加减乘除 4 种运算
        bool add = check(temp, res + nums[i]);
        bool sub = check(temp, res - nums[i]);   
        bool mul = check(temp, res * nums[i]);
        bool div = check(temp, res / nums[i]);
        // 只要有其中一种运算地结果是 24，则计算成功，返回 true
        if (add == true || sub == true || mul == true || div == true) return true;
    }

    // 无法得到 24，返回 false
    return false;
}

int main() {
    // 读入 4 个数字
    vector<double> nums(4); // 因为要存计算结果，所以要定义成 double 类型
    for (int i = 0; i < 4; i ++ ) {
        cin >> nums[i];
    }
    
    if (check(nums, 0) == true) // 初始时，结果是 0 
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    return 0;
}


