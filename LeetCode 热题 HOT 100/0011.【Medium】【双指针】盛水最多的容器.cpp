// 双指针
// 初始时，l 指向最左侧的柱子，r 指向最右侧的柱子
// 如果 l 指向的柱子低，就 l ++
// 如果 r 指向的柱子低，就 r --
// 每移动一次，计算一下当前所围成的面积，更新一下最大值

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

            // 再移动指针
            // 如果 l 指向的柱子低，则向右移动 l，如果 r 指向的柱子低，则向左移动 r
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
        int n = height.size();
        int res = 0;

        int l = 0;
        int r = n - 1;

        while (l < r) {
            res = max(res, min(height[l], height[r]) * (r - l));

            if (height[l] < height[r]) l ++ ;
            else r -- ;
        } 

        return res;
    }
};


