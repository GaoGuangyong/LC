

// д��һ����ϣ��
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;
 
int main() {
    string s;
    while (cin >> s) {
        // ����һ����ϣ����ÿ����ĸ���ֵĴ���
        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); i ++ ) hash[s[i]] ++ ;

        // ������ϣ��ȷ�����ִ�������Сֵ minCnt �Ƕ���
        int minCnt = 21; // ��ʼʱ�������ֵ
        for (auto [k, v]: hash) {
            minCnt = min(minCnt, v);
        }

        // �����ַ����������г��ִ��� > minCnt ���ַ����
        for (int i = 0; i < s.size(); i ++ ) {
            if (hash[s[i]] > minCnt) cout << s[i];
        }
        cout << endl;
    }
    return 0;
}


// д������������ʵ�ֹ�ϣ��
int main() {
    string s;
    while(cin >> s){
        vector<int> count(26, 0); // ��¼��ĸ���ֵĴ���
        for (int i = 0; i < s.size(); i ++ ) // �����ַ���
            count[s[i] - 'a'] ++ ; // ͳ��ÿ����ĸ���ֵĴ���
        int min = count[s[0] - 'a']; // �Ե�һ�����ֵ��ַ�Ϊʼ
        for (int i = 0; i < 26; i ++ )
            if (min > count[i] && count[i] > 0) // һ��Ҫ�ҵ���С������ 0 �Ĵ���
                min = count[i];
        for (int i = 0; i < s.size(); i ++ ) // ������г��ִ������� min ���ַ�
            if (count[s[i] - 'a'] > min)
                cout << s[i];
        cout << endl;
    }
    return 0;
}

