// 模拟：按 '.' 分开，再按字典序进行比较


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size(); // 获取版本1的长度
        int n = version2.size(); // 获取版本2的长度

        // 使用两个指针 i 和 j 分别在版本 1 和版本 2 中遍历版本号
        for (int i = 0, j = 0; i < m || j < n; ) {
            int a = i; // 用 a 遍历版本 1
            int b = j; // 记录版本 2 中当前点号之前的位置

            // 在版本 1 中找到下一个点号或者到达版本 1 的末尾
            while (a < m && version1[a] != '.') a ++ ; // 循环结束时，a 指向 '.' 或结尾，数字就是 version1[i ~ a - 1]

            // 在版本 2 中找到下一个点号或者到达版本 2 的末尾
            while (b < n && version2[b] != '.') b ++ ; // 循环结束时，b 指向 '.' 或结尾，数字就是 version2[i ~ b - 1]
            
            int num1;
            int num2;
            // 截取版本 1 中的子字符串并将其转换为整数 num1，如果当前位置 a 等于 i，则说明没有子字符串，将 num1 设为 0
            if (a == i) num1 = 0; 
            else num1 = stoi(version1.substr(i, a - i)); // 注：使用 stoi() 可以自动去除前导 0

            // 截取版本 2 中的子字符串并将其转换为整数 num2，如果当前位置 b 等于 j，则说明没有子字符串，将 num2 设为 0
            if (b == j) num2 = 0;
            else num2 = stoi(version2.substr(j ,b - j)); // 注：使用 stoi() 可以自动去除前导 0

            // 比较 num1 和 num2 的大小
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
            
            // 如果 num1 和 num2 相等，则继续比较下一个子版本号，更新 i 和 j 指针
            i = a + 1; // i 指向 a + 1，即下一个数字的开头
            j = b + 1; // j 指向 b + 1，即下一个数字的开头
        }

        // 如果所有子版本号都相等，则版本号相同，返回 0
        return 0;
    }
};




