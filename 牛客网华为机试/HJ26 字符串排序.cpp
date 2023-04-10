

// 北大考研机试题

#include<iostream>
#include<string>
using namespace std;
 
// 为了实现规则 1，将字母转化成数字
// a/A -> 0, b/B -> 1, ... , z/Z -> 25
int toint(char c) { 
    if (c >= 'a' && c <= 'z') return c - 'a';
    else return c - 'A';
}

// 为了实现规则 2，采用稳定的排序算法（冒泡）

int main() {
    string s;
    cin >> s;

    int next;
    for (int i = s.size() - 1; i > 0; i -- ) {
        for (int j = 0; j < i; j ++ ) {
            // 根据规则 3：只有字母才需要重排位置，非字母保持原来位置不变
            if (isalpha(s[j])) { 
                // 从 j + 1 开始找下一个字母    
                next = j + 1;
                while (next <= i && !isalpha(s[next])) next ++ ; 
                // 如果 s[next] 是字母，且 当前字母 > s[next]，则交换二者
                if (isalpha(s[next]) && toint(s[j]) > toint(s[next])) {
                    swap(s[j], s[next]); 
                }
            }
        }
    }
    cout << s <<endl;
    return 0;
}

