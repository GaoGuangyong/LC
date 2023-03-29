// 前缀树，参考剑指OfferII 062 的写法，https://leetcode.cn/problems/QC3q1f/

class MagicDictionary {
public:
    // 定义前缀树的结构体
    struct Node {
        Node *son[26]; // 每个节点有 26 个孩子节点 // 即：a -> son[0] , b -> son[1] ......
        bool is_end; // 结尾标记，判断是否有以该节点结尾的单词
        // 构造函数（初始化）
        Node() {
            // 将所有孩子节点初始化为空，
            for (int i = 0; i < 26; i ++ )
                son[i] = nullptr;
            is_end = false; // 结尾标记为 false，代表目前没有以该节点为结尾的单词
        }
    } *root; // 因为每个操作都需要从根节点开始向下，所以定义一个指向 Node 结构体的指针 root，相当于全局变量

    // 初始化前缀树
    MagicDictionary() {
        root = new Node();
    }

    // 向前缀树中插入字符串数组 dictionart 中的每个单词 word （本质就是 剑指OfferII 062 的 insert 函数）
    void buildDict(vector<string> dictionary) {
        // 遍历字符串数组 dictionary，将其中的所有字符串 word 插入前缀树中
        for (string word: dictionary) {
            Node* p = root; // 从根节点开始
            // 遍历字符串的所有字符
            for (char c : word) {
                // 求当前字符的编号 idx（是第几个 son 节点）
                int idx = c - 'a';
                // 如果 p 不存在 son[idx] 这个孩子，就需要创建出来
                if (p->son[idx] == nullptr) {
                    p->son[idx] = new Node();
                }
                // p 指向当前字符
                p = p->son[idx]; 
            }
            p->is_end = true; // 将 p 的结尾标记 修改为 true，代表有以 p 为结尾的单词 word
        }
    }

    // 判断：只将字符串 searchWord 的一个字母换成另一个字母，能否和前缀树中的任何一个字符串匹配
    bool search(string searchWord) {
        // 字符串：searchWord, 从前缀树的根节点开始遍历, 从字符串的下标 0 开始比较, 当前有 0 个不同的字符
        return dfs(searchWord, root, 0, 0);
    }

    // 递归函数：判断给定的字符串 s 能否在前缀树中找到一个仅有 1 个字符不同的字符串
    // s: 需要比较的字符串
    // p: 当前在前缀树中遍历到的节点
    // u: 当前要比较的字符串 s 的下标
    // c: 字符串 s 与前缀树中遍历到的字符串相比较，有几个不同的字符
    bool dfs(string s, Node* p, int u, int c) {
        // 递归出口：如果在缀树中遍历到了结尾的字符 && 在字符串 s 中比较到了最后一个字符 && 只有 1 个不同的字符 -> true
        if (p->is_end == true && u == s.size() && c == 1) return true;
        // 递归出口：如果已经比较到了 s 的最后一个字符 || 不同的字符数超过 1 个 -> false
        if (u == s.size() || c > 1) return false;

        // 枚举当前节点的 26 个儿子
        for (int i = 0; i < 26; i ++ ) {
            // 如果当前节点没有 son[i] 这个儿子，则继续找下一个儿子 son[i ++ ] 
            if (p->son[i] == nullptr) continue;

            // 如果当前节点有 son[i] 这个儿子，则递归比较
            // 判断一下，当前的字符 s[u] 和当前遍历到的第 i 个儿子节点 son[i] 是否相同
            bool check;
            // 不同: 则不同的字符数量 c + 1
            if (s[u] - 'a' != i) check = dfs(s, p->son[i], u + 1, c + 1);
            // 相同: 则不同的字符数量 c 不变
            else check = dfs(s, p->son[i], u + 1, c);

            // 如果当前沿着当前分支走，check == true（即存在只有一个字母不同的字符串），则返回 true
            if (check == true)
                return true;
        }
        // 如果都找不到答案，则返回 false
        return false;
    }
};



// 简化注释版本
class MagicDictionary {
public:
    // 定义前缀树的结构体
    struct Node {
        Node *son[26];
        bool is_end;

        Node() {
            for (int i = 0; i < 26; i ++ ) son[i] = nullptr;
            is_end = false;
        }
    } *root;

    // 初始化前缀树
    MagicDictionary() {
        root = new Node();
    }

    // 向前缀树中插入字符串数组 dictionart 中的每个单词 word
    void buildDict(vector<string> dictionary) {
        // 遍历字符串数组 dictionary，将其中的所有字符串 word 插入前缀树中
        for (string word: dictionary) {
            Node* p = root;
            for (char c : word) {
                int idx = c - 'a';
                if (p->son[idx] == nullptr) {
                    p->son[idx] = new Node();
                }
                p = p->son[idx]; 
            }
            p->is_end = true;
        }
    }

    // 判断：只将字符串 searchWord 的一个字母换成另一个字母，能否和前缀树中的任何一个字符串匹配
    bool search(string searchWord) {
        return dfs(searchWord, root, 0, 0);
    }

    // 递归函数：判断给定的字符串 s 能否在前缀树中找到一个仅有 1 个字符不同的字符串
    // s: 需要比较的字符串
    // p: 当前在前缀树中遍历到的节点
    // u: 当前要比较的字符串 s 的下标
    // c: 字符串 s 与前缀树中遍历到的字符串相比较，有几个不同的字符
    bool dfs(string s, Node* p, int u, int c) {
        if (p->is_end == true && u == s.size() && c == 1) return true;
        if (u == s.size() || c > 1) return false;

        for (int i = 0; i < 26; i ++ ) {
            if (p->son[i] == nullptr) continue;

            bool check;

            if (s[u] - 'a' != i) check = dfs(s, p->son[i], u + 1, c + 1);
            else check = dfs(s, p->son[i], u + 1, c);

            if (check == true)
                return true;
        }
        
        return false;
    }
};


