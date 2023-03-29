
// 位运算

// 指定第二个数 b 不为 0 时循环
// 循环一定会退出
// 因为 carry = (a & b) << 1，所以 carry 的结尾每次会多一个 0
// 又因为 b = carry，所以 b 的结尾每次也会多一个 0，故最多左移 32 次之后，b 就全为 0 了，此时循环结束

class Solution {
public:
    int add(int a, int b){
        // 循环求进位 carry 和无进位和 sum，直至进位为 0
        while (b != 0) {
            // 无进位的和 sum：a ^ b
            int sum = a ^ b; 

            // 进位 carry：a & b << 1, 注意：leetcode 不允许负数左移，所以定义成 unsigned int
            int carry =  (unsigned int) (a & b) << 1;

            // 保证一轮循环结束后，a + b 仍等于 sum + carry;
            a = sum;
            b = carry;
        }

        return a; // 最后进位 b = 0，a 没有必要进位了，答案就是最后的 a
    }
};


// 无注释版本
class Solution {
public:
    int add(int a, int b){
        while (b != 0) {
            int sum = a ^ b; 

            int carry =  (unsigned int) (a & b) << 1;

            a = sum;
            b = carry;
        }

        return a; 
    }
};


