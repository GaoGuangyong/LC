/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// �ⷨһ��
// ���ݶ����������ĵݹ鶨��
// ����ö���������������Ϊ�գ��������������нڵ��ֵ��С�����ĸ��ڵ��ֵ
// ����ö������ĵ����������գ��������������нڵ��ֵ���������ĸ��ڵ��ֵ
// ������������ҲΪ����������

typedef long long LL;

class Solution {
public:
    // dfs �������ж϶����� root �ǲ��Ƕ��������������ж� root ��ֵ�Ƿ��� (min, max) ��Χ��
    bool dfs(TreeNode* root, LL min, LL max) {
        // �ݹ���ڣ�����������������Ƕ���������
        if (root == nullptr) return true;
        // �����ǰ�����ڵ��ֵ�ںϷ�������
        if (root->val <= min || root->val >= max) return false;

        // �ݹ��ж�
        // root ������ӵ�ֵ�Ƿ��� (min, root->val) ��Χ
        bool l = dfs(root->left, min, root->val);
        // root ���Ҷ��ӵ�ֵ�Ƿ��� (root->val, max) ��Χ
        bool r = dfs(root->right, root->val, max);

        return l  && r; // ֻ�������� �� ���������ǣ�root ����
    }

    // �ж��� root Ϊ���ڵ�����Ƿ�Ϊ����������
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};

// ��ע�Ͱ汾
typedef long long LL;

class Solution {
public:
    bool dfs(TreeNode* root, LL min, LL max) {
        if (root == nullptr) return true;
        if (root->val >= max || root->val <= min) return false;

        bool l = dfs(root->left, min, root->val);
        bool r = dfs(root->right, root->val, max);

        return l && r;
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);        
    }
};


// �ⷨ����
// ���ݶ��������������ʣ�һ�����Ƕ������������͵ȼ���������������ǵ�����
// ������������󡢸����ң�����¼һ�����һ�α������Ľڵ㣬��һ���������Ľڵ�һ��Ҫ�ϸ������������

class Solution {
public:
    TreeNode* pre = nullptr; // ��¼����������е�ǰ������ʼʱָ���

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true; // ���У��������Ƕ���������
        // ��
        if (isValidBST(root->left) == false) return false;
        if (pre != nullptr && root->val <= pre->val) return false; // ���ǰ�����ڣ��ҵ�ǰ�ڵ��ֵ <= ǰ�������Ƕ���������
        pre = root;
        if (isValidBST(root->right) == false) return false;

        return true;
    }
};

