
// 模拟



class Solution {
public:
    string replaceSpace(string s) {
        string res;

        for (char c: s) {
            if (c == ' ') res += "%20";
            else res += c;
        }

        return res;
    }
};
