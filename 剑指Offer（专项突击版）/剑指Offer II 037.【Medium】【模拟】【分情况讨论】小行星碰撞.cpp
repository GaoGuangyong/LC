
// 模拟 + 分情况讨论
// 如果两个行星向同方向移动，则不会相撞
// 如果左边的行星向左移动，右边的行星向右移动，则不会相撞
// 如果左边的行星向右移动，右边的行星向左移动，则会相撞
// 如果两个行星要相撞，一定是这两个行星中间没有其他的行星了，否则一定是先撞中间的（即相撞的行星一定是相邻的）

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        // 从左开始枚举所有的行星
        for (int x : asteroids) {
            // 如果当前行星向右移动，则加入 res 数组中保留
            if (x > 0) res.push_back(x);
            
            // 如果当前行星向左移动，则要考虑他左边的情况，即枚举 res 数组
            else {
                // 将当前行星左边，所有向右走的，且比当前行星小的都撞掉（注意要判断 res 数组不为空：res.size()）
                while (res.size() && res.back() > 0 && res.back() < abs(x)) {
                    res.pop_back();
                }

                // 如果遇到当前行星左边，向右走的，且和当前行星一样大的，则也撞掉，但同时当前行星也要撞掉，故不 push_back(x)
                if (res.size() && res.back() > 0 && res.back() == abs(x)) res.pop_back();

                // 如果 res 数组已经空了，或者剩下的是向左走的就保留下来
                else if (res.empty() || res.back() < 0) res.push_back(x);

                // 其它情况，说明是向右走的，且比当前行星大的，则不会被当前行星撞掉，保留(即什么都不用做)
            }
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (int x: asteroids) {
            if (x > 0) res.push_back(x);

            else if (x < 0) {
                while (res.size() && res.back() > 0 && res.back() < abs(x)) res.pop_back();

                if (res.size() && res.back() > 0 && res.back() == abs(x)) res.pop_back();

                else if (res.empty() || res.back() < 0) res.push_back(x);
            }
        }

        return res;
    }
};


