

// �ݹ�

// ���ɣ�
// A && B; // �� A Ϊ false���� B ����ִ�У�ֻ�� A Ϊ true��B �Ż�ִ��
// A || B; // �� A Ϊ true���� B ����ִ�У�ֻ�� A Ϊ false��B �Ż�ִ��

// ʹ�ø����Կ���ȥ�� if ���

// (n > 0) && (res += x); // <=> if (n > 0) res += x;

class Solution {
public:
    int sumNums(int n) {
        // �� n ��ʼ�� 1 �ۼӣ�
        int res = n; 

        // ֻ�� n > 0 ����ʱ���Ż�ִ�к�������
        (n > 0) && (res += sumNums(n - 1)); 
        
        return res;
    }
};


