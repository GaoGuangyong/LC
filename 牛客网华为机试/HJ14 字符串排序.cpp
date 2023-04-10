
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 读入字符串个数 n
    int n;
    cin >> n;

    // 定义一个字符串数组，存所有读入的字符串
    vector<string> res;
    
    // 读入 n 个字符串，插入到字符串数组 res 中
    for (int i = 0; i < n; i ++ ) {
        string s;
        cin >> s;
        res.push_back(s);
    }

    // 对数组排序（字典序）
    sort(res.begin(), res.end());

    // 输出
    for (string s: res) {
        cout << s << endl;
    }
    return 0;
}

