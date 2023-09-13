

// 题意：
// 给定一些同学的信息（名字，成绩）序列，请你将他们的信息按照成绩从高到低或从低到高的排列，相同成绩按先录入排列在前的规则处理（即不改变顺序 -> 稳定排序）

// 第一行输入要排序的人的个数 n
// 第二行输入一个整数表示排序的方式（0 代表降序，1 代表升序）
// 之后 n 行分别输入他们的名字和成绩，以一个空格隔开

// 输入：
// 3
// 0
// fang 90
// yang 50
// ning 70

// 输出：
// yang 50
// ning 70
// fang 90


// 自定义排序
// 根据题意，相同成绩按录入顺序排列（稳定排序）

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, int> PSI;  // 小技巧 ！！！！！存俩俩空格分开的数据 -> pair

// 降序
static bool cmp_0(PSI a, PSI b) {
    return a.second > b.second;
}

// 升序
static bool cmp_1(PSI a, PSI b) {
    return a.second < b.second;
}


int main() {
    // 读入元素个数 及 排序方式
    int n;
    int flag; // 0 ：降序 1 ：升序
    cin >> n >> flag;

    // 定义一个 pair 数组，读入 名字和成绩
    vector<PSI> arr(n);
    for (int i = 0; i < n; i ++ ) {
        string name;
        int grade;
        cin >> name >> grade;
        arr[i] = {name, grade};
    }

    // 如果 flag == 0，则表示是降序排序
    if (flag == 0) stable_sort(arr.begin(), arr.end(), cmp_0);
    
    // 如果 flag == 1，则表示是升序排序
    else stable_sort(arr.begin(), arr.end(), cmp_1);

    // 输出排序后的结果
    for (int i = 0; i < n; i ++ ) {
        cout << arr[i].first << ' ' << arr[i].second << endl;
    }
    
    return 0;
}



