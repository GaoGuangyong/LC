// https://leetcode.cn/problems/Jf1JuT/solution/jian-zhi-offer-2-mian-shi-ti-114-shu-zho-8itg/
/*
��������
���ַ��� s1 ���ַ��� s2 ��������ʱ�������ߵ�����ĸ��ʼ��λ�Աȣ��ȳ��ֽ�С����ĸ�ĵ���������ǰ����ֱ������һ������������ĸ���Ա��궼�޷��ó�������򳤶Ƚ�С�ĵ���������ǰ��
����Ŀ�� words = ["ac","ab","bc","zc","zb"] Ϊ����һ�������� 'a'��'b'��'c' �� 'z' 4 ����ĸ
���� "ac" < "ab" ���� 'c' < 'b'������ "ab" < "bc" ���� 'a' < 'b'�����οɵ� 'b' < 'z' ��'c' < 'b'��

������Ҫ�ҳ��ĸ���ĸ֮��Ĺ�ϵ��ʹ�����������Ĺ�ϵ������ʹ��������������
���԰�ÿ����ĸ����ͼ�Ľڵ㣬����֪������ĸ֮��Ĵ�С��ϵ����ôͼ�оʹ���һ���ӽ�С����ĸָ��ϴ���ĸ�ıߡ�
�������ܸ�������ͼ�������������У���ô����һ���ߵ���ʼ�ڵ㣨��С����ĸ��һ����������ֹ�ڵ㣨�ϴ����ĸ����ǰ�档

�����������£�
ʹ��һ����ϣ�� graph ��������ڵ���ڽӱ�
ʹ��һ����ϣ�� inDegress ��ʾ���ڵ�����
���ȱ������е��ʵ���ĸ��������ϣ������ʼ�����������Ƚϵ����б����������ڵĵ��ʣ���ͷ��ʼ�ҵ���һ������ͬ����ĸ����ͼ�����һ���ӽ�С��ĸָ��ϴ���ĸ�ı�
������Ҫע��һ���������룬�����ߵ�ǰ׺��ͬ����ǰ�ߵĵ��ʳ��ȳ��ں��ߣ��� "abc" �� "ab"�����ǲ������������ģ����������ĸ������ô�����������򶼲����������������һ����Ч���룬ֱ�������������Ϊ��

*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegress;

        // ��ͼ
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

        // �����ڽӱ�����
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
            // �����ж�
            if (j == len && words[i - 1].size() > words[i].size()) {
                return {};
            }
        }

        string res;
        queue<char> q;

        // ���Ϊ 0 �ĵ�
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