

// 递归

// 技巧：
// A && B; // 若 A 为 false，则 B 不会执行；只有 A 为 true，B 才会执行
// A || B; // 若 A 为 true，则 B 不会执行；只有 A 为 false，B 才会执行

// 使用该特性可以去掉 if 语句

// (n > 0) && (res += x); // <=> if (n > 0) res += x;

class Solution {
public:
    int sumNums(int n) {
        // 从 n 开始向 1 累加，
        int res = n; 

        // 只有 n > 0 成立时，才会执行后面的语句
        (n > 0) && (res += sumNums(n - 1)); 
        
        return res;
    }
};


