// https://www.acwing.com/solution/content/65097/
// https://www.acwing.com/video/2784/
class Trie {
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
    Trie() {
        root = new Node();
    }

    // 向前缀树中插入字符串 word
    void insert(string word) {
        Node* p = root; // 从根节点开始
        // 遍历字符串的所有字符
        for (char c: word) {
            // 求当前字符的编号 idx
            int idx = c - 'a'; 
            // 如果 p 不存在 son[idx] 这个孩子，就需要创建出来
            if (p->son[idx] == nullptr) 
                p->son[idx] = new Node(); 
            // p 指向当前字符
            p = p->son[idx]; 
        }
        p->is_end = true; // 将 p 的结尾标记 修改为 true，代表有以 p 为结尾的单词 word
    }

    // 在前缀树中搜索字符串 word，返回 true/false
    bool search(string word) {
        Node* p = root; // 从根节点开始
        // 遍历字符串的所有字符
        for (char c: word) {
            int idx = c - 'a';
            // 如果 p 不存在 son[idx] 这个孩子，则代表搜索失败
            if (p->son[idx] == nullptr) 
                return false;
            // p 指向当前字符
            p = p->son[idx];
        }
        // 循环结束后，p指向的就是word的最后一个字符节点，如果 p->is_end 是 true，就代表查找成功
        return p->is_end; 
    }

    // 如果 prefix 为某个字符串的前缀，则返回 true
    bool startsWith(string prefix) {
        Node* p = root; // 从根节点开始
        // 遍历前缀的所有字符
        for (char c: prefix) {
            int idx = c - 'a';
            // 如果 p 不存在 son[idx] 这个孩子，则这个 字符串prefix 肯定不是 word 的前缀
            if (p->son[idx] == nullptr) 
                return false;
            // p 指向当前字符
            p = p->son[idx];
        }
        // 只要 p 能走完prefix这条路径，即只要这条路径存在，就一定是 word 的前缀
        return true;
    }
};


// 简化注释版本
class Trie {
public:
    // 定义前缀树的结构体
    struct Node {
        Node* son[26];
        bool is_end;

        Node() {
            for (int i = 0; i < 26; i ++ ) son[i] = nullptr;
            is_end = false;
        }
    } *root;

    // 初始化前缀树
    Trie() {
        root = new Node();
    }
    
    // 向前缀树中插入字符串 word
    void insert(string word) {
        Node* p = root;
        for (char c: word) {
            int idx = c - 'a';
            // 如果 p 不存在 son[idx] 这个孩子，就需要创建出来
            if (p->son[idx] == nullptr) {
                p->son[idx] = new Node();
            }
            p = p->son[idx];
        }
        p->is_end = true;
    }
    
    // 在前缀树中查找字符串 word，返回 true/false
    bool search(string word) {
        Node* p = root;
        for (char c: word) {
            int idx = c - 'a';
            // 如果 p 不存在 son[idx] 这个孩子，则代表查找失败
            if (p->son[idx] == nullptr) {
                return false;
            }
            p = p->son[idx];
        }
        return p->is_end;
    }
    
    // 如果字符串 prefix 为某个字符串的前缀，则返回 true
    bool startsWith(string prefix) {
        Node* p = root;
        for (char c: prefix) {
            int idx = c - 'a';
            // 如果 p 不存在 son[idx] 这个孩子，则字符串 prefix 不是任何字符串的前缀
            if (p->son[idx] == nullptr) {
                return false;
            }
            p = p->son[idx];
        }
        return true;
    }
};