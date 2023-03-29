
// ö��
// ����һ�����⣬����ÿ�������� 3 �Σ�������֮�󣬳��� 1 �ε����ֵ��±������������
// ��һ�֣�������ǰ�� {3��4��4��4��5��5��5}
// �ڶ��֣��������м� {3��3��3��4��5��5��5}
// �����֣���������� {3��3��3��4��4��4��5}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end()); // �ȶ������������

        if (n == 1) return nums[0]; // ���У����ֻ��һ������ֱ�ӷ��������

        // ������� 1 ����������� nums[0, 3, 6, 9 ... ]
        for (int i = 0; i < n; i += 3) {
            // ��������������һλ��˵���������һ�������������һ����
            if (i == n - 1) return nums[n - 1];

            // �����ǰ��������������������ͬ��������㣬��������������
            if (nums[i] == nums[i + 2]) continue; 
            
            // ���������ǰ������������������ͬ��������㣬����������Ǵ�
            else return nums[i];
        }

        return -1;
    }
};


// ��ע�Ͱ汾
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end()); 

        if (n == 1) return nums[0]; 

        for (int i = 0; i < n; i += 3) {
            if (i == n - 1) return nums[n - 1];

            if (nums[i] == nums[i + 2]) continue; 
            
            else return nums[i];
        }

        return -1;
    }
};

