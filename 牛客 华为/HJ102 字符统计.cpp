

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


