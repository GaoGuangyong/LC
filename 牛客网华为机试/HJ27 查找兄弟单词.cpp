

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 辅助函数：判断 s1 和 s2 是否是兄弟单词
bool isbrother(string s1, string s2) {
    if (s1.length() == s2.length()) { // 兄弟单词一定要长度相等
        if (s1 == s2) return false; // 不能相同
        // 对两个字符串按字符字典序排序，排序后相同则是兄弟单词
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2) return true;
    }
    // 其他情况都不是兄弟单词
    return false;
}

int main() {
    // 读入 n
    int n;
    cin >> n;
    // 读入 n 个字典单词 到 字符串数组 strs 
    vector<string> strs(n);
    for (int i = 0; i < n; i ++ ) cin >> strs[i];
    // 读入 判断单词 str
    string str;
    cin >> str;
    // 读入 k
    int k;
    cin >> k;

    // 枚举字符串数组 strs，逐个与 str 判断是不是兄弟单词，如果是加入 brothers 数组
    vector<string> brothers;
    for (int i = 0; i < n; i ++ ) {
        if (isbrother(str, strs[i]) == true)
            brothers.push_back(strs[i]);
    }
    // 先输出 brothers 数组中的单词个数
    cout << brothers.size() << endl;
    // 对 brothers 数组排序，如果单词个数 >= k 的话，输出第 k 个单词 brothers[k - 1]
    sort(brothers.begin(), brothers.end());
    if (brothers.size() >= k)
        cout << brothers[k - 1] << endl;
    
    return 0;
}


