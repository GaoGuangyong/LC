// 三次线性扫描
// 观察整个图形，考虑对水的面积按 列 进行拆解
// 注意到，每个矩形条上方所能接受的水的高度，是由它左边最高的矩形，和右边最高的矩形决定的。
// 具体地，假设第 i 个矩形条的高度为 height[i]，且矩形条左边最高的矩形条的高度为 left_max[i]，右边最高的矩形条高度为 right_max[i]，则该矩形条上方能接受水的高度为
// min(left_max[i], right_max[i]) - height[i]。
// 需要分别从左向右扫描求 left_max，从右向左求 right_max，最后统计答案即可。
// 注意特判 n 为 0

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left_max(n);
        vector<int> right_max(n);

        left_max[0] = height[0]; // 初始时，左侧最高的矩形条的高度为第一个矩形条的高度
        right_max[n - 1] = height[n - 1]; // 初始时，右侧最高的矩形条的高度为最后一个矩形条的高度


        // 第一次扫描，从第二个开始，求出每个矩形条 i 左侧的最高矩形条的高度 left_max[i]
        for (int i = 1; i < n; i ++ ) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        // 第二次扫描，从倒数第二个开始，求出每个矩形条 i 右侧的最高矩形条的高度 right_max[i]
        for (int i = n - 2; i >= 0; i -- ) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int res = 0;

        // 第三次扫描，求出每个矩形条 i 上方能存雨水的最大值 min(left_max[i], right_max[i]) - height[i]
        for (int i = 0; i < n; i ++ ) {
            res += min(left_max[i], right_max[i]) - height[i];
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left_max(n);
        vector<int> right_max(n);

        left_max[0] = height[0];
        right_max[n - 1] = height[n - 1];

        for (int i = 1; i < n; i ++ ) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i -- ) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int res = 0;

        for (int i = 0; i < n; i ++ ) {
            res += min(left_max[i], right_max[i]) - height[i];
        }

        return res;
    }
};


