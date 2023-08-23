

// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 返回容器可以储存的最大水量。


// 双指针
// 初始时，l 指向最左侧的柱子，r 指向最右侧的柱子
// 如果 l 指向的柱子低，就 l ++
// 如果 r 指向的柱子低，就 r --
// 每移动一次，计算一下当前所围成的面积 min(height[l], height[r]) * (r - l)，并更新面积的最大值

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int l = 0;
        int r = n - 1;

        int res = 0;

        while (l < r) {
            // 先计算当前 l, r 所围的面积，更新最大值
            res = max(res, min(height[l], height[r]) * (r - l)); 

            // 再移动指针：如果 l 指向的柱子低，则向右移动 l，如果 r 指向的柱子低，则向左移动 r
            if (height[l] < height[r]) l ++ ; 
            else r -- ; 
        }

        return res;
    }
};


// 无注释版本
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;

        int l = 0;
        int r = height.size() - 1;

        while (l < r) {
            res = max(res, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l ++ ;
            else r -- ;
        }

        return res;
    }
};
