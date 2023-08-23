
// 双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        int sum; 

        while (l < r) { // 仅当左右指针不重合时进行循环遍历
            sum = numbers[l] + numbers[r]; //记录当前两个指针所指内容的和
            if (sum == target) break; // 若当前两个指针所指内容的和 = 目标，则找到，退出循环
            if (sum < target) l ++ ; // 若当前两个指针所指内容的和 < 目标，则左指针 + 1
            if (sum > target) r -- ;// 若当前两个指针所指内容的和 > 目标，则右指针 + 1
        }
        
        return {l, r}; // 返回数组，其值分别为左右指针的下标

    }
};


// 无注释版本
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        int sum = 0;

        while (l < r) { 
            sum = numbers[l] + numbers[r];

            if (sum == target) break;
            if (sum < target) l ++ ;
            if (sum > target) r -- ;
        }
        
        return {l, r};
    }
};

// 二刷
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        int sum;

        while (l < r) {
            sum = numbers[l] + numbers[r];
            if (sum == target) break;
            else if (sum < target) l ++ ;
            else if (sum > target) r -- ;
        }

        return {l, r};
    }
};


