
// 题意：
// 编写程序将数字转换成英文

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ones{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
vector<string> tens{ "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
vector<string> twenties{ "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

vector<int> ihundreds{ (int)100, (int)1000, (int)1000000, (int)1000000000};
vector<string> hundreds{ "hundred", "thousand", "million", "billion" };

// 辅助函数：将 long long 型整数转换为 英文
string itoe(long long n) {
    //【1】处理 100 以内的数
    // 0 ~ 9，直接输出
    if (0 <= n && n <= 9) return ones[n];
    // 10 ~ 19，直接输出
    if (10 <= n && n < 20) return tens[n % 10];
    // 20 - 99
    if (20 <= n && n < 100) {
        // 如果个位数 n % 10 不为 0，则输出为 "几十几"
        if (n % 10 != 0) return twenties[n / 10] + " " + ones[n % 10];
        // 如果个位为 0，则输出为 "几十"
        else return twenties[n / 10];
    }
    //【2】处理 >= 100 的数，每三位数后记得带上计数单位 分别是 thousand, million, billion
    for (int i = 0; i < 4; i ++ ) { 
        if (n < ihundreds[i + 1]) { // 确定范围
            // 如果 n 不能整除 ihundreds[i]，即 n 不是 整百、整千、整百万、整十亿
            if (n % ihundreds[i] != 0) {
                // 如果 i = 0，则是三位数，hundred 后要加 and
                if (i == 0) return itoe(n / ihundreds[i]) + " " + hundreds[i] + " and " + itoe(n % ihundreds[i]);               
                // 如果 i = 1, 2, 3，则不是三位数，thousand、million、billion 后不加 and
                else return itoe(n / ihundreds[i]) + " " + hundreds[i] + " " + itoe(n % ihundreds[i]);
            } 
            // 否则，如果 n 能整除 ihundreds[i]，则 n 是整百、整千、整百万、整十亿
            else {
                return itoe(n / ihundreds[i]) + " " + hundreds[i];
            }
        }
    }
    return "";
}

int main() {
    // 读入一个 long long 型整数 n
    long long n;
    cin >> n;

    cout << itoe(n) << endl;

    return 0;
}


