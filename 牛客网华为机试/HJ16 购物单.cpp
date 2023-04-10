

// AcWing 487 ������Ԥ�㷽��
// ���鱳��
// https://www.acwing.com/solution/content/3803/
// https://www.acwing.com/solution/content/55745/
// ���Խ�ÿ���������丽������һ����Ʒ�飬������Ϊ p����������Ϊ a,b�������һ����4����ϣ�
// p
// p,a
// p,b
// p,a,b
// ����������ǻ���ģ����ֻ�ܴ���ѡһ�֣���˿��Խ�ÿ����Ͽ���һ����Ʒ����ô����ͱ���˷��鱳������

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> PII;

const int N = 70; // ����д�� const !!!
const int M = 32010;

PII master[N]; // ��������
vector<PII> servent[N]; // ��������

int f[N][M]; // f[i][j] ��ʾ��ǰ i ����Ʒ��ѡ������������� j ��ѡ���У���ֵ�����ֵ

int main() {
    // ������Ʒ�� n ��Ǯ�� m
    int n, m;
    cin >> m >> n;
    // ���� n ����Ʒ
    for (int i = 1; i <= n; i ++ ) {
        // ������Ʒ�۸� v����Ҫ�� p��1 ~ 5������Ʒ���� q��0��������> 0��������ţ�
        int v, p, q;
        cin >> v >> p >> q;
        // ������������������������ {�������ֵ}
        if (q == 0) master[i] = {v, v * p};
        // ����Ǹ���������븽������ {�������ֵ}
        else servent[q].push_back({v, v * p});
    }

    // ö����Ʒ�� n
    for (int i = 1; i <= n; i ++ ) {
        // ��������
        for (int j = 0; j <= m; j ++ ) {
            f[i][j] = f[i - 1][j]; // ���ǲ�ѡ�����

            for (int k = 0; k < (1 << servent[i].size()); k ++ ) {
                int v = master[i].first; // ��� v
                int w = master[i].second; // ��ֵ w

                for (int t = 0; t < servent[i].size(); t ++ ) {
                    if ((k >> t) & 1 != 0) { // ���ѡȡ������ i �ĸ��������еĵ� t ����Ʒ
                        v += servent[i][t].first;
                        w += servent[i][t].second;
                    }
                }
                if (j >= v)     
                    f[i][j] = max(f[i][j], f[i - 1][j - v] + w);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
