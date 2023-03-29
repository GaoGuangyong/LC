
// 自定义比较规则

// 写法一：在主函数外写成 static bool 函数
class Solution {
public:
    // 自定义比较函数 a < b 当且仅当 ab < ba
    // 即 a 在前 b 在后比 b 在前 a 在后小，则认为 a 比 b 小； eg: "123" < "132" 当且仅当 "123132" < "132123"
    static bool cmp(int a, int b) {
        string as = to_string(a);
        string bs = to_string(b);
        return as + bs < bs + as;
    }

    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp); // 按照 cmp 函数的规则进行排序

        string res;
        for (int x: nums) {
            res += to_string(x);
        }

        return res;
    }
};


// 写法二：在主函数里写成 lambda 表达式
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 自定义比较函数 a < b 当且仅当 ab < ba
        // 即 a 在前 b 在后比 b 在前 a 在后小，则认为 a 比 b 小； eg: "123" < "132" 当且仅当 "123132" < "132123"
        auto cmp = [&](int a, int b) {
            string as = to_string(a);
            string bs = to_string(b);
            return as + bs < bs + as;
        };

        sort(nums.begin(), nums.end(), cmp);

        string res;
        for (auto x : nums) res += to_string(x);

        return res;
    }
};


