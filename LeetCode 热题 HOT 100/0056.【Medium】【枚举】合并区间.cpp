
// 模板题
// 将所有区间按照起点的大小排序
// 如果当前区间的起点 >  上一个区间的终点：则无交集，上一个区间已是独立区间，不需要再合并，输出上一个区间
// 如果当前区间的起点 <= 上一个区间的终点：则有交集，更新右端点为当前区间的终点和上一个区间终点二者的最大值

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<vector<int>> res; // 结果数组

        sort(intervals.begin(),intervals.end()); // 将所有区间按照起点排序

        // 初始时，令 l 和 r 分别为 第 1 个区间的头尾
        int l = intervals[0][0];
        int r = intervals[0][1];

        // 从第二个区间开始，枚举每个区间的起点
        for (int i = 1; i < n; i ++ ) {
            // 如果当前区间的起点 >  上一个区间的终点：则无交集，输出上一个区间
            if (intervals[i][0] > r) {
                // 将上一个区间 [l, r] 加入结果数组
                res.push_back({l, r});
                // 重新令 l 和 r 为当前区间的头尾
                l = intervals[i][0];
                r = intervals[i][1];
            }
            // 如果当前区间的起点 <= 上一个区间的终点：则有交集，更新右端点为当前区间的终点和上一个区间终点二者的最大值
            else {
                r = max(r, intervals[i][1]);
            }
        }
        res.push_back({l, r}); // 将最后一个有效的区间也放进来
        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<vector<int>> res;

        sort(intervals.begin(),intervals.end());
        
        int l = intervals[0][0];
        int r = intervals[0][1];

        for (int i = 1; i < n; i ++ ) {
            if (intervals[i][0] > r) {
                res.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else {
                r = max(r, intervals[i][1]);
            }
        }
        res.push_back({l, r});
        
        return res;
    }
};


