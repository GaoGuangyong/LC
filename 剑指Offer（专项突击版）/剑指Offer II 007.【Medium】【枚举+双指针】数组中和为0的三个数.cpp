

// 枚举 + 双指针
// 先对数组排序
// 1、枚举每个数，表示该数 nums[i] 已被确定，通过双指针 l，r 分别从左边 i + 1 和右边 n - 1 往中间遍历
// 找满足 nums[i] + nums[l] + nums[r] == 0 的所有符合条件的搭配

// 2、在找符合条件搭配的过程中，假设 sum = nums[i] + nums[l] + nums[r]
//   若 sum > 0，则 r 往左走，使 sum 变小
//   若 sum < 0，则 l 往右走，使 sum 变大
//   若 sum == 0，则表示找到了与 nums[i] 搭配的组合 nums[l] 和 nums[r]，存到 res 中

// 3、判重处理
//   1、当 nums[i] == nums[i - 1]，表示当前确定好的数与上一个一样，则跳过
//   2、当找符合条件搭配时，即 sum == 0 时，需要对相同的 nums[l] 和 nums[r] 进行判重
//   例：[-1, -2, -2, 3, 3]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end()); // 先将数组按从小到大排序

        // 枚举 nums 数组，设 nums[i] 为三个数中的第一个数
        for (int i = 0; i < n; i ++ ) {
            // 减枝：若枚举到了重复的数，则跳过
            if (i >= 1 && nums[i] == nums[i - 1]) continue;

            // 否则，从 i + 1 和 n - 1 开始向中间搜索（相当于两数之和）
            int l = i + 1;
            int r = n - 1; 

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                // 若目前三数之和等于 0，则将其加入答案二维数组中，并进行判重处理
                if (sum == 0) { 
                    res.push_back({nums[i], nums[l], nums[r]}); 
                    // 判重处理（如果不用 do while 则会超时）
                    do l ++ ; while(l < r && nums[l] == nums[l - 1]);
                    do r -- ; while(l < r && nums[r] == nums[r + 1]);
                }
                else if (sum < 0) l ++ ; // 如果三数之和 < 0，则需要右移 l 指针，使其和变大
                else if (sum > 0) r -- ; // 如果三数之和 > 0，则需要左移 r 指针，使其和变小
            }
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i ++ ) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    do l ++ ; while (l < r && nums[l] == nums[l - 1]);
                    do r -- ; while (l < r && nums[r] == nums[r + 1]);
                }
                else if (sum < 0) l ++ ;
                else if (sum > 0) r -- ;
            }
        }

        return res;
    }
};
