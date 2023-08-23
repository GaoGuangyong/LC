
// 模拟
// 根据题意，要使频率越高的字母 * 越大的数（不区分大小写）

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 辅助函数：计算名字 name 的最大漂亮度
int getMaxValue(string name) {
    // 定义一个数组，记录名字中不同字母出现的次数，alphabet[0] -> a/A，alphabet[1] -> b/B 以此类推
    vector<int> alphabet(26, 0); 
    // 定义一个数组，按照 1 ~ 26 升序记录漂亮度
    vector<int> Price{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26}; 

    int maxVal = 0; // 初始化最大漂亮度
    
    // 遍历名字，记录每个字母出现的次数（不区分大小写）
    for (int i = 0; i < name.size(); i ++ ) {
        // 如果是大写字母
        if (isupper(name[i]) != 0) alphabet[name[i] - 'A'] ++ ;
        // 如果是小写字母
        else if (islower(name[i]) != 0) alphabet[name[i] - 'a'] ++ ;
    }

    // 将 alphabet 数组排序，这样一来 alphabet 和 Price 都是升序的，频率与jia
    sort(alphabet.begin(), alphabet.end());
    
    for (int i = 0; i < 26; i ++ ) {
        maxVal += alphabet[i] * Price[i]; 
    }

    return maxVal; // 返回一个名字的最大可能价钱（即漂亮度）
}

// 主函数
int main () {
    // 读入 n 
    int n;
    cin >> n;
    // 读入所有的名字，输出每个名字的最大可能漂亮度
    string str;
    while (cin >> str) {
        cout << getMaxValue(str) << endl;
    }
    
    return 0;
}

