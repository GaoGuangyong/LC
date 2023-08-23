// https://leetcode.cn/problems/Jf1JuT/solution/jian-zhi-offer-2-mian-shi-ti-114-shu-zho-8itg/
/*
拓扑排序
对字符串 s1 和字符串 s2 进行排序时，从两者的首字母开始逐位对比，先出现较小的字母的单词排序在前，若直到其中一个单词所有字母都对比完都无法得出结果，则长度较小的单词排序在前。
以题目中 words = ["ac","ab","bc","zc","zb"] 为例，一共出现了 'a'、'b'、'c' 和 'z' 4 个字母
由于 "ac" < "ab" 所以 'c' < 'b'，由于 "ab" < "bc" 所以 'a' < 'b'，依次可得 'b' < 'z' 、'c' < 'b'。

现在需要找出四个字母之间的关系，使其满足上述的关系，可以使用拓扑排序解决。
可以把每个字母看作图的节点，若已知两个字母之间的大小关系，那么图中就存在一条从较小的字母指向较大字母的边。
如果最后能给出有向图的拓扑排序序列，那么任意一条边的起始节点（较小的字母）一定出现在终止节点（较大的字母）的前面。

完整代码如下，
使用一个哈希表 graph 来保存各节点的邻接表
使用一个哈希表 inDegress 表示各节点的入度
首先遍历所有单词的字母对两个哈希表做初始化。接下来比较单词列表内两两相邻的单词，从头开始找到第一个不相同的字母，在图内添加一条从较小字母指向较大字母的边
这里需要注意一类特殊输入，若两者的前缀相同，但前者的单词长度长于后者，如 "abc" 和 "ab"。这是不符合排序规则的，无论最后字母存在怎么样的拓扑排序都不会成立，所以这是一个无效输入，直接输出拓扑排序为空

*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegress;

        // 建图
        for (auto& word : words) {
            for (auto& ch : word) {
                if (!graph.count(ch)) {
                    graph[ch] = {};
                }
                if (!inDegress.count(ch)) {
                    inDegress[ch] = 0;
                }
            }
        }

        // 计算邻接表和入度
        for (int i = 1; i < words.size(); ++i) {
            int j = 0;
            int len = min(words[i - 1].size(), words[i].size());
            for (; j < len; ++j) {
                char ch1 = words[i - 1][j];
                char ch2 = words[i][j];
                if (ch1 != ch2) {
                    if (!graph[ch1].count(ch2)) {
                        graph[ch1].insert(ch2);
                        inDegress[ch2]++;
                    }
                    break;
                }
            }
            // 特殊判断
            if (j == len && words[i - 1].size() > words[i].size()) {
                return {};
            }
        }

        string res;
        queue<char> q;

        // 入度为 0 的点
        for (auto& d : inDegress) {
            if (d.second == 0) {
                q.push(d.first);
            }
        }
        // BFS
        while (q.size()) {
            char ch = q.front();
            q.pop();
            res.push_back(ch);

            for (auto& c : graph[ch]) {
                inDegress[c]--;
                if (inDegress[c] == 0) {
                    q.push(c);
                }
            }
        }

        if (res.size() != inDegress.size()) {
            return "";
        }
        return res;
    }
};