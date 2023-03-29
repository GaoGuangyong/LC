// 将字典 dictionary 中的词根 root 插入前缀树中；
// 依次枚举 sentence 中的单词，在前缀树中查找
// https://leetcode.cn/problems/replace-words/solution/-by-yexx-my6r/

class Solution {
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

    
    // 向前缀树中插入字符串 word
    void insert(string word) {
        Node* p = root; // 从根节点开始
        // 遍历字符串的所有字符
        for (char c: word) {
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

    // 如果字符串 word 的某个前缀在前缀树中，则返回这个前缀（词根）
    string search(string word) {
        Node* p = root; // 从根节点开始
        string res = ""; // 用于返回搜索到的单词，如果搜索失败，则返回空字符串 ""

        // 遍历字符串的所有字符
        for (char c: word) {
            // 如果当前字符是单词结尾。则返回这个单词
            if (p->is_end == true) return res;
            // 求当前字符的编号 idx（是第几个 son 节点） 
            int idx = c - 'a'; 
            // 如果 p 不存在 son[idx] 这个孩子，则代表搜索失败，返回空字符串
            if (p->son[idx] == nullptr) {
                return "";
            }
            // 如果 p 存在 son[idx] 这个孩子，则把当前字符加入 res
            res += c;
            p = p->son[idx]; // p 指向当前字符
        }
        // 循环结束后，p 指向的就是 word 的某个前缀的最后一个字母，res 中存的就是从根节点到 p 指向节点的单词（也就是这个前缀）
        // 例如：前缀树中有前缀 app，而要搜索的 word 是 apple，则 search("apple") --> 返回 "app"
        return res;
    }

    // 该函数将句子 sentence 中的所有继承词用词根数组 dictionary 中的词根替换掉
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new Node();
        // 遍历字典中的所有词根，插入前缀树
        for (string s: dictionary) insert(s)

        // 读取字符串 sentence 中空格分开的单词到 ssin
        string res;
        stringstream ssin(sentence);

        // 从 ssin 中读入字符串到 word
        string word;
        while (ssin >> word) { 
            // 先到前缀树中搜索当前读入的单词的前缀（词根）   
            string prefix = search(word); 
            // 如果当前读入的单词在前缀树中找不到对应的前缀，则原封不动的加入到结果字符串 res 中
            if (prefix == "") res += word + ' ';
            // 如果当前读入的单词在前缀树中能找到对应的前缀（词根），则将这个前缀（词根）加入到 res 中（相当于用词根替换了单词）
            else res += prefix + ' ';
        }
        // 因为最后会从 ssin 中读入一个空串，所以 res 会 += ' '，需要删掉这个空格
        res.pop_back(); // 弹出最后多余的一个空格
        return res;
    }
};



// 简化注释版本
class Solution {
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

    // 如果字符串 word 的某个前缀在前缀树中，则返回这个前缀（词根）
    string search(string word) {
        Node* p = root; 
        string res = ""; // 用于返回搜索到的单词，如果搜索失败，则返回空字符串 ""

        for (char c: word) {
            // 如果当前字符是单词结尾。则返回这个单词
            if (p->is_end == true) return res;
            
            int idx = c - 'a'; 
            if (p->son[idx] == nullptr)
                return "";
            // 如果 p 存在 son[idx] 这个孩子，则把当前字符加入 res
            res += c;
            p = p->son[idx];
        }
        return res;
    }

    // 该函数将句子 sentence 中的所有继承词用词根数组 dictionary 中的词根替换掉
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new Node();
        // 遍历字典中的所有词根，插入前缀树
        for (string s: dictionary) insert(s);

        // 读取字符串 sentence 中空格分开的单词到 ssin
        string res;
        stringstream ssin(sentence);

        // 从 ssin 中读入字符串到 word
        string word;
        while (ssin >> word) { 
             // 先到前缀树中搜索当前读入的单词的前缀（词根）   
            string prefix = search(word); 
            // 如果当前读入的单词在前缀树中找不到对应的前缀，则原封不动的加入到结果字符串 res 中
            if (prefix == "") res += word + ' ';
            // 如果当前读入的单词在前缀树中能找到对应的前缀（词根），则将这个前缀（词根）加入到 res 中（相当于用词根替换了单词）
            else res += prefix + ' ';
        }

        res.pop_back(); 
        return res;
    }
};
