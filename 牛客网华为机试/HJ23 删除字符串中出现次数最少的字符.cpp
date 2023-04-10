

// 写法一：哈希表
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;
 
int main() {
    string s;
    while (cin >> s) {
        // 定义一个哈希表，存每个字母出现的次数
        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); i ++ ) hash[s[i]] ++ ;

        // 遍历哈希表，确定出现次数的最小值 minCnt 是多少
        int minCnt = 21; // 初始时，设最大值
        for (auto [k, v]: hash) {
            minCnt = min(minCnt, v);
        }

        // 遍历字符串，将所有出现次数 > minCnt 的字符输出
        for (int i = 0; i < s.size(); i ++ ) {
            if (hash[s[i]] > minCnt) cout << s[i];
        }
        cout << endl;
    }
    return 0;
}


// 写法二：用数组实现哈希表
int main() {
    string s;
    while(cin >> s){
        vector<int> count(26, 0); // 记录字母出现的次数
        for (int i = 0; i < s.size(); i ++ ) // 遍历字符串
            count[s[i] - 'a'] ++ ; // 统计每个字母出现的次数
        int min = count[s[0] - 'a']; // 以第一个出现的字符为始
        for (int i = 0; i < 26; i ++ )
            if (min > count[i] && count[i] > 0) // 一定要找到最小但不是 0 的次数
                min = count[i];
        for (int i = 0; i < s.size(); i ++ ) // 输出所有出现次数大于 min 的字符
            if (count[s[i] - 'a'] > min)
                cout << s[i];
        cout << endl;
    }
    return 0;
}

