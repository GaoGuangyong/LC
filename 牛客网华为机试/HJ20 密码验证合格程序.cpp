#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) { // 等价于 while (cin >> s)
        int n = s.size();
        // 特判条件 1：若读入字符串的长度 <= 8 则输出 NG，继续判断下一个
        if (n <= 8) {
            cout << "NG" << endl;
            continue;
        }

        // 判断条件 2
        // 枚举读入的字符串
        int flag[4] = {0};
        for (int i = 0; i < n; i ++ ) {
            // 大写字母    
            if (s[i] >= 'A' && s[i] <= 'Z') flag[0] = 1;
            // 小写字母
            else if (s[i] >= 'a' && s[i] <= 'z') flag[1] = 1;
            // 数字
            else if (s[i] >= '0' && s[i] <= '9') flag[2] = 1;
            // 其他符号
            else flag[3] = 1;
        }
        // 若字符类型少于三种，则输出 NG，继续判断下一个
        if (flag[0] + flag[1] + flag[2] + flag[3] < 3) { 
            cout << "NG" << endl;
            continue;
        }

        // 判断条件 3
        bool repeat = false; // 记录重复子串
        // 枚举字符串，检查是否有长度为 3 的相同的字串
        for (int i = 0; i <= n - 6; i ++ ) {
            for (int j = i + 3; j < n; j ++ ) {
                if (s.substr(i, 3) == s.substr(j, 3)) {
                    repeat = true;
                    break;
                }
            }
        }
        if (repeat == true) cout << "NG" << endl;
        else cout << "OK" << endl;
    }

    return 0;
}



// 无注释，写法二
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();

        if (n <= 8) {
            cout << "NG" << endl;
            continue;
        }

        vector<int> flag(4);

        for (int i = 0; i < n; i ++ ) {
            if (s[i] >= 'A' && s[i] <= 'Z') flag[0] = 1;
            else if (s[i] >= 'a' && s[i] <= 'z') flag[1] = 1;
            else if (s[i] >= '0' && s[i] <= '9') flag[2] = 1;
            else flag[3] = 1;
        }

        if (accumulate(flag.begin(), flag.end(), 0) < 3) {
            cout << "NG" << endl;
            continue;
        } 

        bool repeat = false;
        for (int i = 0; i <= n - 6; i ++ ) {
            for (int j = i + 3; j < n; j ++ ) {
                if (s.substr(i, 3) == s.substr(j, 3)) {
                    repeat = true;
                    break;
                }
            }
        }
        if (repeat == true) cout << "NG" << endl;
        else cout << "OK" << endl;
    }
    return 0;
}

