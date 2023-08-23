

// 把所有时间排序，则最小时间差一定出现在相邻的间隔之间
// 为了方便，把所有的时刻都转化成从 0 点开始的分钟数
// 注意由于是可能跨过一天的，所以实际上对于排序的数组是要做环形的比较的

// 也就是说还要计算：
// 最后一个时间，到 24:00（24 * 60 分钟） 的时间差 +  00：00（0 分钟）到第一个时间的时间差

// 给定的时间 timePoint = "HH:MM"，则
// HH = stoi(timePoint.substr(0, 2)) 
// MM = stoi(timePoint.substr(3, 2))
// 则对应的分钟数为：HH * 60 + MM

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX; // 求最小值，所以初始化成无穷大

        // 将所有时刻转化成分钟数，存到数组 time 中，
        vector<int> time; 
        for (string t : timePoints) {
            int minutes = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
            time.push_back(minutes);
        }

        sort(time.begin(), time.end()); // 将时间数组 time 中所有的时间从校到大排序

        // 从小到大俩俩枚举不跨天的时间间隔
        for (int i = 1; i < time.size(); i ++ ) {
            res = min(res, time[i] - time[i - 1]);
        }

        // 再计算一下最后一个时刻和第一个时刻的间隔
        res = min(res, 24 * 60 - time.back() + time[0]);

        return res;
    }
};


// 无注释版本
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for (string timePoint: timePoints) {
            int minutes = stoi(timePoint.substr(0, 2)) * 60 + stoi(timePoint.substr(3, 2));
            time.push_back(minutes);
        }

        sort(time.begin(), time.end());

        int res = INT_MAX;
        for (int i = 1; i < time.size(); i ++ ) {
            res = min(res, time[i] - time[i - 1]);
        }

        res  = min(res, 24 * 60 - time.back() + time[0]);

        return res;
    }
};


// 二刷
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;

        vector<int> times;
        for (string timePoint: timePoints) {
            int minute = stoi(timePoint.substr(0, 2)) * 60 + stoi(timePoint.substr(3, 2));
            times.push_back(minute);
        }

        sort(times.begin(), times.end());

        for (int i = 1; i < times.size(); i ++ ) {
            res = min(res, times[i] - times[i - 1]);
        }

        int last = (24 * 60 - times[times.size() - 1]) + times[0];

        res = min(res, last);

        return res; 
    }
};

