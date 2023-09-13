
// 模拟


// 密钥：如果包含重复字母，则只保留第 1 个，将这个字符串作为密文的开头，并将字母表中未出现的字母填入这个字符串后面
// 例如：密文为：TRAILBLAZERS 
// 先去除重复的字母，得到字符串 TRAILBZES，将该字符串作为开头并将其中未出现的字母按顺序放在后面，以此作为密钥，得到明文与密钥的对应关系如下：
// 密文：T R A I L B Z E S C D F G H J K M N O P Q U V W X Y 
// 明钥：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// 小写字母同上

// 示例
// 密钥 key 为：nihao，要加密的字符串为：ni，则得到的明文与密钥的对应关系如下：
// 明文：a b c d e f g h i j k l m n o p q r s t u v w x y z
// 密钥：n i h a o b c d e f g j k l m p q r s t u v w x y z 

// 输出加密后的字符串为：le


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 读入密钥 key 和要加密的明文字符串 s
    string key, s;
    cin >> key >> s;

    // ！！！  技巧：用长度为 26 的数组 flag 数组标记某个字母是否在 密钥 中出现，false 表示没出现过
    vector<bool> flag(26, false); // A -> 0, B -> 1, ... , Z -> 25

    vector<char> mi; // 密钥数组
    // 遍历密钥 key，将 key 中的字母按顺序放到 密钥数组 mi 的开头
    for (int i = 0; i < key.size(); i ++ ) { 
        key[i] = toupper(key[i]); // 先将当前字母转成大写（只会转换小写字母）
        // 只有当前字母不在密钥数组中时，将当前字母标加入密钥数组，并标记为在密钥数组中出现
        if (flag[key[i] - 'A'] == false) {
            mi.push_back(key[i]); // 加入密钥数组
            flag[key[i] - 'A'] = true; // 标记为已出现
        }
    }

    // ！！！  技巧：从 A 遍历到 Z，维护密钥数组的剩余部分：如果某个字母没有在密钥中出现过，则加入 密钥数组
    for (char c = 'A'; c <= 'Z'; c ++ ) {
        if (flag[c - 'A'] == false) {
            mi.push_back(c);
        }
    }

    string res; // 要输出的密钥

    // 遍历输入的要加密的明文字符串 s， 
    for (int i = 0; i < s.size(); i ++ ) {
        // 如果是小写字母，则将其在密钥中对应的大写字母转化成小写，再加入 res
        if ('a' <= s[i] <= 'z') 
            res += mi[s[i] - 'a'] + 32; // ！！！  技巧：大写字母的 ASCII 码 +32 即为大写字母
        // 如果是大写字母，则直接转换为大写密钥
        else 
            res += mi[s[i] - 'A'];
    }

    cout << res << endl;
    
    return 0;
}



// 二刷

#include <bits/stdc++.h>
using namespace std;

int main() {
    string key, s;
    cin >> key >> s;

    vector<char> mi;

    vector<char> flag(26, false);
    for (int i = 0; i < key.size(); i ++ ) {
        key[i] = toupper(key[i]);
        if (flag[key[i] - 'A'] == false) {
            mi.push_back(key[i]);
            flag[key[i] - 'A'] = true;
        }
    }

    for (char c = 'A'; c <= 'Z'; c ++ ) {
        if (flag[c - 'A'] == false) {
            mi.push_back(c);
        }
    }

    string res;

    for (char c: s) { // 改用范围 for 循环
        if ('a' <= c <= 'z') res += tolower(mi[c - 'a']); // 改用 tolower 函数
        else res += mi[c - 'A'];
    }

    cout << res << endl;

    return 0;
}
