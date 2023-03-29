

// 哈希表
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // 定义一个哈希表，存字符串 order 中每个字母及其下标
        unordered_map<char, int> hash;
        for (int i = 0; i < order.size(); i ++ ) hash[order[i]] = i;

        // 从前往后枚举 words 数组，判断相邻两个字符串 a 和 b 是否为升序
        for (int i = 1; i < words.size(); i ++ ) {
            string a = words[i - 1];
            string b = words[i];
            int x = 0; // 用于枚举字符串 a，字符 a[x] 在字典里的下标为 hash[a[x]]
            int y = 0; // 用于枚举字符串 b，字符 b[x] 在字典里的下标为 hash[b[x]]

            // 当字符串 a 没有枚举完且字符串 b 没有枚举完
            while (x < a.size() && y < b.size()) { 
                // 如果是逆序，则返回 false  
                if (hash[a[x]] > hash[b[y]]) return false;
                // 如果是顺序，则退出当前循环，继续比较下一位
                if (hash[a[x]] < hash[b[y]]) break;

                x ++ ;
                y ++ ;
                
            }

            // 特殊情况，如果 b 已经遍历完毕了 a 还没有遍历完，则 a > b，同样是逆序，返回 false
            if (x < a.size() && y == b.size()) return false;
        }
        return true;
    }
};


// 无注释版本
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> hash;
        for(int i = 0; i < order.size(); i ++ ) hash[order[i]] = i;

        for (int i = 1; i < words.size(); i ++ ) {
            string a = words[i - 1];
            string b = words[i];
            
            int x = 0;
            int y = 0;

            for (; x < a.size() && y < b.size(); x ++ , y ++ ) {
                if (hash[a[x]] > hash[b[y]]) return false;
                if (hash[a[x]] < hash[b[y]]) break;
            }

            if (x < a.size() && y == b.size()) return false;
        }

        return true;
    }
};

