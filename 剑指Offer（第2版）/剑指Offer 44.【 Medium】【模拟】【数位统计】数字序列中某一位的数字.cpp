// 数位统计问题

// 题目的数字序列是从 0 开始的，而且计算第 n 位数的时候也是从 0 开始的
// 故我们可以认为序列是从 1 开始的，计算第 n 位的时候也是从 1 开始的
// 这样的话 一位数有 9 个，两位数有 90 个，三位数有 900 个...

// 要确定该序列的第 n 个数字是多少？分成三步处理
// 假设 n = 1001
// 1、确定第 n 个数字是属于几位数的？设为 x
//     n - 9*1 - 90*2 = 812 < 900*3，所以是 3 位数
// 2、确定第 n 个数字属于所有的 X 位数中的第几个 X 位数？这个数是多少？设为 number
//     ⌈812/3⌉ = 271，所以是第 271 个 3 位数，number = 100 + 271 - 1 = 370
// 3、确定第 n 个数字属于 number 的第几位？设为 k
//     1001 % 3 = 2，所以是 370 这个数的第 2 位，即 7

class Solution {
public:
    int findNthDigit(int n) {
        long long x = 1; // x 表示 x 位数，从一位数开始
        int num = 9; // num 表示 x 位数共有多少个，一位数有 9 个
        int base = 1; // base 表示第 1 个 x 位数是多少，第 1 个一位数是多少

        // 第 n 个数字属于几位数（x）？
        // 第 1 个 x 位数是多少？（base）
        while (n > num * x) { // 当剩余的 n 大于 x 位数的总长度
            n -= num * x; // 减去 x 位数的总长度
            x ++ ; // 接下来判断 x + 1 位数
            num *= 10; // x + 1 位数一共有多少个
            base *= 10; // 第一个 x + 1 位数是多少
        }

        // 第 n 位对应哪个数（number）
        int number = base + ((n + x - 1) / x) - 1; //  n / x 上取整 等价于 (n + x - 1) / x 下取整

        // 第 n 位是 x 位数 number 的第几位（k）
        int k;
        // n 模 x 余 0，则说明是 number 的第 x 位
        if (n % x == 0) k = x; 
        // n 模 x 不余 0，则说明是 number 的第 余数 位
        else k = n % x; 

        // 输出最终结果：number 的第 k 位，例如要输出 12561 的第 2 位，则先删掉后面的 561，得到 12，再取个位，得到 2
        // 先删掉后面的 x - k 位：循环 x - k 次，每次 除 10
        for (int j = 0; j < x - k; j ++ ) {
            number /= 10; // 方法：每次除 10
        }
        
        // 再取个位
        return number % 10;
    }
};



// 无注释版本
class Solution {
public:
    int findNthDigit(int n) {
        long long x = 1;
        int num = 9;
        int base = 1;

        while (n > num * x) {
            n -= num * x;
            x ++ ;
            num *= 10;
            base *= 10;
        }

        int number = base + ((n + x - 1) / x) - 1;

        int k;
        if (n % x == 0) k = x; 
        else k = n % x; 

        for (int j = 0; j < x - k; j ++ ) {
            number /= 10;
        }

        return number % 10;
    }
};


