

// 套用整数高精度加法的模板，把其中的进位规则变成逢 2 进位
// 注意：高精度加法的模板是从数组的第 0 位开始，而题目的字符数组的第 0 位置是高位，所以反转过来，把第 0 位变成个位，这样就可以套用模板仍然从第 0 位开始加

// 写法一
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string c; // 最终结果
        int t = 0; // 进位

        // 从个位开始遍历，当 a 没遍历完 || b 没遍历完 时
        for (int i = 0; i < a.size() || i < b.size(); i ++ ) { 
            if (i < a.size()) { // i < a.size()，说明 a 的 i 这位是有数的，就把这个数（a[i] - '0'）加上
                t += a[i] - '0'; // a[i] - '0' 将 char 类型的数字转换成 int 型
            }
            if (i < b.size()) { // i < b.size()，说明 b 的 i 这位是有数的，就把这个数（b[i] - '0'）加上
                t += b[i] - '0';
            }
            // 此时 t = a[i] + b[i] + t，也就是当前这一位的2个数相加再加上进位
            c += to_string(t % 2); // 当前位的计算结果：t % 2
            t /= 2; // 进位的计算结果：t / 2
        }
        // 如果循环结束后，还有进位的话，就说明最高位是1，需要给C的高位补上1
        if (t != 0) c += to_string(1);

        reverse(c.begin(), c.end());
        return c;
    }
};

// 写法二（推荐）高精度加法的模板写法
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string c; // 最终结果
        int t = 0; // 进位

        // 从个位开始遍历，当 a 没遍历完 || b 没遍历完 || 有进位 时
        for (int i = 0; i < a.size() || i < b.size() || t != 0; i ++ ) {
            // i < a.size()，说明 a 的 i 这位是有数的，就把这个数（a[i] - '0'）加上
            if (i < a.size()) t += a[i] - '0'; // 将 char 类型的数字转换成 int 型
            // i < b.size()，说明 b 的 i 这位是有数的，就把这个数（b[i] - '0'）加上    
            if (i < b.size()) t += b[i] - '0'; // 将 char 类型的数字转换成 int 型
            
            // 此时 t = a[i] + b[i] + t，也就是当前这一位的2个数相加再加上进位

            c += to_string(t % 2); // 当前位的计算结果：t % 2
            t /= 2; // 进位的计算结果：t / 2
        }

        reverse(c.begin(), c.end());
        
        return c;
    }
};


// 无注释版
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c;

        int t = 0;

        for (int i = 0; i < a.size() || i < b.size() || t != 0; i ++ ) {
            if (i < a.size()) t += a[i] - '0';
            if (i < b.size()) t += b[i] - '0';
            c += to_string(t % 2);
            t /= 2;
        }

        reverse(c.begin(), c.end());
        return c;
    }
};


