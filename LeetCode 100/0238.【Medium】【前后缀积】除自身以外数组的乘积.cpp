

// https://www.acwing.com/solution/content/72762/
//            i = 0   1   2   3
// 原数组 nums     1   2   3   4
// 前缀积 prefix   1   2   6   24
// 后缀积 suffix   24  24  12  4 
// 答案   res      24  12  8   6

// i = 0 时，    res[i] = suffix[i + 1]
// i > 0 时，    res[i] = prefix[i - 1] * suffix[i + 1]      
// i = n - 1 时，res[i] = prefix[i - 1]

// 对于题目的进一步空间要求，可以开一个 prefix 数组，然后利用 nums数组从后往前维护一个变量 s，保存 suffix 数组的每一个数的值


// 解法一：开前缀，后缀两个数组（好理解）
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // 定义前缀积数组 preffix 和后缀积数组 suffix
        vector<int> prefix(n); // preffix[i] 表示 nums[0 ~ i] 的乘积
        vector<int> suffix(n); // suffix[i] 表示 nums[i ~ n - 1] 的乘积
        
        // 初始化
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        
        // 实现前缀积和后缀积数组
        for (int i = 1; i < n; i ++ ) {
            prefix[i] = prefix[i - 1] * nums[i];
        }
        for (int i = n - 2; i >= 1; i -- ) {
            suffix[i] = nums[i] * suffix[i + 1];
        }

        vector<int> res(n);
        for (int i = 0; i < n; i ++ ) {
            if (i == 0) res[i] = suffix[i + 1];
            else if (i == n - 1) res[i] = prefix[i - 1];
            else res[i] = prefix[i - 1] * suffix[i + 1];
        }
            
        return res;
    }
};

// 无注释版本
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i ++ )
            prefix[i] = prefix[i - 1] * nums[i];
        for (int i = n - 2; i >= 0; i -- )
            suffix[i] = suffix[i + 1] * nums[i];

        vector<int> res(n);
        for (int i = 0; i < n; i ++) {
            if (i == 0) res[i] = suffix[i + 1];
            else if (i == n - 1) res[i] = prefix[i - 1];
            else res[i] = prefix[i - 1] * suffix[i + 1];
        }
            
        return res;
    }
};

// 二刷
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n + 1);
        vector<int> suffix(n + 1);

        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i ++ ) prefix[i] = prefix[i - 1] * nums[i];
        for (int i = n - 2; i >= 1; i -- ) suffix[i] = nums[i] * suffix[i + 1];

        vector<int> res(n);

        for (int i = 0; i < n; i ++ ) {
            if (i == 0) res[i] = suffix[1];
            else if (i == n - 1) res[i] = prefix[n - 2];
            else res[i] = prefix[i - 1] * suffix[i + 1];
        }
        
        return res;
    }
};



// 解法二：只开前缀积数组
// s[i] 表示下标 i 左侧所有元素的乘积
// r 表示下标 i 右侧所有元素的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // 预处理前缀积数组
        vector<int> s(n);

        s[0] = 1; // 刚开始左边没有元素，所以 s[0] = 1
        
        for (int i = 1; i < n; i ++ ) {
            s[i] = s[i - 1] * nums[i - 1];
        }
        
        int r = 1; // 刚开始右边没有元素，所以 r = 1

        // 从后往前枚举，将当前元素右边的乘积乘到 s[i] 上，则 s[i] 就是答案
        for (int i = n - 1; i >= 0; i -- ) {
            s[i] = s[i] * r;
            r *= nums[i]; // 将当前元素乘到 r 上
        }
        return s;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> s(n);
        s[0] = 1;
        for (int i = 1; i < n; i ++ ) {
            s[i] = s[i - 1] * nums[i - 1];
        }

        int r = 1;
        for (int i = n - 1; i >= 0; i -- ) {
            s[i] *= r;
            r *= nums[i];
        }

        return s;
    }
};

