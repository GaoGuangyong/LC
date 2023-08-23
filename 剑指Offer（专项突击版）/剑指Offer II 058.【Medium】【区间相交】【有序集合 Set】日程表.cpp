
// 解法一：pair
// 题意：对于给定的区间，判断是否和已有区间相交
// 区间相交问题自然想到用 pair 类型的哈希表存这些区间，因为对 pair 排序，是先按 first 升序排序，再按 second 升序排序
// 对于给定的区间 [start, end]，以 start 为分界线，将已有的所有区间划分成两部分, 然后判断
// 当前区间的 start 和前半部分的最后一个区间的 end 的关系
// 当前区间的 end 和后半部分的第一个一个区间的 start 的关系



class MyCalendar {
public:
    // 全局变量
    int INF = 1e9; // 定义一个无穷大值 INF = 1e9（因为 0 <= start < end <= 1e9）
    set<pair<int, int>> S; // 定义有序哈希结合，存所有没有交集的区间

    // 初始化
    MyCalendar() {
        // 为了避免判断边界区间为空的情况，设置两个哨兵区间，这样的话在最左侧和最右侧都还有区间存在
        S.insert({-INF, -INF}); // 区间 [负无穷，负无穷]
        S.insert({INF, INF});   // 区间 [正无穷，正无穷]
    }

    // 判断当前区间 [start, end) 和已有的区间是否相交，如果不相交，则返回 true，否则返回 false
    bool book(int start, int end) {
        // 找后半部分的第一个区间，即找第一个 起点 >= start 的迭代器，终点无所谓，>= 负无穷即可
        auto it = S.lower_bound({start, -INF});

        // 如果后半部分的第一个区间的左端点 < end 或 前半部分的最后一个区间的右端点 > start，则相交
        if (it->first < end || ( -- it)->second > start) return false;
        
        //  否则，当前区间和已有区间不相交，将当前区间插入有序哈希集合，返回 true
        S.insert({start, end});
        return true;
    }
};



// 无注释版本
class MyCalendar {
public:
    set<pair<int, int>> S;
    int INF = 1e9;
    
    MyCalendar() {
        S.insert({-INF, -INF});
        S.insert({INF, INF});
    }
    
    bool book(int start, int end) {
        auto it = S.lower_bound({start, -INF});
        if (it->first < end || (--it)->second > start) return false;
        else S.insert({start, end});
        return true;
    }
};



// 解法二：直接遍历
// 我们记录下所有已经预订的课程安排区间，当我们预订新的区间 [start, end) 时
// 检查当前已经预订的每个日程安排是否与新日程安排冲突。若不冲突，则可以添加新的日程安排
// 对于两个区间 [l, r) 和 [start, end)，如果二者没有交集，则此时应当满足 l >= end 或者 start >= r
// 也就是说如果满足 l < end 并且 start < r，则两者会产生交集

class MyCalendar {
public:
    vector<pair<int, int>> booked;

    MyCalendar() {

    }

    bool book(int start, int end) {
        for (auto& [l, r]: booked) {
            if (l < end && start < r) {
                return false;
            }
        }
        booked.push_back({start, end});
        return true;
    }
};


