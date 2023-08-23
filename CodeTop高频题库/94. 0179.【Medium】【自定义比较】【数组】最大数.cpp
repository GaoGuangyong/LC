

// 类似 剑指 Offer 45
// 自定义比较函数

class Solution {
public:
    // 自定义比较函数 a > b 当且仅当 ab > ba
    // 即 a 在前 b 在后比 b 在前 a 在后大，则认为 a 比 b 大； eg: 132 > 123 当且仅当 132123 > 123132
    static bool cmp(int& a, int& b) {
        string as = to_string(a);
        string bs = to_string(b);
        return as + bs > bs + as;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp); // 按照 cmp 函数的规则进行排序
        string res;
        for (int x : nums) res += to_string(x);

        // 特殊情况：去掉前导 0，例如：nums = [0, 0]，则需输出 0 而不是 00
        int k = 0;
        while (k + 1 < res.size() && res[k] == '0') k ++;
        return res.substr(k);
    }
};


// 写法二：推荐
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 按照 cmp 函数的规则进行排序
        sort(nums.begin(), nums.end(), [&](int a, int b){
            string as = to_string(a);
            string bs = to_string(b);
            return as + bs > bs + as;
        }); 

        string res;
        for (int x : nums) res += to_string(x);

        // 特殊情况：去掉前导 0，例如：nums = [0, 0]，则需输出 0 而不是 00
        int k = 0;
        while (k + 1 < res.size() && res[k] == '0') k ++;
        return res.substr(k);
    }
};


