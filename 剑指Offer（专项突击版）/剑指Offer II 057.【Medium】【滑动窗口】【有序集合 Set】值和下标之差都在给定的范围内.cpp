

// 滑动窗口 + 有序集合
// 枚举数组中的每个数 nums[i]，向前找一个长度为 k 的滑动窗口，然后在这个窗口内找是否存在 nums[j]，使得 abs(nums[i] - nums[j]) <= t
// 即在这个滑动窗口内找一个与 nums[i] 最接近的数，即 >= nums[i] 的最小的数 和 <= nums[i] 的最大的数
// >= nums[i] 的最小的数可以用 lower_bound 函数找到，找到后，其前一个数就是 <= nums[i] 的最大的数
// 注1：set 内的数是按升序排列的
// 注2：set 的内置函数 lower_bound 可以找到有序集合中第一个 >= nums[i] 的数


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> S; // INT_MAX - INT_MIN 会爆 int，所以定义成 long long

        // 为了保证一定能找到，加入正无穷和负无穷作为哨兵，这样就不用单独判断边界
        S.insert(1e10); // INT_MAX ≈ 2.1 * 10^9，因此 1e10 就够了
        S.insert(-1e10);

        // 遍历数组，维护一个滑动窗口 nums[j ~ i]，满足：i - j <= k
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            // 如果当前窗口的大小超过了 k，那么就滑出去一个 nums[j]
            while (i - j > k) {
                S.erase(nums[j]); 
                j ++ ;
            }

            int x = nums[i]; // 当前遍历的 nums[i]

            auto it = S.lower_bound(x); // 找到 >= x 的最小值的迭代器（it 是地址，*it 才是对应的值）
            // 如果 >= x 的最小值和 x 的差值满足 <= t，则找到了，返回 true
            if (*it - x <= t) return true; 
    
            it -- ; // 求 < x 的最大值

            // 如果 < x 的最大值和 x 的差值是满足 <= t，则找到了，返回 true
            if (x - *it <= t)  return true; 
                
            S.insert(x); // 将这轮遍历到的 nums[i] 加入有序集合
        }

        // 如果遍历结束都没找到，则返回 false
        return false;
    }
};


// 无注释版本
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> S;

        S.insert(1e10);
        S.insert(-1e10);

        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            while (i - j > k) {
                S.erase(nums[j]);
                j ++ ;
            }

            int x = nums[i];

            auto it = S.lower_bound(x); 
            if (*it - x <= t) return true; 
            it -- ;
            if (x - *it <= t)  return true; 
                
            S.insert(x); 
        }

        return false;
    }
};

