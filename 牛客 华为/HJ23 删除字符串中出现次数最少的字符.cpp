

// 写法一：哈希表
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> hash;

    for (int i = 0; i < s.size(); i ++ ) hash[s[i]] ++ ;

    int minCnt = INT_MAX;

    for (auto [k, v]: hash) minCnt = min(minCnt, v);

    for (char c: s) {
        if (hash[c] > minCnt) cout << c;
    }

    cout << endl;

    return 0;
}



// 写法二：用数组实现哈希表
int main() {
    string s;
    while(cin >> s){
        vector<int> cnt(26, 0); // 记录字母出现的次数
        for (int i = 0; i < s.size(); i ++ ) { // 遍历字符串，统计每个字母出现的次数
            cnt[s[i] - 'a'] ++ ;
        }

        int min = cnt[s[0] - 'a']; // 以第一个出现的字符为始

        for (int i = 0; i < 26; i ++ ) {
            if (min > cnt[i] && cnt[i] > 0) { // 一定要找到最小但不是 0 的次数
                min = cnt[i];
            }
        }

        for (int i = 0; i < s.size(); i ++ ) { // 输出所有出现次数大于 min 的字符
            if (cnt[s[i] - 'a'] > min) {
                cout << s[i];
            }
        }

        cout << endl;
    }
    return 0;
}

