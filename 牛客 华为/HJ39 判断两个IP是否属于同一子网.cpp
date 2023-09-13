

// 模拟

// 3 行输入，第 1 行是输入子网掩码、第 2，3 行是输入两个 ip 地址，判断两个 IP 是否属于同一子网
// 若两个 IP 地址 与 子网掩码 进行逻辑 “与” 运算后的结果相同，则说明这两台主机在同一子网中

// IP 1        11000000.10101000.00000000.00000001
// 子网掩码     11111111.11111111.11111111.00000000
// AND (&)     11000000.10101000.00000000.00000000

// IP 2　      11000000.10101000.00000000.11111110
// 子网掩码     11111111.11111111.11111111.00000000
// AND (&)     11000000.10101000.00000000.00000000

// 若 IP 地址 或 子网掩码 格式非法 输出 1
// 若 IP1 与 IP2 属于同一子网络 输出 0
// 若 IP1 与 IP2 不属于同一子网络 输出 2


// 写法一：用 cin 读入
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> mask(4, 0); // 掩码
    vector<int> ip1(4, 0);  // IP1
    vector<int> ip2(4, 0);  // IP2

    int res = -1; // 结果

    // ！！！  技巧：读入点分十进制数
    char c;
    cin >> mask[0] >> c >> mask[1] >> c >> mask[2] >> c >> mask[3]; // 读入掩码
    cin >> ip1[0] >> c >> ip1[1] >> c >> ip1[2] >> c >> ip1[3]; // 读入第 1 个 ip 地址
    cin >> ip2[0] >> c >> ip2[1] >> c >> ip2[2] >> c >> ip2[3]; // 读入第 2 个 ip 地址

    // 先判断 IP 地址和 子网掩码的格式是否正确
    for (int i = 0; i < 4; i ++ ) { // 合法的 IP 地址和掩码每一段都要在 0 ~ 255 之间，否则，格式非法
        if (mask[i] < 0 || mask[i] > 255 || ip1[i] < 0 || ip1[i] > 255 || ip2[i] < 0 || ip2[i] > 255) {
            res = 1;
            break;
        }
    }
    for (int i = 0; i < 3; i ++ ) { // 合法的 掩码的左边部分都是 1，右边部分都是 0
        // ！！！ 关键：俩俩一组判断，合法的掩码形如 255.255，255.0，254.0，0.0，即前一位不是 255，则后一位必是 0，否则，格式非法
        if (mask[i] != 255 && mask[i + 1] != 0) { // 如果前一位为 255 但后一位不为 0，则子网掩码非法
            res = 1;
            break;
        }
    }

    if (res == 1) // 如果格式非法，输出 1
        cout << res << endl; 
    else { // 如果格式合法，则继续判断两个 IP 地址是否属于同一个子网掩码
        // 逐个将 两个 IP 地址 和 子网掩码 做 AND 操作
        for (int i = 0; i < 4; i ++ ) {
            // AND 操作结果不同，res = 2
            if ((mask[i] & ip1[i]) != (mask[i] & ip2[i])) {
                res = 2;
                break;
            } 
            // AND 操作结果相同，res = 1
            else res = 0;
        }
        cout << res << endl;
    }
    
    return 0;
}

// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> mask(4, 0);
    vector<int> ip1(4, 0);
    vector<int> ip2(4, 0);

    char c;
    cin >> mask[0] >> c >> mask[1] >> c >> mask[2] >> c >> mask[3]; // 读入掩码
    cin >> ip1[0] >> c >> ip1[1] >> c >> ip1[2] >> c >> ip1[3]; // 读入第 1 个 ip 地址
    cin >> ip2[0] >> c >> ip2[1] >> c >> ip2[2] >> c >> ip2[3]; // 读入第 2 个 ip 地址
    
    int res = -1;
    
    for (int i = 0; i < 4; i ++ ) {
        if (mask[i] < 0 || mask[i] > 255 || ip1[i] < 0 || ip1[i] > 255 || ip2[i] < 0 || ip2[i] > 255) {
            res = 1;
            break;
        }
    }
    for (int i = 0; i < 3; i ++ ) { 
        if (mask[i] != 255 && mask[i + 1] != 0) {
            res = 1;
            break;
        }
    }

    if (res == 1)
        cout << res << endl; 
    else {
        for (int i = 0; i < 4; i ++ ) {
            if ((mask[i] & ip1[i]) != (mask[i] & ip2[i])) {
                res = 2;
                break;
            } 
            else res = 0;
        }
        cout << res << endl;
    }
    
    return 0;
}



// 写法二：用 scanf 读入
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> mask(4, 0);
    vector<int> ip1(4, 0);
    vector<int> ip2(4, 0);
    
    scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]); // 读入掩码

    int res = -1; // 结果
    
    scanf("%d.%d.%d.%d", &ip1[0], &ip1[1], &ip1[2], &ip1[3]); // 读入第 1 个 ip 地址
    scanf("%d.%d.%d.%d", &ip2[0], &ip2[1], &ip2[2], &ip2[3]); // 读入第 2 个 ip 地址

    //【1】先判断 IP 地址和 子网掩码的格式是否正确
    for (int i = 0; i < 4; i ++ ) { // 合法的 IP 地址和掩码每一段都要在 0 - 255 之间
        if (mask[i] < 0 || mask[i] > 255 || ip1[i] < 0 || ip1[i] > 255 || ip2[i] < 0 || ip2[i] > 255) {
            res = 1; // 格式非法
            break;
        }
    }
    for (int i = 0; i < 3; i ++ ) { // 合法的 掩码的左边部分都是 1，右边部分都是 0
        // 俩俩一组判断，合法的掩码形如 255.255，255.0，254.0，0.0，即前一位不是 255，则后一位必是 0
        if (mask[i] != 255 && mask[i + 1] != 0) {
            res = 1; // 格式非法
            break;
        }
    }
    // 如果格式非法，输出 1
    if (res == 1) cout << res << endl;
    
    //【2】如果格式合法，则继续判断两个 IP 地址是否属于同一个子网掩码
    else {
        // 逐个将 两个 IP 地址 和 子网掩码 做 AND 操作
        for (int i = 0; i < 4; i ++ ) {
            // AND 操作结果不同，res = 2
            if ((mask[i] & ip1[i]) != (mask[i] & ip2[i])) {
                res = 2;
                break;
            } 
            // AND 操作结果相同，res = 1
            else res = 0;
        }
        cout << res << endl;
    }
    
    return 0;
}





