

// 括号匹配 —> 想到栈
// 如果从后向前遍历的话比较简单，因为入栈时是 cb, 出栈时正好就是 bc


class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;

        // 从后向前遍历字符串
        for (int i = s.size() - 1; i >= 0; ) {

            //【1】将左括号之前的所有字符入栈
            if (s[i] == ']' || 'a' <= s[i] && s[i] <= 'z') { // 如果是右括号或字符的话，什么都不做，入栈
                stk.push(string(1, s[i])); // 因为栈是 string 类型，所以将字符 's[i]' 转换成字符串 "s[i]" 插入
                i -- ;
            }
            // 如果遇到左括号，
            else if (s[i] == '[') {
                //【2】取出 [] 内的字符串，存到 block
                string block; 
                while (stk.top() != "]") { // 将右括号之前的内容加到 block 中
                    block += stk.top(); // 先将栈顶元素加到 block
                    stk.pop(); // 再将栈顶出栈
                }
                stk.pop(); // 循环结束时，栈顶就是右括号，将右括号出栈
                i -- ; // 因为此时 i 在左括号的位置，左移一位

                //【3】求重复次数 k（重复数字的位数可能大于 1，需要先获取这个数字）
                int k = 0; // 记录重复次数
                int base = 1; // 倍率：在个位就乘 1，在十位就乘 10，以此类推
                // 如果当前的字符是数字
                while (i >= 0 && isdigit(s[i])) { 
                    k += (s[i] - '0') * base; // s[i] - '0' 得到的就是 int型 数字
                    base *= 10;
                    i -- ; // 遍历下一个数字
                } // 循环结束时，k 存的就是重复次数 k，i 指向的就是下一个位置（字母或右括号）

                //【4】根据重复次数 k，把 k 次 block 入栈
                string str; // str 用来存 k 次 block
                while (k -- ) {
                    str += block;
                }
                stk.push(str); // 将 str 入栈
            }
        }
        // 【5】不断将栈顶元素（str）加入结果数组字符串
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};

// 框架
class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;

        for (int i = s.size() - 1; i >= 0; ) {

        }

        string res;
        while (stk.size()) {
            res += stk.top();
            stk.pop();
        }

        return res;
    }
};

// 无注释版本
class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;

        for (int i = s.size() - 1; i >= 0; ) {
            if (s[i] == ']' || isalpha(s[i])) { 
                stk.push(string(1, s[i]));
                i -- ;
            }
            else if (s[i] == '[') {
                string block;
                while (stk.top() != "]") {
                    block += stk.top();
                    stk.pop();
                }
                stk.pop();
                i -- ;

                int k = 0;
                int base = 1;
                while (i >= 0 && isdigit(s[i])) {
                    k += (s[i] - '0') * base;
                    base *= 10;
                    i -- ;
                }

                string str;
                while (k != 0) {
                    str += block;
                    k -- ;
                }
                stk.push(str);
            }
        }

        string res;
        while (stk.size()) {
            res += stk.top();
            stk.pop();
        }

        return res;
    }
};


// 二刷
class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;

        for (int i = s.size() - 1; i >= 0; ) {
            if (s[i] == ']' || isalpha(s[i])) {
                stk.push(string(1, s[i]));
                i -- ;
            }
            else if (s[i] == '[') {
                string block;
                while (stk.top() != "]") {
                    block += stk.top();
                    stk.pop();
                }
                stk.pop();
                i -- ;

                int k = 0;
                int base = 1;
                while (i >= 0 && isdigit(s[i])) {
                    k += (s[i] - '0') * base;
                    base *= 10;
                    i -- ;
                }

                string str;
                while (k -- ) str += block;
                stk.push(str);
            }
        }

        string res;
        while (stk.size()) {
            res += stk.top();
            stk.pop();
        }
        return res;

    }
};


