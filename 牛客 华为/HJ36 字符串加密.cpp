
// 密钥：TRAILBLAZERS -> TRAILBZES
// 明文：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// 密文：T R A I L B Z E S C D F G H J K M N O P Q U V W X Y 
// 小写字母同上

// 示例 1
// 密钥：nihao
// 要加密的：ni

// 明文：a b c d e f g h i j k l m n o p q r s t u v w x y z
// 密文：n i h a o b c d e f g j k l m p q r s t u v w x y z 

// 输出：le

// 模拟

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    // 读入密钥 key 和要加密的单词 word
    string key, word;
    cin >> key >> word;

    vector<char> mi; // 密文数组

    // flag 数组用于：标记某个字母是否在 密钥 中出现，false 表示没出现过
    vector<bool> flag(26, false); // A -> 0, B -> 1, ... , Z -> 25

    // 遍历字符串 key，先将 key 中的字母按顺序放到 密文数组 mi 的开头
    for (int i = 0; i < key.size(); i ++ ) { 
        key[i] = toupper(key[i]); // 先将当前字母转成大写
        // 将当前字母标记为在 密钥 中出现，加入 密文数组
        if (flag[key[i] - 'A'] == false) {
            flag[key[i] - 'A'] = true;
            mi.push_back(key[i]); // 加入密钥
        }
    }

    // 从 A 遍历到 Z，维护 密文数组 的剩余部分
    for (char c = 'A'; c <= 'Z'; c ++ ) {
        // 如果某个字母没有在密钥中出现过，则加入 密文数组
        if (flag[c - 'A'] == false) {
            mi.push_back(c);
        }
    }

    string res; // 要输出的密文

    // 遍历输入的要加密的字符串 word 
    for (int i = 0; i < word.size(); i ++ ) {
        // 如果是小写字母，则需要在转换大写密文的基础上加 32
        if ('a' <= word[i] <= 'z') 
            res += mi[word[i] - 'a'] + 32;
        // 如果是大写字母，则直接转换为大写密文
        else 
            res += mi[word[i] - 'A'];
    }

    cout << res << endl;
    
    return 0;
}



// 二刷

