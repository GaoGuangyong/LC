

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

    int cnt = 0; // 非法票数

    // 读入总票数 k
    int k;
    cin >> k;
    for (int i = 0; i < k; i ++ ) { 
        // 读入 k 个投票结果
        string s;
        cin >> s;
        // 只对 哈希表 中有的 候选人 票数 + 1
        if (hash.count(s)) hash[s]++;
        else cnt ++ ;
    }

    // 遍历候选人的名字，输出其票数
    for (int i = 0; i < name.size(); i ++ ) { 
        cout << name[i] << " : " << hash[name[i]] << endl;
    }

    cout << "Invalid : " << cnt << endl; // 总票数减去合法票数就是非法票数
    
}




