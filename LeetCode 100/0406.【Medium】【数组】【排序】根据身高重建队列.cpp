/*

我们先按照身高从大到小排序（身高相同的情况下 K 小的在前面）
这样的话，无论哪个人的身高都 <= 他前面人的身高
所以接下来只要按照 K 值将他插入相应的位置就可以了
新建一个二维数组，按照 K 值将每个一维数 people[i] 组插入到新建的二维数组的第 k 个位置上

例如：示例 1 排完序：[[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]
[7, 0] 插入第 0 的位置
[7, 1] 插入第 1 的位置
[6, 1] 插入第 1 的位置，这时 [7, 1] 就往后移一位了
........

*/


// 写法一：在主函数外写成 static bool 函数，然后在主函数中调用
class Solution {
public:
    // 自定义比较函数：比较 数组 a 与 数组 b
    static bool cmp(vector<int> a,vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1]; // 如果身高相同，则 k 小的在前 
        return a[0] > b[0]; // 否则，身高大的在前
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 先对原二维数组排序
        sort(people.begin(), people.end(), cmp);

        // 再新建一个二维数组，将每个一维数组插入到新建的二维数组的第 k 个位置上
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); i ++ ) {
            int k = people[i][1]; // 获取 k
            // 在二维数组的第 k 个位置上插入一维数组 people[i]
            res.insert(res.begin() + k, people[i]);
        }
        return res;
    }
};


// 写法二：用 lamda 表达式，定义和调用写在一起
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 先对身高数组按降序排序，身高相同时，k 小的在前
        sort(people.begin(), people.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<vector<int>> res;

        for (int i = 0; i < people.size(); i ++ ) {
            int k = people[i][1];
            res.insert(res.begin() + k, people[i]);
        }

        return res;
    }
};

// 写法三：用 lamda 表达式，先定义再调用
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        };

        // 先对身高数组按降序排序，身高相同时，k 小的在前
        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> res;

        for (int i = 0; i < people.size(); i ++ ) {
            int k = people[i][1];
            res.insert(res.begin() + k, people[i]);
        }

        return res;
    }
};



