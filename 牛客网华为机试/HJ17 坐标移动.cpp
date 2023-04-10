#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    vector<string> move;

    for (int i = 0; i < s.size(); i ++ ) {
        string temp;
        // �������ַ���Ϊ ';' ʱѹ����ʱ�ַ��� temp
        while (s[i] != ';') {
            temp.push_back(s[i]);
            i ++ ;
        }
        // ���� ';' ʱ���ٰ���ʱ�ַ���ѹ���ַ������� move
        move.push_back(temp);
    }

    int x = 0, y = 0; // ���λ�� (0, 0)

    // ö�� move �ַ��������е�ÿ���ַ�������
    for (int i = 0; i < move.size(); i ++ ) {
        if (move[i].size() == 3 || move[i].size() == 2) {
            if (move[i][0] == 'A' || move[i][0] == 'D' || move[i][0] == 'W' || move[i][0] == 'S') {
                int num1 = move[i][1] - '0';
                if (move[i].size() == 2 && num1 >= 0 && num1 <= 9) {
                    if (move[i][0] == 'A') x = x - num1;
                    if (move[i][0] == 'D') x = x + num1;
                    if (move[i][0] == 'W') y = y + num1;
                    if (move[i][0] == 'S') y = y - num1;
                }
                int num2 = move[i][2] - '0';
                if (move[i].size() == 3 && num1 >= 0 && num1 <= 9 && num2 >= 0 && num2 <= 9) {
                    int num = 10 * num1 + num2;
                    if (move[i][0] == 'A') x = x - num;
                    if (move[i][0] == 'D') x = x + num;
                    if (move[i][0] == 'W') y = y + num;
                    if (move[i][0] == 'S') y = y - num;
                }
            }
        }
    }

    cout << x << "," << y << endl;
    return 0;
}

