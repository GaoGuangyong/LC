
// ���� DP
// ����DP����ö�����䳤�ȣ���С����ö�٣���ö����㣬�Ӷ�ȷ���յ㣬���������յ��״̬ת��

// ״̬��ʾ��
// f[i][j] ��ʾ������ [i + 1 ~ j - 1] �����������ܻ��Ӳ�ҵ�������������Ϊ f[0][n + 1]
// �������Է�ֹ���������������

// ״̬ת�ƣ�
// �� k Ϊ [i + 1 ~ j - 1] ���������һ�����򣬴�ʱ i��j ��ŵ�����δ�����
// �൱���Ȱ� [i + 1 ~ k - 1] ������ٰ� [k + 1 ~ j - 1] ���������ٴ�� k
// f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // ����һ�� a ������������a[1] ~ a[n] �� nums[0] ~ nums[n-1]�����ߴ� 1
        vector<int> a(n + 2, 1);
        for (int i = 1; i <= n; i ++ ) {
            a[i] = nums[i - 1];
        }

        // ����״̬����
        vector<vector<int>> f(n + 2, vector<int>(n + 2));

        // ö�����䳤��
        for (int len = 3; len <= n + 2; len ++ ) { // ���䳤������Ϊ 3
            // ö���������
            for (int i = 0; i + len - 1 <= n + 1; i ++ ) {
                int j = i + len - 1; // ȷ�������յ�
                // ö���м��
                for (int k = i + 1; k <= j - 1; k ++ ) {
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
                }
            }
        }
        return f[0][n + 1];
    }
};

// ���� DP ģ��

// ����״̬����
vector<vector<int>> f(n + 2, vector<int>(n + 2));

// ö�����䳤��
for (int len = 1; len <= n; len ++ ) {
    // ö��������˵㣬�� 1 �� n
    for (int i = 1; i + len - 1 <= n; i ++ ) {
        // ���������Ҷ˵�
        int j = i + len - 1;
        f[i][j] = ��ʼֵ; // ������Ҫ��ȡ�ϴ�ֵ���Сֵ��Ҳ����û����һ��
        for (int k = i; k <= j; k ++ ) { // �������⣬ k <= j �� j - 1
            f[i][j] = ״̬���㷽��;
        }
    }
}

// ��ע�Ͱ汾
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> a(n + 2);
        a[0] = a[n + 1] = 1;
        for (int i = 1; i <= n; i ++ ) {
            a[i] = nums[i - 1];
        }

        vector<vector<int>> f(n + 2, vector<int>(n + 2));

        for (int len = 3; len <= n + 2; len ++ ) {
            for (int i = 0; i + len - 1 <= n + 1; i ++ ) {
                int j = i + len - 1;
                for (int k = i + 1; k <= j - 1; k ++ ) {
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[j] * a[k]);
                }
            }
        }

        return f[0][n + 1];
    }
};
