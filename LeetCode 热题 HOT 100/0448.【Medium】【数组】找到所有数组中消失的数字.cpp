/* 

我们可以用一个哈希表记录数组 nums 中的数字
由于数字范围均在 [1, n] 中，记录数字后我们再利用哈希表检查 [1, n] 中的每一个数是否出现，从而找到缺失的数字
我们也可以用一个长度为 n 的数组来代替哈希表，这一做法的空间复杂度是 O(n) 的，而我们的目标是优化空间复杂度到 O(1)
注意到 nums 的长度恰好也为 n，能否让 nums 充当哈希表呢？

方法：对 nums 数组进行一定的修改，使其充当哈希表的功能
因为数组下标是 [0, n - 1]，而数字范围是 [1, n]，所以
对于每一个存在的数字 x，让下标 x - 1 的数取负号，表示 x 存在（正数变成负数，负数就不用变了）
比如：数字 4 存在，则 nums[3] 取反
然后再次遍历数组，如果存在某个数字 num[i] 大于 0，那么原来的 nums 数组中就没有 i + 1 这个数

*/


// 解法一：空间复杂度 O(1)
// 数组下标是 [0, n - 1]，而数字范围是 [1, n]，因此
// 遍历数组，对于每一个数字 x，让 nums[x - 1] 取反，表示 x 存在
// 即：将所有的正数变成负数，负数不变
// 再次遍历数组，如果存在某个数字 num[i] 为正数，那么原来的 nums 数组中就没有 i + 1 这个数

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;

        // 遍历数组，对于每一个存在的数字，让其取负数，代表存在
        for (int i = 0; i < nums.size(); i ++ ) {
            int x = abs(nums[i]); // 当前的数字可能已经被标记成了负数，要先获取它的真实值，也就是取绝对值
            if (nums[x - 1] > 0) { // 如果 nums[x - 1] > 0，说明数字 x 没有被标记过
                nums[x - 1] = -nums[x - 1]; // 标记成负数
            }
        }

        // 再次遍历数组，如果 nums[i] 为正数，就说明 i + 1 不存在
        for (int i = 0; i < nums.size(); i ++ ) {
            if (nums[i] > 0) {
                res.push_back(i + 1); // 将其加入结果数组
            }
        }

        return res;
    }
};

// 无注释版本
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;

        for (int i = 0; i < nums.size(); i ++ ) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) nums[x - 1] = -nums[x - 1];
            
        }

        for (int i = 0; i < nums.size(); i ++ ) {
            if (nums[i] > 0) res.push_back(i + 1);
        }

        return res;
    }
};


// 解法二：空间复杂度 O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 定义哈希集合，并将 nums 数组中的元素插入集合
        unordered_set<int> S;
        for (int x: nums) S.insert(x); 

        // 定义结果数组
        vector<int> res;
        
        int n = nums.size(); 
        // 遍历 1 ~ n
        for (int i = 1; i <= n; i ++ ) {
            // 如果元素 i 不在集合 S 中，就把 i 插入结果数组
            if (!S.count(i)) res.push_back(i);
        }
        return res;
    }
};

// 无注释版本
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> S;
        for (int x: nums) S.insert(x);

        vector<int> res;
        
        int n = nums.size();
        for (int i = 1; i <= n; i ++ ) {
            if (!S.count(i)) res.push_back(i);
        }

        return res;
    }
};
