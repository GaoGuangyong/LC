

// DP
// ״̬��ʾ��
// f[i][j] ��ʾ�� word1[1 ~ i] ��� word2[1 ~ j] ���а�˳������ķ����������������Сֵ

// ��ʼ����
// ��ĳ���ַ����ĳ���Ϊ 0������Ҫ�����Ĵ���Ϊ��һ���ַ����ĳ���

// ״̬ת�ƣ�
// ���� word1 ���������
// ��ɾ��ɾ�� Word1[i] �� word1 �� word2 ��ȣ�˵��ɾ֮ǰ word1[1 ~ i - 1] �� word2[1 ~ j] �Ѿ������
//      f[i][j] = f[i - 1][j] + 1
// ���塿�� word1[i] ����� Word2[j] �� word1 �� word2 ��ȣ�˵������֮ǰ word1[1 ~ i] �� word2[1 ~ j - 1] �Ѿ������
//      f[i][j] = f[i][j - 1] + 1
// ���ġ��޸� Word1[i] �� word1 �� word2 ��ȣ�˵���޸�֮ǰ word1[1 ~ i - 1] �� word2[1 ~ j - 1] �Ѿ������
//      f[i][j] = f[i - 1][j - 1] + 1 (�� word1[i] != word2[j])
//      f[i][j] = f[i - 1][j - 1] + 0 (�� word1[i] == word2[j]������Ҫ�޸ģ��������� + 0)
// ���ս��Ϊ�����������ȡ min

// ͬ������ word2 Ҳ���������

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        word1 = ' ' + word1;
        word2 = ' ' + word2;

        // ����״̬����
        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        // ��ʼ������ĳ���ַ����ĳ���Ϊ 0������Ҫ�����Ĵ���Ϊ��һ���ַ����ĳ���
        for (int i = 0; i <= n; i ++ ) f[i][0] = i;
        for (int j = 0; j <= m; j ++ ) f[0][j] = j;

        // ״̬ת��
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                // ����ǰ�����������Сֵ
                f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
                // ��������һ���������Сֵ
                int t = 1;
                if (word1[i] == word2[j]) t = 0;
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + t);
            }
        }
        return f[n][m];
    }
};


// ��ע�Ͱ汾

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        word1 = " " + word1;
        word2 = " " + word2;

        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i ++ ) f[i][0] = i;
        for (int j = 1; j <= m; j ++ ) f[0][j] = j;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);

                if (word1[i] == word2[j]) 
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                else 
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);    
            }
        }

        return f[n][m];
    }
};
