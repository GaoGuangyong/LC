// 见笔记 +  https://www.acwing.com/activity/content/code/content/654956/
// + https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode-solution-ur9w/ 的方法二

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 定义一个哈希表存储每个字符 c 及其出现的次数 cnt
        unordered_map<char, int> hash;
        for (auto c: tasks) hash[c] ++ ;

        int mc = 0; // 出现次数最多的字母出现了 mc 次
        int k = 0; // 共有 k 个字母出现了 mc 次

        // 遍历哈希表，求出最多的那个字母出现了多少次（mc）
        for (auto [c, cnt]: hash) {
            mc = max(mc, cnt);
        }

        // 遍历哈希表，求出有多少个字母出现了 mc 次
        for (auto [c, cnt]: hash) {
            if (mc == cnt) k ++ ;
        }

        // 返回结果
        return max((int)tasks.size(), (mc - 1) * (n + 1) + k);
    }
};


// 无注释版
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        unordered_map<char, int> hash;
        for (char c: tasks) hash[c] ++ ;

        int mc = 0;
        int k = 0;

        for (auto& [c, cnt]: hash) {
            mc = max(mc, cnt);
        }

        for (auto& [c, cnt]: hash) {
            if (mc == cnt) k ++ ;
        }

        return max(len, (mc - 1) * (n + 1) + k);
    }
};