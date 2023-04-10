


// C++ 的 STL 中的有序集合 set，将所有数字添加到集合中
// set 会对添加的数字完成去重并从小到大排序

#include <iostream>
#include <set>
using namespace std;

int main() {
    // 读入个数 n
    int n;
    cin >> n;

    set<int> S; // 定义有序集合，存所有的数
    
    // 读入 n 个数，并加入有序集合
    for (int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;
        S.insert(x);
    }

    // 遍历有序集合，顺序输出集合中的元素
    for (int x: S) { 
        cout << x << endl;
    }
    
    return 0;
}

