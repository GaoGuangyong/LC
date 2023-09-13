

// 题意：

// 输入一个只包含小写英文字母和数字的字符串，按照不同字符统计个数 由多到少 输出，如果统计的个数相同，则按照 ASCII码 由小到大 输出


// 输入：
// aaddccdc

// 输出：
// cda

// 说明：
// c 和 d 出现 3 次，a 出现 2 次，但 c 的 ASCII 码比 d 小，所以先输出 c，再输出 d，最后输出 a


// 哈希表 + 自定义排序

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
 
// 自定义比较规则 
static bool cmp(pair<char, int>& a, pair<char, int>& b) {
    // 优先按出现次数降序排序
    if (a.second != b.second)
        return a.second > b.second;
    // 如果出现次数相同，则按 ASCⅡ 码升序排序
    else 
        return a.first < b.first;
}
 
int main() {
    // 读入字符串 s
    string s;
    cin >> s;

    // 定义一个哈希表，存每个字符及其次数
    unordered_map<char, int> hash;
    for (int i = 0; i < s.size(); i ++ ) hash[s[i]] ++ ;
    
    // 关键 ！！！
    // vector<pair<char, int>> nums(hash.begin(), hash.end()); // 和下面等价
    vector<pair<char, int>> nums;
    for (auto [k, v]: hash) {
        nums.push_back({k, v});
    }

    // 排序
    sort(nums.begin(), nums.end(), cmp); 

    // 输出
    for (int i = 0; i < nums.size(); i ++ ) { 
        cout << nums[i].first; 
    }

    cout << endl;
    
    return 0;
}


// 二刷：使用 lambda 表达式（推荐）
#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> PCI;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> hash;
    for (int i = 0; i < s.size(); i ++ ) hash[s[i]] ++ ;

    vector<PCI> nums;
    for (auto [k, v]: hash) nums.push_back({k, v});

    auto cmp = [&](PCI a, PCI b) {
        if (a.second != b.second) 
            return a.second > b.second;
        return a.first < b.first;
    };

    sort(nums.begin(), nums.end(), cmp);

    for (auto [k, v]: nums) cout << k;

    cout << endl;

    return 0;
}


