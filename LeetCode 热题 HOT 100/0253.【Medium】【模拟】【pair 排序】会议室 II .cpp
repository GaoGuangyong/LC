// 模拟 枚举

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 特判：
        if (intervals.size() == 0) return 0;

        // 定义 pair 数组，存 <上/下车时间, 人数变化(+1/-1)>
        vector<pair<int, int>> meetings;
        // 遍历 intervals，实现 pair 数组
        for (auto& interval: intervals) {
            meetings.push_back({interval[0], +1});
            meetings.push_back({interval[1], -1});
        }
        // 对 pair 数组进行排序，即按照第一个关键字排序
        sort(meetings.begin(), meetings.end());

        int cnt = 0; // 维护实时人数
        int res = 0; // 维护人数的最大值
        for (auto& meeting: meetings) {
            cnt += meeting.second;
            res = max(res, cnt);
        }

        return res;
    }
};