// https://leetcode.cn/problems/map-sum-pairs/solution/-by-yexx-3zad/

// 画图参考笔记
// 在每个节点中存两个值，sum 和 val ，sum 表示当前节点值得总和，val 表示到当前节点代表的单词的值；
// 例如 apple = 3, 则此时 a, p, p, l, e 这 5 个节点的 sum 都是 3；如果再插入 app = 2, 则此时 a,p,p 这 3 个节点值的 sum 变成 5
// 如果只是求总和，不替换新的键值对的话，我们只需在每个节点维护一个 sum ，给每个节点都加上 sum ；
// 如果要替换新的键值对的话，我们就需要知道这个单词的旧值 val ，所以在节点中还要维护一个 val ，只需在每个单词的结尾插入 val
// 往树中插入新单词时，先遍历找是否有上一个已经存在的该单词，并取出它的 val

class MapSum {
public:
    // 定义前缀树的结构体
    struct Node {
        Node* son[26]; // 每个节点有 26 个孩子节点 // 即：a -> son[0] , b -> son[1] ...
        int sum; // 当前节点的值
        int val; // 到当前节点为止的单词的值
        
        // 构造函数（初始化）
        Node() {
            sum = 0;
            val = 0;
            for (int i = 0; i < 26; i ++ ) son[i] = nullptr;
        }
    } *root;

    // 遍历前缀树，找单词 word 的值 val，如果 word 不存在，则 val = 0
    int search(string word) {
        Node* p = root; // 从根节点开始
        // 遍历字符串的所有字符
        for (char c: word) {
            // 求当前字符的编号 idx（是第几个 son 节点）
            int idx = c - 'a';
            // 如果 p 不存在 son[idx] 这个孩子，查找失败，返回 0
            if (p->son[idx] == nullptr) {
                return 0;
            }
            // p 指向当前字符
            p = p->son[idx]; 
        }
        // 循环结束后，p 指向的就是 word 的最后一个字符在前缀树的节点，即 p->val 就是该单词 word 的值
        return p->val;
    }

    // 初始化 MapSum 对象
    MapSum() {
        root = new Node();
    }

    // 向前缀树中插入单词 key 及其值 val，如果单词存在，则更新其值，并更新该单词路径上各节点的值
    void insert(string key, int val) {
        // 插入之前，先获取该单词的旧值 last
        int last = search(key);

        Node* p = root; // 从根节点开始
        // 遍历单词的所有字母
        for (char c: key) {
            // 求当前字符的编号 idx（是第几个 son 节点）
            int idx = c - 'a';
            // 如果 p 不存在 son[idx] 这个孩子，就需要创建出来
            if (p->son[idx] == nullptr) {
                p->son[idx] = new Node();
            }
            // p 指向当前字符
            p = p->son[idx]; 

            p->sum -= last; // 减去旧单词的 val
            p->sum += val; // 加上新单词的 val
        }
        p->val = val; // 保存 val
    }

    // 返回所有以该前缀 prefix 开头的单词 key 的值的总和，即 prefix 这个单词对应的 sum
    int sum(string prefix) {
        Node* p = root; // 从根节点开始
        // 遍历前缀的所有字符
        for (char c: prefix) {
            // 求当前字符的编号 idx（是第几个 son 节点）
            int idx = c - 'a';
            // 如果 p 不存在 son[idx] 这个孩子，则这个前缀不对应任何单词，返回 0
            if (p->son[idx] == nullptr) {
                return 0;
            }
            // p 指向当前字符
            p = p->son[idx]; 
        }
        return p->sum;
    }
};



// 简化注释版本
class MapSum {
public:
    // 定义前缀树的结构体
    struct Node {
        Node* son[26];
        int sum;
        int val;
        
        Node() {
            sum = 0;
            val = 0;
            for (int i = 0; i < 26; i ++ ) son[i] = nullptr;
        }
    } *root;

    // 遍历前缀树，找单词 word 的值 val，如果 word 不存在，则 val = 0
    int search(string word) {
        Node* p = root;
        for (char c: word) {
            int idx = c - 'a';
            if (p->son[idx] == nullptr) {
                return 0;
            }
            p = p->son[idx]; 
        }
        return p->val;
    }

    // 初始化 MapSum 对象
    MapSum() {
        root = new Node();
    }

    // 向前缀树中插入单词 key 及其值 val，如果单词存在，则更新其值，并更新该单词路径上各节点的值
    void insert(string key, int val) {
        int last = search(key);

        Node* p = root; 
        for (char c: key) {
            int idx = c - 'a';
            if (p->son[idx] == nullptr) {
                p->son[idx] = new Node();
            }
            p = p->son[idx]; 

            p->sum -= last;
            p->sum += val;
        }
        p->val = val;
    }

    // 返回所有以该前缀 prefix 开头的单词 key 的值的总和，即 prefix 这个单词对应的 sum
    int sum(string prefix) {
        Node* p = root;

        for (char c: prefix) {
            int idx = c - 'a';
            if (p->son[idx] == nullptr) {
                return 0;
            }
            p = p->son[idx]; 
        }
        return p->sum;
    }
};


