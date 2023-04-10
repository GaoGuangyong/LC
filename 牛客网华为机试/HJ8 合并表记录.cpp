

#include <iostream>
#include <map>
using namespace std;

int main() {
    // 读入键值对个数 n
    int n;
    cin >> n;

    // 定义一个有序哈希表，存索引及其数值的和
    map<int, int> hash;

    // 读入 n 对键值对
    for (int i = 0; i < n; i ++ ) {
        pair<int, int> x;

        int index = x.first;
        int value = x.second;
        
        cin >> index >> value;
        hash[index] += value;
    }

    // 遍历哈希表，输出结果
    for (auto [k, v]: hash) {
        cout << k << " " << v << endl;
    }

    return 0;
}

