

// 哈希表 + 分情况讨论

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// 用哈希表记录每个字符相应的大小，其中 10 用字符 1 表示
unordered_map<char, int> num{{'3', 1}, {'4', 2}, {'5', 3}, {'6', 4}, {'7', 5}, {'8', 6}, {'9', 7}, {'1', 8},
    {'J', 9}, {'Q', 10}, {'K', 11}, {'A', 12}, {'2', 13}};

int main() {
    string s;
    getline(cin, s);
    string s1_origin = s.substr(0, s.find('-')); //从-处截取成两段
    string s2_origin = s.substr(s.find('-') + 1);

    string s1 = "";
    string s2 = "";

    for (int i = 0; i < s1_origin.size(); i ++ ) // 将原字符串中的 10 变成 1
        if (s1_origin[i] != '0') // 如果遇到 0 则跳过
            s1 += s1_origin[i];
    for (int i = 0; i < s2_origin.size(); i ++ ) // 将原字符串中的 10 变成 1
        if (s2_origin[i] != '0') // 如果遇到 0 则跳过
            s2 += s2_origin[i];

    // 如果有王炸直接输出王炸
    if (s1 == "joker JOKER" || s2 == "joker JOKER") 
        cout << "joker JOKER";

    // 字符串其中一个为 7，说明是炸弹，输出炸弹
    else if (s1.size() == 7) 
        cout << s1_origin << endl;
    else if (s2.size() == 7)
        cout << s2_origin << endl;

    // s1 和 s2 的类型相同（个子、对子、三个、顺子、炸弹），则都是比较第一个大小
    else if (s1.size() == s2.size()) { 
        if (num[s1[0]] > num[s2[0]]) 
            cout << s1_origin << endl;
        else
            cout << s2_origin << endl;
    }

    // 如果有一个是个子，另一个是大小王
    else if (s1.size() == 1 && (s2 == "joker" || s2 == "JOKER"))
        cout << s2_origin << endl;
    else if (s2.size() == 1 && (s1 == "joker" || s1 == "JOKER"))
        cout << s1_origin << endl;
    
    // 其他情况
    else
        cout << "ERROR" << endl;

    return 0;
}




