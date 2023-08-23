// 见笔记 +  https://www.acwing.com/activity/content/code/content/654956/
// + https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode-solution-ur9w/ 的方法二

// https://leetcode.cn/problems/task-scheduler/solution/tong-zi-by-popopop/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 定义哈希表：存每个字母 c 及其出现的次数 cnt
        unordered_map<char, int> hash;
        for (char c: tasks) hash[c] ++ ;

        int max_cnt = 0; // 出现次数最多的字母出现了 max_cnt 次
        int k = 0; // 共有 k 个字母出现了 max_cnt 次

        // 遍历哈希表，求出现次数最多的字母出现了多少次（max_cnt）
        for (auto [c, cnt]: hash) {
            max_cnt = max(max_cnt, cnt);
        }

        // 遍历哈希表，求出有多少个字母出现了 max_cnt 次，即最后一行的个数
        for (auto [c, cnt]: hash) {
            if (cnt == max_cnt) k ++ ;
        }

        // 返回结果
        int len1 = tasks.size();
        int len2 = (max_cnt - 1) * (n + 1) + k
        return max(len1, len2);
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

        int len1 = tasks.size();
        int len2 = (max_cnt - 1) * (n + 1) + k
        return max(len1, len2);
    }
};



// 二刷

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> hash;
        for (char c: tasks) hash[c] ++ ;

        int max_cnt = 0;
        int k = 0;

        for (auto [c, cnt]: hash) max_cnt = max(max_cnt, cnt);

        for (auto [c, cnt]: hash) if (cnt == max_cnt) k ++ ;

        int len1 = tasks.size();
        int len2 = (max_cnt - 1) * (n + 1) + k;
        
        return max(len1, len2);
    }
};