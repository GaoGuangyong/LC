
// 解法一
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 先对数组排序
        return nums[nums.size() / 2]; // 众数一定在中间位置
    }
};

// 解法二 
// 枚举
// 一个数字出现的次数超过数组长度的一半 等价于 这个数字出现的次数 > 其他数组出现次数的和

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val; // val: 出现次数最多的数
        int cnt = 0; // cnt: 出现次数最多的数出现的次数

        // 遍历数组
        for (int x : nums) {
            // 如果 cnt == 0，则表示这个数是第 1 个数，或者在之前的数中，出现最多的数被其他数抵消了，则继续在剩下的数组里找出现最多的数
            if (cnt == 0) {
                val = x; // 将当前数字设为出现次数最多的数
                cnt = 1; // 出现的次数为 1
            }
            // 否则，如果 cnt != 0
            else if (x == val) cnt ++ ; // 如果当前的数是出现最多的数，计数 + 1
            else if (x != val) cnt -- ; // 如果当前的数不是出现最多的数，计数 - 1
        }

        return val;
    }
};

// 无注释版本
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val; 
        int cnt = 0;

        for (int x: nums) {
            if (cnt == 0) {
                val = x;
                cnt = 1;
            }
            else if (x == val) cnt ++ ;
            else if (x != val) cnt -- ;
        }

        return val;
    }
};


// 扩展：LC 229 多数元素 II：要求找出数组种所有出现超过 n/3 次的元素

// 满足这样条件的元素最多只有两个
// 我们每次判断当前元素是否为第 1 个选中的元素或者第 2 个选中的元素
// 每次我们发现当前元素与已经选中的 2 个元素都不相同，则进行抵消 1 次
// 如果存在最终次数大于 0 的元素，还需要再次统计已选中元素的次数是否大于 n/3

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1, val2; // 两个候选元素
        int cnt1 = 0, cnt2 = 0; // 两个候选元素出现的次数

        // 枚举所有的数
        for (int x: nums) {
            if (cnt1 > 0 && x == val1) // 如果该元素出现次数 > 0，且为第 1 个候选元素 val1
                cnt1 ++ ;
            else if (cnt2 > 0 && x == val2) // 如果该元素出现次数 > 0，且为第 2 个候选元素 val2
                cnt2 ++ ;
                
            else if (cnt1 == 0) { // 选择作为第一个元素
                val1 = x;
                cnt1 = 1;
            }
            else if (cnt2 == 0) { // 选择作为第二个元素
                val2 = x;
                cnt2 = 1;
            }
            else (x != val1 && x != val2) { // 如果 x 与 两个候选元素均不相同，则个抵消 1 次
                cnt1 -- ;
                cnt2 -- ;
            }
        }
        // 接下来统计两个候选元素的出现次数
        cnt1 = 0;
        cnt2 = 0;
        for (int x: nums) {
            if (x == val1) cnt1 ++ ;
            else if (x == val2) cnt2 ++ ;
        }

        vector<int> res;
        // 检测元素出现的次数是否满足要求（出现次数 > n/3）
        if (cnt1 > nums.size() / 3) res.push_back(val1);
        if (cnt2 > nums.size() / 3) res.push_back(val2);
        return res;
    }
};

// 无注释版本
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1; 
        int val2;
        int cnt1 = 0;
        int cnt2 = 0;

        for (int x: nums) {
            if (cnt1 > 0 && x == val1) {
                cnt1 ++ ;
            }

            else if (cnt2 > 0 && x == val2) {
                cnt2 ++ ;
            }

            else if (cnt1 == 0) {
                val1 = x;
                cnt1 = 1;
            }

            else if (cnt2 == 0) {
                val2 = x;
                cnt2 = 1;
            }

            else if (x != val1 && x != val2) {
                cnt1 -- ;
                cnt2 -- ;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int x: nums) {
            if (x == val1) cnt1 ++ ;
            else if (x == val2) cnt2 ++ ;
        }

        vector<int> res;
        int n = nums.size();
        if (cnt1 > n / 3) res.push_back(val1);
        if (cnt2 > n / 3) res.push_back(val2);

        return res;
    }
};
