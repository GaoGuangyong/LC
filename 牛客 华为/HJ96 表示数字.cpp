

// 题意：
// 将一个字符串中所有的整数前后加上符号 *，其他字符保持不变。连续的数字视为一个整数


// 输入：
// Jkdi234klowe90a3

// 输出：
// Jkdi*234*klowe*90*a*3*



// 双指针
// 考察字符串的 insert 函数 

#include <iostream>
#include <string>
using namespace std;
 
int main() {
    // 读入字符串
    string s;
    cin >> s;

    // 枚举字符串
    for (int i = 0; i < s.size(); i ++ ) {
        // 当遇到的数字时，在该数字前插入 *（用 insert 函数实现）
        if (isdigit(s[i])) { 
            s.insert(i, "*");
            // 从 i + 1 开始搜索数字结束的位置
            int j = i + 1;
            while (isdigit(s[j])) j ++ ;
            // 此时 j 指向的是数字的下一个位置，在其前面插入 *
            s.insert(j, "*"); 

            i = j; // 因为每次 i ++ ，故只需令 i 指向 j
        }
    }

    cout << s << endl;
    
    return 0;
}


