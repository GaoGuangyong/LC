
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组

// 模板题
// 先将所有区间按照起点的大小排序
// 如果当前区间的起点 >  上一个区间的终点：则无交集，上一个区间已是独立区间，不需要再合并，输出上一个区间，并重新令当前区间的头尾作为要合并区间的头尾
// 如果当前区间的起点 <= 上一个区间的终点：则有交集，更新右端点为当前区间的终点和上一个区间终点二者的最大值



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()); // 将所有区间按照起点排序

        // 初始时，令 l 和 r 分别为 第 1 个区间的头尾
        int l = intervals[0][0];
        int r = intervals[0][1];

        vector<vector<int>> res; // 结果数组

        // 从第二个区间开始，枚举每个区间的起点
        for (int i = 1; i < intervals.size(); i ++ ) {
            // 如果当前区间的起点 >  上一个区间的终点：则无交集，输出上一个区间
            if (intervals[i][0] > r) {
                // 将上一个区间 [l, r] 加入结果数组
                res.push_back({l, r});
                // 重新令 l 和 r 为当前区间的头尾
                l = intervals[i][0];
                r = intervals[i][1];
            }
            // 如果当前区间的起点 <= 上一个区间的终点：则有交集，更新右端点为当前区间的终点和上一个区间终点的最大值
            else {
                r = max(r, intervals[i][1]); // 注意是和 r 比较，不是和 intervals[i - 1][1] 比较
            }
        }

        res.push_back({l, r}); // 将最后一个有效的区间也放进来
        
        return res;
    }
};


// 二刷
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        int l = intervals[0][0];
        int r = intervals[0][1];

        for (int i = 1; i < intervals.size(); i ++ ) {
            if (intervals[i][0] > r) {
                res.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else r = max(r, intervals[i][1]);
        }

        res.push_back({l, r});

        return res;
    
    }
};