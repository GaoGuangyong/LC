
// �ⷨһ
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x != 0 || y != 0) { // �� x �� y ��Ϊ 0 ��ʱ��
            // �ֱ�ȡ�� x �ĸ�λ�� y �ĸ�λ�������������ͬΪ0����ͬΪ1����������߲�ͬ������� + 1
            res += (x & 1) ^ (y & 1); 

            // �� x �� y ������һλ
            x >>= 1;  
            y >>= 1;
        }
        return res;
    }
};

// �ⷨһ��ע�Ͱ汾
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;

        while (x != 0 || y != 0) {
            res += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
        }

        return res;
    }
};


// �ⷨ�����Ƽ���
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        // ���� x �� y �Ķ����Ʊ�ʾ��ÿһλ
        for (int i = 0; i < 32; i ++ ) {
            // ��� x �Ķ����Ʊ�ʾ�ĵ� i λ �� y �Ķ����Ʊ�ʾ�ĵ� i λ �����
            if ((x >> i & 1) != (y >> i & 1)) 
                res ++ ;
        }

        return res;
    }
};

// �ⷨ����ע�Ͱ汾
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;

        for (int i = 0; i < 32; i ++ ) {
            if ((x >> i & 1) != (y >> i & 1)) 
                res ++ ;
        }

        return res;
    }
};

