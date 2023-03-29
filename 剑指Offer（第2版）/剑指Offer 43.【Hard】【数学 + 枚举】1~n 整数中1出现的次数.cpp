// 数学 + 枚举
// 见笔记

// _ _ x _ _ _  (x 左边两位数是 left, 右边三位数是 right)

// 举例：n = 13015
// 万位的 1：右边可以是 0000 ~ 3015（right）
// 千位的 1：左边 1 位是 0 ~ 0（left-1） 时，右边 3 位可以是 000 ~ 999 + 左边 1 位是 1（left） 且当前位 > 1，右边 3 位可以是 000 ~ 999
// 百位的 1：左边 2 位是 00 ~ 12（left-1） 时，右边 2 位可以是 00 ~ 99 + 左边 2 位是 13（left） 且当前位 == 0，故百位不可能取 1
// 十位的 1：左边 3 位是 000 ~ 129（left-1） 时，右边 1 位可以是 0 ~ 9 + 左边 3 位是 130（left） 且当前位 == 1，右边 1 位可以是 0 ~ 5（right）
// 个位的 1：左边可以是 0000 ~ 1301（right）

class Solution {
public:
    int countDigitOne(int n) {
        // 定义一个数组来存 n 的每一位，例如：n = 123456，则循环结束后：nums = [6, 5, 4, 3, 2, 1]
        vector<int> nums; 
        while (n != 0) {
            nums.push_back(n % 10); // 获取个位
            n /= 10; // 删掉个位
        }

        long long res = 0;

        // 从数组的最高位开始枚举，即从数字 n 的最左边的位开始枚举（ 注：数组[最低位 --- i --- 最高位] ）
        for (int i = nums.size() - 1; i >= 0; i -- ) {
            int left = 0; // 对于当前遍历的位置 i，left 就是其左边的数字
            int right = 0; // 对于当前遍历的位置 i，right 就是其右边的数字
            int t = 1; // t 就是 10^(right 的位数)，比如 right 是三位数，则 t = 10^3 = 1000

            // 求 left：从 nums.size() - 1 枚举到 i + 1
            for (int j = nums.size() - 1; j > i; j -- ) {
                left = left * 10 + nums[j];
            }

            // 求 right：从 i - 1 枚举到 0
            // 求 t：right 有几位数，就乘几个 10
            for (int j = i - 1; j >= 0; j -- ) {
                right = right * 10 + nums[j];
                t *= 10;
            }

            // 将分析的三种情况的方案数相加
            res += left * t; // 左边 2 位填 00 ~ left - 1 时，右边 3 位可以填 000 ~ 999，共 left * t 个
            if (nums[i] == 1) res += right + 1; // 左边两位数填 left 且当前位置 == 1 时，仅当当前位置填 1 时，右边三位数可以填 000 ~ right，共 right + 1 个
            else if (nums[i] > 1) res += t; // 左边两位填 left 时且当前位置 > 1 时，仅当当前位置填 1 时，右边三位可以填 000 ~ 999，共 t 个
        }
        return res;
    }
};


// 无注释版本

class Solution {
public:
    int countDigitOne(int n) {
        vector<int> nums; 
        while (n != 0) {
            nums.push_back(n % 10);
            n /= 10;
        }

        long long res = 0;

        for (int i = nums.size() - 1; i >= 0; i -- ) {
            int left = 0;
            int right = 0;
            int t = 1;

            for (int j = nums.size() - 1; j > i; j -- ) {
                left = left * 10 + nums[j];
            }

            for (int j = i - 1; j >= 0; j -- ) {
                right = right * 10 + nums[j];
                t *= 10;
            }

            res += left * t;
            if (nums[i] == 1) res += right + 1; 
            else if (nums[i] > 1) res += t;
        }
        return res;
    }
};
