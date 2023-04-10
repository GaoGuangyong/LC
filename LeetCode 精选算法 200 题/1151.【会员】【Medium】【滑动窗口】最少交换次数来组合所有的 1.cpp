
// 滑动窗口
// 题目要求将数组中任何位置上的 1 组合到一起，那么肯定需要知道数组中 1 的个数
// 假设数组中 1 的个数为 5，数组中某一段的数字为 1 0 1 0 1，则只需要把里面的两个 0 交换出去就能得到最小交换次数


class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        // 1、计算原数组中 1 的个数 len
        int len = 0;
        for (int x: data) {
            if (x == 1) len ++ ;
        }

        // 2、维护一个长度为 len 的滑动窗口
        // 先求出第一个窗口中 1 的个数，记为 cnt
        int cnt = 0; 
        for (int i = 0; i < len; i ++ ) {
            cnt += data[i];
        }

        // 再求所有滑动窗口中 1 的最大个数，记为 maxCnt，初始时为第一个窗口中 1 的个数
        int maxCnt = cnt;
        for (int i = 0; i < n; i ++ ) {
            int j = i + len;
            if (j >= n) break;
            // 每次滑出 data[i]，滑入 data[j]，因此窗口中 1 的个数为：+ data[j] - data[i]
            cnt = cnt + data[j] - data[i];
            maxCnt = max(maxCnt, cnt);
        }

        // 则答案：需要交换的次数 = 1 的总个数 - 所有滑动窗口中 1 的最大个数
        return len - maxCnt; 
    }
};

