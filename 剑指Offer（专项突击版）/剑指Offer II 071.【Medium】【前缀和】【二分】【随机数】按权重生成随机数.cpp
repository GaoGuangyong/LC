// 前缀和 + 二分

// w[0] = 1 表示总长度 6 中占 1 份，即 1
// w[1] = 2 表示总长度 6 中占 2 份，即 2, 3
// w[2] = 3 表示总长度 6 中占 3 份，即 4, 5, 6

// 求数组 w 的前缀和数组 s，使用 s[i] 记录前 i 份的总值
// 生成一个 x，找到在 s[i] 中 >= x 的最小值，该值对应的坐标就是第几份

//   i  =  0, 1, 2
// w[i] = [1, 2, 3]
// s[i] = [0, 1, 3, 6]

// 然后从 1 ~ 6 随机获取一个数字 x，在 s 中找到 >= x 的最小值对应的下标
// 如果数字 x 在 [1, 1] 即 1       则 s 中 >= x 的最小值为 1，对应 w[0]，返回下标 0
// 如果数字 x 在 [2, 3] 即 2, 3    则 s 中 >= x 的最小值为 3，对应 w[1]，返回下标 1
// 如果数字 x 在 [4, 6] 即 4, 5, 6 则 s 中 >= x 的最小值为 6，对应 w[2]，返回下标 2

class Solution {
public:
    vector<int> s; // 声明前缀和数组
    int n;

    Solution(vector<int>& w) {
        n = w.size();

        // 定义前缀和数组
        s.resize(n + 1);

        // 初始化前缀和数组 
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + w[i - 1];
        }
    }


    int pickIndex() {
        // 随机获取一个 [1 ~ s.back()] 的下标 x
        int x = rand() % s.back() + 1; 
        
        int l = 1;
        int r = n;
        
        // 在前缀和数组 s 中二分的是第一个 >= x 的那个数所在的下标
        while (l < r) {
            int mid = l + r >> 1;
            // 如果当前二分到的下标 mid 对应的 s[mid] >= x，则答案在 mid 左边，或就是 mid 对应的数
            if (s[mid] >= x) 
                r = mid;
            else 
                l = mid + 1;
        }
        
        return r - 1;
        
        // 找出 s 中第一个 >= x 的数的下标
        // return lower_bound(s.begin(), s.end(), x) - s.begin();
    }
};



// 无注释版本
class Solution {
public:
    vector<int> s;
    int n;

    Solution(vector<int>& w) {
        n = w.size();
        
        s.resize(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + w[i - 1];
        }
    }

    int pickIndex() {
        int x = (rand() % s.back()) + 1;

        int l = 1;
        int r = n;

        while (l < r) {
            int mid = l + r >> 1;
            if (s[mid] >= x) 
                r = mid;
            else
                l = mid + 1;
        }

        return r - 1;
    }
};


// 写法二
class Solution {
public:
    vector<int> s;
    int n;

    Solution(vector<int>& w) {
        n = w.size();

        s.resize(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + w[i - 1];
        }
    }

    int pickIndex() {
        int x = rand() % s.back() + 1; 
        
        // 找出 s 中第一个 >= x 的数的下标 - 1
        return lower_bound(s.begin(), s.end(), x) - s.begin() - 1;
    }
};
