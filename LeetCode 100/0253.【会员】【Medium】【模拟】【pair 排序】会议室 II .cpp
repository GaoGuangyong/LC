

// 给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。

// 上下车模型 -> 模拟 枚举

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 定义 pair 类型数组 meetings，存 <会议开始/结束时间, 会议室数量变化>
        vector<pair<int, int>> meetings;

        // 遍历 intervals，维护 pair 数组
        for (auto& interval: intervals) {
            meetings.push_back({interval[0], +1}); // <会议开始时间, +1>
            meetings.push_back({interval[1], -1}); // <会议结束时间, -1>
        }

        int cnt = 0; // 维护实时会议室数量
        int res = 0; // 维护会议室数量的最大值

        // 对 meetings 数组进行排序，即按照 时间 排序
        sort(meetings.begin(), meetings.end());

        // 遍历 meetings 数组，更新 cnt 和 res 
        for (auto& meeting: meetings) {
            // 每遍历到一个开始的会议，cnt + 1
            // 每遍历到一个结束的会议，cnt - 1
            cnt += meeting.second;
               
            res = max(res, cnt); // 更新会议室数量的最大值 
        }

        return res;
    }
};


// 二刷
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> meetings;

        for (auto interval: intervals) {
            meetings.push_back({interval[0], +1});
            meetings.push_back({interval[1], -1});
        }

        int cnt = 0;
        int res = 0;

        sort(meetings.begin(), meetings.end());

        for (auto meeting: meetings) {
            cnt += meeting.second;
            res = max(res, cnt);
        }

        return res;
    }
};