

// 库函数 substr()

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int k;
    cin >> k;

    cout << str.substr(0, k) << endl;

    return 0;
}
