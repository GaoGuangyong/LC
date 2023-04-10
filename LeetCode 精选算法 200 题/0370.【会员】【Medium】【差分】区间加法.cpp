
// 差分

// 写法一：定义原数组 & 差分数组，返回原数组
class Solution {
public:
    vector<int> s; // 原数组：差分数组的前缀和数组
    vector<int> b; // 差分数组

    // 辅助函数：对原数组的区间 [l, r] 的所有数都加 c
    void insert(int l, int r, int c) {
        b[l] += c;
        b[r + 1] -= c;
    }

    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        s.resize(length);
        b.resize(length + 1); // 差分数组长度为原数组 + 1 

        for (auto& e : updates) {
            insert(e[0], e[1], e[2]);
        }

        s[0] = b[0];
        for (int i = 1; i < length; i ++ ) s[i] = s[i - 1] + b[i];
        
        return s;
    }
};


// 写法二：差分数组，返回差分数组
class Solution {
public:
    vector<int> b; // 差分数组

    // 辅助函数：对原数组的区间 [l, r] 的所有数都加 c
    void insert(int l, int r, int c) {
        b[l] += c;
        b[r + 1] -= c;
    }

    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        b.resize(length + 1); // 差分数组长度为原数组 + 1 

        for (auto& e : updates) {
            insert(e[0], e[1], e[2]);
        }

        for (int i = 1; i < length; i ++ ) b[i] += b[i - 1];
        b.pop_back();
        
        return b;
    }
};


