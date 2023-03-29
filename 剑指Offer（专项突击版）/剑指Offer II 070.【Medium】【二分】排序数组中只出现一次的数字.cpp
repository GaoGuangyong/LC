// 二分
// 把相邻 2 个数看成一组，不论数组中元素的个数是多少，都先补一个
// 那我们就会发现，可以找到一个分界点，分界点左边的每组数相同，分界点右边每组数不同

// [1, 1] [2, 3] [3, 4] [4, 8] [9, ] // 在数组最后补一个 9
// n = 9，l = 0; r = 9 / 2 - 1 = 3
// 即 l -> [1, 1]，r -> [4, 8]

// [1, 1] [2, 2] [3, 3] [4, 5] [5, 6] [6, 7]  // 在数组最后一个 6 后面补一个 7
// n = 12，l = 0; r = 12 / 2 - 1 = 5
// 即 l -> [1, 1]，r -> [6, 7]

// 答案就是分界点右边第一个数

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 先在数组的结尾补一个数，只要和数组的最后一个数不一样就行
        nums.push_back(nums.back() + 1);
        int n = nums.size();

        // l，r 指向的是组号
        int l = 0;
        int r = n / 2 - 1;

        while (l < r) {
            // 二分组号 mid
            int mid = l + r >> 1;
            
            // 在一个组内相邻的两个数的下标就是 mid * 2 与 mid * 2 + 1
            int first = mid * 2;
            int second = mid * 2 + 1;

            // 如果一个组内相邻的两个数不相等，则分界点在当前位置或当前位置的左边
            if (nums[first] != nums[second]) 
                r = mid;
            // 如果一个组内相邻的两个数相等，则分界点在当前位置的右边
            else 
                l = mid + 1;
        }

        return nums[r * 2];
    }
};


// 无注释版本
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        nums.push_back(-1);
        int n = nums.size();

        int l = 0;
        int r = n / 2 - 1;

        while (l < r) {
            int mid = l + r >> 1;

            int first = mid * 2;
            int second = mid * 2 + 1;

            if (nums[first] != nums[second]) 
                r = mid;
            else
                l = mid + 1;
        }

        return nums[l * 2];
    }
};



