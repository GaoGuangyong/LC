// 双指针
// 从前往后枚举数组，对于当前位置 i，看能跳到的最后一个位置 j 是多少？即 j = max(j, i + nums[i])
// 当枚举到位置 i 时，如果发现前面的 0 ~ i-1 位置能跳到的最后的位置 j < i，则说明 i 永远都跳不到了，返回 false
// 如果整个数组都遍历完了，都没找到这样的 j，则返回 true

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j = 0;

        for (int i = 0; i < nums.size(); i ++ ) {
            // 每次遍历时，判断 j 和 i 的关系，如果 j < i，则无法跳到 i，也就无法跳到终点
            if (j < i) return false;
            // 更新目前为止能跳到的最远距离
            j = max(j, i + nums[i]);
        }

        // 如果能遍历完整个数组，说明可以到达终点
        return true;
    }
};


// 无注释版本
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j = 0; 

        for (int i = 0; i < nums.size(); i ++ ) {
            if (j < i) return false;
            j = max(j, i + nums[i]);
        }

        return true;
    }
};


