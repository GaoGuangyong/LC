// ��������ɨ��
// �۲�����ͼ�Σ����Ƕ�ˮ������� �� ���в��
// ע�⵽��ÿ���������Ϸ����ܽ��ܵ�ˮ�ĸ߶ȣ������������ߵľ��Σ����ұ���ߵľ��ξ����ġ�
// ����أ������ i ���������ĸ߶�Ϊ height[i]���Ҿ����������ߵľ������ĸ߶�Ϊ left_max[i]���ұ���ߵľ������߶�Ϊ right_max[i]����þ������Ϸ��ܽ���ˮ�ĸ߶�Ϊ
// min(left_max[i], right_max[i]) - height[i]��
// ��Ҫ�ֱ��������ɨ���� left_max������������ right_max�����ͳ�ƴ𰸼��ɡ�
// ע������ n Ϊ 0

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left_max(n);
        vector<int> right_max(n);

        left_max[0] = height[0]; // ��ʼʱ�������ߵľ������ĸ߶�Ϊ��һ���������ĸ߶�
        right_max[n - 1] = height[n - 1]; // ��ʼʱ���Ҳ���ߵľ������ĸ߶�Ϊ���һ���������ĸ߶�


        // ��һ��ɨ�裬�ӵڶ�����ʼ�����ÿ�������� i ������߾������ĸ߶� left_max[i]
        for (int i = 1; i < n; i ++ ) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        // �ڶ���ɨ�裬�ӵ����ڶ�����ʼ�����ÿ�������� i �Ҳ����߾������ĸ߶� right_max[i]
        for (int i = n - 2; i >= 0; i -- ) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int res = 0;

        // ������ɨ�裬���ÿ�������� i �Ϸ��ܴ���ˮ�����ֵ min(left_max[i], right_max[i]) - height[i]
        for (int i = 0; i < n; i ++ ) {
            res += min(left_max[i], right_max[i]) - height[i];
        }

        return res;
    }
};


// ��ע�Ͱ汾
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left_max(n);
        vector<int> right_max(n);

        left_max[0] = height[0];
        right_max[n - 1] = height[n - 1];

        for (int i = 1; i < n; i ++ ) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i -- ) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int res = 0;

        for (int i = 0; i < n; i ++ ) {
            res += min(left_max[i], right_max[i]) - height[i];
        }

        return res;
    }
};


