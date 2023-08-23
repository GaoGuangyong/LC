
// 模拟
// 爆搜，搜第一个数到第四个数，确保分割后每个数字满足：
// 1. 在 0 ~ 255之间，没有前导 0
// 2. 本身就是 0 

class Solution {
public:
    // 辅助函数：判断 ip 地址每段是否合法
    bool check(string s) {
        if (stoi(s) <= 255 && s[0] != '0') return true;
        else if (s == "0") return true;
        return false;
    }

    // 主函数
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;

        // 枚举 4 段 ip，a b c d 分别表示 4 段 ip 地址长度
        for (int a = 1; a <= 3; a ++ ) 
            for (int b = 1; b <= 3; b ++ ) 
                for (int c = 1; c <= 3; c ++ ) 
                    for (int d = 1; d <= 3; d ++ ) 
                        if (a + b + c + d == s.size()) { // 四段长度刚好
                            // 分别截取四段 ip 地址
                            string s1 = s.substr(0, a); // 截取 s[0 ~ a)
                            string s2 = s.substr(a, b); // 截取 s[a ~ a + b)
                            string s3 = s.substr(a + b, c); // 截取 s[a + b ~ a + b + c)
                            string s4 = s.substr(a + b + c, d); // 截取 s[a + b + c ~ a + b + c + d)
                            // 如果四段 ip 地址都合法，则按照 ip 的规则输出
                            if (check(s1) && check(s2) && check(s3) && check(s4)) {
                                string ip = s1 + '.' + s2 + '.' + s3 + '.' + s4;
                                res.push_back(ip);
                            }
                        }

        return res;
    }
};



// 二刷
class Solution {
public:
    bool check(string s) {
        if (stoi(s) <= 255 && s[0] != '0') return true;
        else if (s == "0") return true;
        return false;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;

        for (int a = 1; a <= 3; a ++ )
            for (int b = 1; b <= 3; b ++ )
                for (int c = 1; c <= 3; c ++ ) 
                    for (int d = 1; d <= 3; d ++ )
                        if (a + b + c + d == s.size()) {
                            string s1 = s.substr(0, a);
                            string s2 = s.substr(a, b);
                            string s3 = s.substr(a + b, c);
                            string s4 = s.substr(a + b + c, d);
                            if (check(s1) && check(s2) && check(s3) && check(s4)) {
                                string ip = s1 + '.' + s2 + '.' + s3 + '.' + s4;
                                res.push_back(ip);
                            }
                        }

        return res;
    }
};

