// https://www.acwing.com/solution/content/63191/

// 双链表
// 题目要求 O(1) 时间实现增删改查 --> 哈希表 hash
// 每次访问 hash 中的某个 key，需要将这个元素变为最新使用的，也就是说 hash 要支持在 O(1) 的时间获取最久使用的 key --> 双链表


// 双向链表节点，每一个节点 Node 都是键值对 <key, val>
class Node {
public: // 注意！不写成 public 的话，默认是 private，类外无法访问！二刷时犯了这个错！
    int key;
    int val;
    Node* prev;
    Node* next;

    // 构造函数 写法一（1）
    Node (int _key, int _val) {
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
    }

    // 构造函数 写法一（2）
    Node (int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }

    // 构造函数 写法二（推荐）
    Node(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {}

};

class LRUCache {
public:
    int capacity; // 双链表容量
    Node* head; // 双链表的头节点（最左侧节点）
    Node* tail; // 双链表的尾节点（最右侧节点）

    unordered_map<int, Node*> hash; // 定义一个哈希表：key -> 节点

    // 辅助函数：删除双链表的某个节点 node
    void remove(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    // 辅助函数：在双链表的表头插入节点：将 node 插入到 head 后
    void insert_after_head(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // ·························· 以容量 capacity 初始化双链表 ·························· // 
    LRUCache(int _capacity) {
        // 初始化容量，左右端点
        capacity = _capacity; // 初始化容量
        head = new Node(-1, -1); // 初始化双链表的左端点
        tail = new Node(-1, -1); // 初始化双链表的右端点

        // 一开始只有左右端点，令左端点的 next 指向右端点，令右端点的 prev 指向左端点
        head->next = tail;
        tail->prev = head;
    }

    // ························ 如果 key 存在于缓存中，则返回其 value，并将其放到表头 ························ // 
    int get(int key) {
        // 如果 key 不存在，返回 -1
        if (!hash.count(key)) return -1;
        // 如果 key 存在，先找到该节点 hash[key]，将其从双链表中删掉后插入到双链表的表头
        Node* node = hash[key]; // 从哈希表中找到该节点
        remove(node); // 从双链表中删除该节点
        insert_after_head(node); // 将该节点插入双链表的表头，即将其变成最新使用过的

        return node->val; // 返回 node 的值
    }

    // 如果 key 在缓存（队列）中，则改变其 value
    // 如果 key 不在缓存中，则加入缓存（插入队列）
    // 如果需要页面置换（页面（节点）数超出缓存（链表）容量 capacity），则删除最久未使用的页面（节点）
    void put(int key, int value) {
        // 如果 key 存在，则在链表中找到该节点 hash[key]，将其值修改为 value，然后将该节点删掉并插入到双链表的表头
        if (hash.count(key)) {
            auto node = hash[key];
            node->val = value;
            remove(node);
            insert_after_head(node);
        }
        // 如果 key 不存在，先判断链表容量是否已满。如果满了，则先找到尾结点，删掉尾结点并从哈希表中也删掉
        // 然后创建节点 <key, value>，插入哈希表，并插入到双链表的表头
        else {
            // 如果容量已满，先找到双链表的表尾节点 tail->prev，从双链表中删除该节点，并从哈希表中也删掉
            if (hash.size() == capacity) {
                auto node = tail->prev;
                remove(node);
                hash.erase(node->key);
            }
            // 此时，容量未满，先创建该节点，插入哈希表，并插入到双链表的表头
            auto node = new Node(key, value);
            hash[key] = node;
            insert_after_head(node);
        }
    }
};



// 简单注释版 -------------------------------------------------------------- //

// 双向链表节点，每一个节点 Node 都是键值对 <key, val>
class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    // 构造函数
    // Node (int _key, int _val) {
    //     key = _key;
    //     val = _val;
    //     prev = nullptr;
    //     next = nullptr;
    // }

    Node(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int capacity; // 双链表容量
    Node* head; // 双链表的头节点（最左侧节点）
    Node* tail; // 双链表的尾节点（最右侧节点）

    unordered_map<int, Node*> hash;

    // 删除双链表的某个节点
    void remove(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    // 在双链表的表头插入节点
    void insert_after_head(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // ·························· 初始化 LRU 缓存 ·························· // 
    LRUCache(int _capacity) {
        // 初始化容量，左右端点
        capacity = _capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // ························ 从缓存中得到数据 ························ // 
    int get(int key) {
        // 如果 key 不存在，返回 -1
        if (hash.count(key) == 0) return -1;
        // 如果 key 存在，先找到该节点 hash[key]，将其删掉，并插入到双链表的表头
        Node* node = hash[key];
        remove(node);
        insert_after_head(node);

        return node->val;
    }

    // ························ 向缓存中写入数据 ························ // 
    void put(int key, int value) {
        // 如果 key 存在，找到该节点 hash[key]，修改其值，将其删掉，并插入到双链表的表头
        if (hash.count(key)) {
            Node* node = hash[key];
            node->val = value;
            remove(node);
            insert_after_head(node);
        }
        // 如果 key 不存在，先创建该节点，插入哈希表，并插入到双链表的表头
        else {
            // 如果容量已满，先找到表头节点 tail->prev，按照 LRU 的方法删除该节点，并在哈希表中也删掉
            if (hash.size() == capacity) {
                Node* node = tail->prev;
                remove(node);
                hash.erase(node->key);
            }
            // 否则，如果容量未满，则创建该节点，插入哈希表，并插入到双链表的表头
            Node* node = new Node(key, value);
            hash[key] = node;
            insert_to_head(node);
        }
    }
};



// 注释框架：练习用 -------------------------------------------------------------- //

// 双向链表节点，每一个节点 Node 都是键值对 <key, val>
class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    // 构造函数 写法二
    Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    // 双链表容量
    // 双链表的头节点（最左侧节点）
    // 双链表的尾节点（最右侧节点）

    // 哈希表：key -> 节点

    // 辅助函数：删除双链表的某个节点 node
    void remove(Node* node) {
    }

    // 辅助函数：在双链表的表头插入节点：将 node 插入到 head 后
    void insert_after_head(Node* node) {
    }

    // ·························· 以容量 capacity 初始化 LRU 缓存 ·························· // 
    LRUCache(int _capacity) {
        // 初始化容量，左右端点

    }

    // ························ 如果 key 存在于缓存中，则返回其 value，并将其放到表头 ························ // 
    int get(int key) {
        // 如果 key 不存在，返回 -1
        
        // 如果 key 存在，先找到该节点 hash[key]，将其从双链表中删掉后插入到双链表的表头

        // 返回 node 的值
    }

    // ···················· 如果 key 在缓存中，则改变其 value ······························· // 
    // ···················· 如果 key 不在缓存中，则插入 <key, value> ························ // 
    // ···················· 如果插入后，超出 capacity，则删除最久未使用的 <key, val> ········· // 
    void put(int key, int value) {
        // 如果 key 存在，找到该节点 hash[key]，修改其值，将其删掉，并插入到双链表的表头

        // 如果 key 不存在，先创建该节点，插入哈希表，并插入到双链表的表头
        else {
            // 如果容量已满，先找到双链表的表尾节点 tail->prev，从双链表中删除该节点，并从哈希表中也删掉
            if (hash.size() == capacity) {

            }
            // 此时，容量未满，先创建该节点，插入哈希表，并插入到双链表的表头

        }
    }
};


// 二刷

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;

    unordered_map<int, Node*> hash;

    void remove(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void insert_after_head(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!hash.count(key)) return -1;
        
        auto node = hash[key];
        remove(node);
        insert_after_head(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (hash.count(key)) {
            auto node = hash[key];
            node->val = value;
            remove(node);
            insert_after_head(node);
        }
        else {
            if (hash.size() == capacity) {
                auto node = tail->prev;
                remove(node);
                hash.erase(node->key);
            }
            auto node = new Node(key, value);
            hash[key] = node;
            insert_after_head(node);
        }
    }
};