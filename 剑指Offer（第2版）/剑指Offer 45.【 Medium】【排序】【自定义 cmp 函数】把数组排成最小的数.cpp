
// 自定义比较规则


// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个 



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


// 写法二：在主函数里写成 lambda 表达式，cmp 写在 sort 外面

class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 自定义比较函数 a < b 当且仅当 ab < ba
        // eg: "123" < "132" 当且仅当 "123132" < "132123"
        auto cmp = [&](int a, int b) {
            string as = to_string(a);
            string bs = to_string(b);
            return as + bs < bs + as;
        };

        sort(nums.begin(), nums.end(), cmp);

        string res;
        for (int x: nums) res += to_string(x);

        return res;
    }
};


// 写法三：在主函数里写成 lambda 表达式，cmp 写在 sort 里面
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 自定义比较函数 a < b 当且仅当 ab < ba
        // eg: "123" < "132" 当且仅当 "123132" < "132123"
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            string as = to_string(a);
            string bs = to_string(b);
            return as + bs < bs + as;
        });

        string res;
        for (int x: nums) res += to_string(x);

        return res;
    }
};