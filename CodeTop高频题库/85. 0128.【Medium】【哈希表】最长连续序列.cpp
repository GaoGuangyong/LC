
// 因为这个数组是乱排布的，所以考虑把数组里的数都存到哈希集合中
// 遍历 nums 数组，对于当遍历到的数字 x，在哈希集合中找 x + 1 是否存在, ..., 直到 x + y ，然后记录下长度 y - x + 1

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 定义哈希集合，存所有的数
        unordered_set<int> S;
        for (int x: nums) S.insert(x);

        int res = 0;

        // 枚举每一个数
        for (int x: nums) {
            // 如果当前数字 x 存在，且前一个数字 x - 1 不存在，则将当前数字作为一个序列的起点
            if (S.count(x) && !S.count(x - 1)) { 
                S.erase(x); // 枚举过的数，要在哈希集合中删掉
                
                int y = x; // 从 y = x 开始枚举序列的终点
                while (S.count(y + 1)) { // 只要下一个数字 y + 1 存在，就不断将 y 更新为 y + 1 ，并将 y + 1 从集合中删去
                    y += 1; // 序列终点 ++
                    S.erase(y); // 枚举过的数，要在哈希集合中删掉
                }

                res = max(res, y - x + 1); // 更新最大长度 y - x + 1
            }
        }

        return res;
    }
};

// 无注释版本
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S;
        for (int x: nums) S.insert(x);

        int res = 0;

        for (int x: nums) {
            if (S.count(x) && !S.count(x - 1)) {
                S.erase(x);
                
                int y = x;
                while (S.count(y + 1)) {
                    y ++ ;
                    S.erase(y);
                }

                res = max(res, y - x + 1);
            }
        }

        return res;
    }
};