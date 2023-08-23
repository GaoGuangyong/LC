
// 借助计数排序思想：
// 统计次数最多的前 k 个元素的下界，然后将所有出现次数大于等于该下界的数输出

// 假设 nums 数组有 3 个 1，2 个 2，1 个 3，1 个 4， 共有 n = 7 个数字，k = 2，则出现次数最多的前 2 个数的下界是 2
//【1】定义一个哈希表，统计每个数出现几次： hash[1] = 3, hash[2] = 2, hash[3] = 1, hash[4] = 1
//【2】计数排序
// 先初始化数组 s，统计出现 i 次的数有几个（注意：有 n 个数，则 i 可以取到 n，故数组 s 的大小为 n + 1）

// 下标 i: 0   1   2   3   4   5   6   7  // 代表数字出现的次数
// 数组 s: 0   2   1   1   0   0   0   0  // 代表出现 i 次的数有几个

// 从后往前遍历数组 s，维护一个变量 t，初值为 0，然后 t 不断 += s[i]，当 t == k 时，停止遍历，记录此时的下标 i 
// 将哈希表中 value >= i 的 key 输出到结果数组中（即 将出现的次数 >= i 的数字输出）

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        // 定义并实现哈希表：遍历数组，统计每个数字及其出现的次数
        unordered_map<int, int> hash;
        for (int x : nums) hash[x] ++ ;
        
        // 定义并实现 s 数组：遍历哈希表，统计出现 cnt 次的数字有几个
        vector<int> s(n + 1);
        for (auto [x, cnt]: hash) s[cnt] ++ ;

        // 从后往前遍历数组 s，找 t == k 时的下标 idx
        int t = 0;
        int idx; // 保存 t == k 时的下标
        for (int i = n; i >= 0; i -- ) {
            t += s[i];
            if (t == k) {
                idx = i;
                break; // 此时的下标 i 即为分界点
            }
        }

        vector<int> res; // 定义结果数组

        // 再次遍历哈希表，将出现的次数 >= idx 的数字输出
        for (auto [x, cnt]: hash) {
            if (cnt >= idx) res.push_back(x);
        }

        return res;
    }
};

// 无注释版本
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> hash;
        for (int x: nums) hash[x] ++ ;

        vector<int> s(n + 1);
        for (auto [k, v]: hash) s[v] ++ ;

        int t = 0;
        int idx; 
        for (int i = n; i >= 0; i -- ) {
            t += s[i];
            if (t == k) {
                idx = i;
                break;
            }
        }

        vector<int> res;
        for (auto [k, v]: hash) {
            if (v >= idx) res.push_back(k);
        }

        return res;
    }
};


// 二刷
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int x: nums) hash[x] ++ ;

        int n = nums.size();
        vector<int> s(n + 1);
        for (auto& [num, cnt]: hash) s[cnt] ++ ; // 为了便于理解，通常用 num cnt 替代 k v
        
        int t = 0;
        int idx = 0;
        for (int i = n; i >= 0; i -- ) {
            t += s[i];
            if (t == k) {
                idx = i;
                break;
            }
        }

        vector<int> res;
        for (auto& [num, cnt]: hash) {
            if (cnt >= idx) res.push_back(num);
        }

        return res;
    }
};
