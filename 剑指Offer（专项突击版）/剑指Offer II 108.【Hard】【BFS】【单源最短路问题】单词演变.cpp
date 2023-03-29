
// 单源最短路 BFS

// 题目翻译：
// 将单词看做点，如果两个单词可以相互转化，则在相应的点之间连一条无向边，那问题就变成了:
// 对于每条边的权值都相同（=1）的无向图，求从起点到终点的最短路径长度，直接从起点开始 bfs
// 考虑如何建图：枚举所有单词对，然后判断是否可以通过改变一个字母相互转化，可以转化就连一条边

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 定义哈希集合，存单词表中的所有单词
        unordered_set<string> S; 
        for (auto word: wordList) S.insert(word);
        
        // 定义哈希表 dist，存最短路径上的各个单词到起点单词的距离（边数）
        unordered_map<string, int> dist; 
        dist[beginWord] = 0; // 起点单词的距离为 0

        queue<string> q; // BFS 队列, 每个点都是一个 string 单词
        q.push(beginWord); // 将起点加入队列

        // BFS 过程
        while (q.size()) { // 当队列不空的时候，就不断将节点入队
            auto t = q.front(); // 获取队头元素：当前单词 t 
            q.pop(); // 队头元素出队

            // 枚举当前单词 t 的每一位 i
            for (int i = 0; i < t.size(); i ++ ) {
                string word = t; // 由于每次循环都会修改原单词，所以先保存原单词
                // 枚举单词的 i 位的所有可能字母 j
                for (char j = 'a'; j <= 'z'; j ++ ) {
                    word[i] = j; // 把单词的 i 位换成 j
                    // 如果当前位换成 j 后的单词在哈希集合中存在（说明该单词在 worldList 中存在，可以转化成这个单词）
                    // 且在哈希表中不存在（说明该单词还没被转换过，到起点单词的距离也就没计算过）
                    if (S.count(word) && !dist.count(word)) {
                        // 更新当前转换后的单词 word 到起点单词的距离：在 t 的基础上 +1
                        dist[word] = dist[t] + 1; 
                        // 如果当前已经转换到了终点单词，则输出答案
                        if (word == endWord) { 
                            return dist[word] + 1; // 因为求得是单词个数，所以是边数 + 1
                        }
                        q.push(word); // 将新搜到的单词入队
                    }
                }
            }
        }
        // 如果找不到答案则返回 0
        return 0; 
    }
};


// 无注释版本
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> S; 
        for (auto word: wordList) S.insert(word);
        
        unordered_map<string, int> dist; 
        dist[beginWord] = 0;

        queue<string> q; 
        q.push(beginWord);

        // BFS 过程
        while (q.size()) { 
            auto t = q.front();
            q.pop();

            for (int i = 0; i < t.size(); i ++ ) {
                string word = t;

                for (char j = 'a'; j <= 'z'; j ++ ) {
                    word[i] = j;
                    if (S.count(word) && !dist.count(word)) {
                        dist[word] = dist[t] + 1; 
                        if (word == endWord) { 
                            return dist[word] + 1; 
                        }
                        q.push(word); 
                    }
                }
            }
        }

        return 0; 
    }
};


