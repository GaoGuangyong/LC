// 二分

// 找 >= target 的最小位置，当所有元素都比 target 小时，要在最后插入
// 所以 r 从 len 位置而不是 len - 1 位置

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        while (l < r) {
            int mid = l + r >> 1;
            // 如果当前二分到的数 >= target，则答案可能是 mid 或在 mid 左边
            if (nums[mid] >= target) 
                r = mid;
            else 
                l = mid + 1;
        }

        return l;
    }
};


// 写法二：
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] < target)
                l = mid + 1;
            else 
                r = mid - 1;
        }

        return l;
    }
};

