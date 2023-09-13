

// 题意：
// 请实现一个计票统计系统。你会收到很多投票，其中有合法的也有不合法的，请统计每个候选人得票的数量以及不合法的票数

// 第一行输入候选人的人数n，第二行输入n个候选人的名字（均为大写字母的字符串），第三行输入投票人的人数，第四行输入投票
// 按照输入的顺序，每行输出候选人的名字和得票数量（以" : "隔开，注：英文冒号左右两边都有一个空格！），最后一行输出不合法的票数，格式为"Invalid : "+不合法的票数

// 输入：
// 4
// A B C D
// 8
// A D E CF A GG A B

// 输出：
// A : 3
// B : 1
// C : 0
// D : 1
// Invalid : 3

// 说明：
// E CF GG三张票是无效的，所以Invalid的数量是3


// 哈希表

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
 
int main() {
    // 读入候选人数 n
    int n;
    cin >> n;

    unordered_map<string, int> hash; // 候选人及其票数
    vector<string> name(n); // 候选人名字
    
    // 遍历 n 个候选人
    for (int i = 0; i < n; i ++ ) { 
        // 读入候选人名称
        string s;
        cin >> s;
        hash[s] = 0; // 在 哈希表 中记录候选人，初始票数为 0
        name[i] = s; // 记录候选人的名字
    }

    int cnt = 0; // 记录非法票数

    // 读入总票数 k
    int k;
    cin >> k;

    // 读入 k 个投票结果
    for (int i = 0; i < k; i ++ ) {
        string s;
        cin >> s;
        // 只对 哈希表中存在的候选人 票数 + 1，否则对非法票数 ++ 
        if (hash.count(s)) hash[s] ++ ;
        else cnt ++ ;
    }

    // 遍历候选人的名字，输出其票数
    for (int i = 0; i < name.size(); i ++ ) { 
        cout << name[i] << " : " << hash[name[i]] << endl;
    }

    cout << "Invalid : " << cnt << endl; // 总票数减去合法票数就是非法票数
}




