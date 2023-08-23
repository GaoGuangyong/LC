/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Codec {
public:
    // ------------------------------------------------------【1】序列化
    string path; // 序列
    
    // DFS 函数：将二叉树 root 以先序遍历的方式序列化为字符串
    void dfs_serialize(TreeNode* root) {
        // 递归出口：如果遍历到空节点，则加上 "#," 作为标记
        if (root == nullptr) path += "#,";
        // 否则，如果遍历到数字，则加上 ”数字,“ 作为标记，然后递归左右子树
        else {
            path += to_string(root->val) + ',';
            dfs_serialize(root->left);
            dfs_serialize(root->right);
        }
    }

    // 主函数
    string serialize(TreeNode* root) {
        dfs_serialize(root); // 递归遍历根节点
        return path;
    }

    // ------------------------------------------------------【2】反序列化
    int u; // 从下标 u 开始反序列化
    
    // DFS 函数
    TreeNode* dfs_deserialize(string& data, int _u) {
        u = _u;
        
        // 递归出口：如果当前字符是 '#'，则代表遍历到了空节点
        if (data[u] == '#') {
            u += 2; // 跳过当前节点（即跳过 '#' 和 ',' ）
            return nullptr; // 返回空
        }
        // 如果当前字符不是 '#'，则代表遍历到了非空节点
        else {
            // 先计算出当前非空节点的值
            int k = u;
            while (data[u] != ',') u ++ ; // 如果数字有多位 比如1356，需要 u 一直走到逗号，也就是 6 右边的 ','
            TreeNode* root = new TreeNode(stoi(data.substr(k, u - k)));
            u ++ ; // 获取完 root 后，令 u 移动到 ',' 的下一个位置

            // 再递归反序列化 根节点 的左右子树
            root->left = dfs_deserialize(data, u);
            root->right = dfs_deserialize(data, u);
            return root;
        }
    }

    // 主函数
    TreeNode* deserialize(string data) {
        return dfs_deserialize(data, 0);
    }
};


// 二刷
class Codec {
public:
    // 序列化
    string path;

    void dfs_serialize(TreeNode* root) {
        if (root == nullptr) path += "#,";
        else {
            path += to_string(root->val) + ',';
            dfs_serialize(root->left);
            dfs_serialize(root->right);
        }
    }

    string serialize(TreeNode* root) {
        dfs_serialize(root);
        return path;
    }

    // 反序列化
    int u;
    
    TreeNode* dfs_deserialize(string& data, int _u) {
        u = _u;
        if (data[u] == '#') {
            u += 2;
            return NULL;
        }
        else {
            int k = u;
            while (data[u] != ',') u ++ ;
            TreeNode* root = new TreeNode(stoi(data.substr(k, u - k)));
            u ++ ;

            root->left = dfs_deserialize(data, u);
            root->right = dfs_deserialize(data, u);
            return root;
        }
    }

    TreeNode* deserialize(string data) {
        return dfs_deserialize(data, 0);
    }
};
