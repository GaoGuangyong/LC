
// 题意：输入

// 10.0.3.193 -> 167773121
// 167969729 -> 10.3.3.193

// 输入 a.b.c.d = 10.0.3.193
// a = 10  -> 00001010
// b = 0   -> 00000000
// c = 3   -> 00000011
// d = 193 -> 11000001
// 00001010 << 24 + 00000000 << 16 + 00000011 << 8 + 11000001
// = 00001010 00000000 00000011 11000001
// = (a << 24) + (b << 16) + (c << 8) + d

// 输入 num = 167969729
// num = 00001010 00000011 00000011 11000001
// a = num >> 24 = 00001010 = 10
// num -= (a << 24) = 00000011 00000011 11000001
// b = num >> 16  = 00000011 = 3
// num -= (b << 16) = 00000011 11000001
// c = num >> 8  = 00000011 = 3
// num -= (c << 8) = 11000001 = 193
// d = num

#include <iostream>
using namespace std;

typedef long long LL;

int main() {
    // 为了左移时不溢出，用 long long 存 IP 地址的每一位
    LL a, b, c, d;
    LL num;

    // 使用 scanf 格式化的读入原 IP 地址的每一位
    scanf("%lld.%lld.%lld.%lld", &a, &b, &c, &d);
    // 读入十进制的 IP 地址
    cin >> num;
    
    cout << (a << 24) + (b << 16) + (c << 8) + d << endl;

    a = num >> 24;
    num -= (a << 24);

    b = num >> 16;
    num -= (b << 16);

    c = num >> 8;
    num -= (c << 8);

    d = num;

    cout << a << "." << b << "." << c << "." << d << endl;
    
}


// 二刷
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c, d;
    long long num;

    // scanf("%lld.%lld.%lld.%lld", &a, &b, &c, &d);

    char x;
    cin >> a >> x >> b >> x >> c >> x >> d;
    cin >> num;

    cout << (a << 24) + (b << 16) + (c << 8) + d << endl;

    a = num >> 24;
    num -= (a << 24);

    b = num >> 16;
    num -= (b << 16);

    c = num >> 8;
    num -= (c << 8);

    d = num;

    cout << a << "." << b << "." << c << "." << d << endl;

    return 0;
}
