

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s); // 读入一行字符串 s

    vector<string> move; // 创建一个字符串数组 move，用于存储解析后的移动指令
    
    // 遍历输入字符串，将每个移动指令提取并存储在 move 数组中
    for (int i = 0; i < s.size(); i ++ ) {
        string temp;
        // 当读入字符不为 ';' 时压入临时字符串 temp
        while (s[i] != ';') {
            temp.push_back(s[i]);
            i ++ ;
        }
        // 读到 ';' 时，再把临时字符串压入字符串数组 move
        move.push_back(temp);
    }

    int x = 0, y = 0; // 起点位置 (0, 0)

    // 枚举 move 字符串数组，解析每个移动指令并更新坐标
    for (int i = 0; i < move.size(); i ++ ) {
        if (move[i].size() == 3 || move[i].size() == 2) { // 判断每个指令是否有效（长度为 2 或 3）
            if (move[i][0] == 'A' || move[i][0] == 'D' || move[i][0] == 'W' || move[i][0] == 'S') { // 判断第一个字符是不是方向指令
                int num1 = move[i][1] - '0'; // 将第二个字符转换为数字
                
                // 如果指令的长度为 2，且 num1 为 0 ~ 9
                if (move[i].size() == 2 && num1 >= 0 && num1 <= 9) { 
                    if (move[i][0] == 'A') x = x - num1; // 左移 x
                    if (move[i][0] == 'D') x = x + num1; // 右移 x
                    if (move[i][0] == 'W') y = y + num1; // 上移 y
                    if (move[i][0] == 'S') y = y - num1; // 下移 y
                }

                // 如果指令的长度为 3，且 num1 和 num2 都为 0 ~ 9
                int num2 = move[i][2] - '0';
                if (move[i].size() == 3 && num1 >= 0 && num1 <= 9 && num2 >= 0 && num2 <= 9) { // 处理长度为 3 的指令
                    int num = num1 * 10 + num2; // 将两位数字合并成一个整数
                    if (move[i][0] == 'A') x = x - num; // 左移 x
                    if (move[i][0] == 'D') x = x + num; // 右移 x
                    if (move[i][0] == 'W') y = y + num; // 上移 y
                    if (move[i][0] == 'S') y = y - num; // 下移 y
                }
            }
        }
    }

    cout << x << "," << y << endl;
    return 0;
}


