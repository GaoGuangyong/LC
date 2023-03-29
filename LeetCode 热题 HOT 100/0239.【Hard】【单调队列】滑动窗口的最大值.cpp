// 同 剑指Offer59-1
// 单调队列
// 题意：给定 nums 和 k，给出所有长度为 k 的滑动窗口里的最大值
// 思路：利用双端队列实现一个单调的队列（从队头到队尾单调递减），用来存放数组中数字的下标，队头始终放最大值的下标

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; // 定义一个双端队列，队列中存储元素的下标
        vector<int> res;

        for (int i = 0; i < nums.size(); i ++ ) {
            // 1、维护窗口大小：队头下标如果距离 i 超过了 k（即窗口内的元素个数超过了 k 个），则队头出队
            while (q.size() && i - q.front() >= k)  q.pop_front();
            // 2、单调性维护：如果 nums[i] >= 队尾元素下标所对应的值，则当前队尾再也不可能充当某个滑动窗口的最大值了，故队尾出队
            while (q.size() && nums[i] >= nums[q.back()]) q.pop_back();

            q.push_back(i); // 将当前数字的下标插入队尾

            // 从 i == k - 1 开始，将队头下标对应的数加入结果数组中，即滑动窗口中的元素达到了 k 个，才可以将其加入答案数组中
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};

// 无注释版本
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;

        for (int i = 0; i < nums.size(); i ++ ) {
            while (q.size() && i - q.front() >= k) q.pop_front();
            while (q.size() && nums[i] >= nums[q.back()]) q.pop_back();

            q.push_back(i);

            if (i >= k - 1) res.push_back(nums[q.front()]);
        }

        return res;
    }
};

