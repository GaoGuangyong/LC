
// 和 LC 62 类似，只不过构建的前缀树是以 0，1 为节点的
// 在前缀树中找到与当前数字 x 异或结果值最大的 数字 的方法：见笔记图示
// 从高位到低位，依次在前缀树中遍历，每次尽量走到与当前位不同的分支（x 的当前位是 0，则 1 分支走）
// 这样可以使找到的数字 与 当前数字 x 在当前位的异或结果为 1，从而得到更大的结果 

class Solution {
public:
    // 定义前缀树结构体
    struct Node {
        Node* son[2]; // 每个节点有 2 个孩子节点 // 0 -> son[0] , 1 -> son[1]
        // 构造函数
        Node() {
            // 将所有孩子节点初始化为空
            for (int i = 0; i < 2; i ++ ) son[i] = nullptr;
        }
    } *root; // 因为每个操作都需要从根节点开始向下，所以定义一个指向 Node 结构体的指针 root，相当于全局变量

    // 将数字 x 以二进制表示的形式插入前缀树
    void insert(int x) {
        Node* p = root; // 从根节点开始
        // 从 x 的二进制表示的最高位开始
        for (int i = 30; i >= 0; i -- ) {
            // 获取 x 的二进制表示的第 i 位数字
            int idx = x >> i & 1; 
            // 如果 p 不存在 son[idx] 这个孩子，就需要创建出来
            if (p->son[idx] == nullptr) {
                p->son[idx] = new Node();
            }
            // p 指向当前字符
            p = p->son[idx];
        }
    }

    // 如果数字 x 的二进制表示在前缀树中存在，则返回较大的异或结果
    int search(int x) {
        Node* p = root; // 从根节点开始
        int res = 0;
        // 从 x 的二进制表示的最高位开始
        for (int i = 30; i >= 0; i -- ) {
            // 获取 x 的二进制表示的第 i 位数字
            int idx = x >> i & 1; 
            // 如果 !idx 存在，则把 res 的 i 位置为 1，然后 p 往 !idx 走
            if (p->son[!idx] != nullptr) {
                res += 1 << i;
                p = p->son[!idx]; 
            } 
            // 如果 !idx 不存在，则走到 idx
            else p = p->son[idx];
        }
        return res;
    }

    // 主函数
    int findMaximumXOR(vector<int>& nums) {
        // 初始化根节点
        root = new Node();
        // 将数组的第一个数插入前缀树中
        insert(nums[0]);
        
        int res = 0;

        // 依次枚举数组中的元素 x，在前缀树中找与它异或结果最大的数，并不断更新 res
        for (int x: nums) {
            res = max(res, search(x));
            insert(x);
        }
        
        return res;
    }
};



// 简化注释版本
class Solution {
public:
    // 定义前缀树结构体
    struct Node {
        Node* son[2];

        Node() {
            for (int i = 0; i < 2; i ++ ) son[i] = nullptr;
        }
    } *root;

    // 将数字 x 以二进制表示的形式插入前缀树
    void insert(int x) {
        Node* p = root; 
        
        for (int i = 30; i >= 0; i -- ) {
            int idx = x >> i & 1; 
            if (p->son[idx] == nullptr) {
                p->son[idx] = new Node();
            }
            p = p->son[idx];
        }
    }

    // 如果数字 x 的二进制表示在前缀树中存在，则返回较大的异或结果
    int search(int x) {
        Node* p = root;
        int res = 0;
        for (int i = 30; i >= 0; i -- ) {
            int idx = x >> i & 1; 
            
            if (p->son[!idx] != nullptr) {
                res += 1 << i;
                p = p->son[!idx]; 
            } 
            else p = p->son[idx];
        }
        return res;
    }

    // 主函数
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        insert(nums[0]);
        
        int res = 0;

        for (int x: nums) {
            res = max(res, search(x));
            insert(x);
        }
        
        return res;
    }
};

