// 模拟
// 根据题意：我们需要快速的知道 arr1 中的数在 arr2 中的位置
// 因此定义一个哈希表，来记录 arr2 中的元素及其下标

// 哈希表有个性质，就是没出现在哈希表中的元素的值为 0

// 技巧：对于在 arr2 中出现的数，令其值 < 0 且保持相对位置不变（i - arr2.size()）
// 这样一来，在 arr2 中没出现的数的值（0）> 出现的数的值（< 0），因此会被排在后面

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 定义一个哈希表，存 arr2 中的元素及其下标（按照相对位置存成负值）
        unordered_map<int, int> hash;
        for (int i = 0; i < arr2.size(); i ++ ) {
            hash[arr2[i]] = i - arr2.size(); // 注意这个技巧
        }

        // 自定义排序规则
        auto cmp = [&](int a, int b) {
            // 如果 a 和 b 在 arr2 中都存在的话（值都为 0），则按照哈希值排序
            if (hash[a] != hash[b]) return hash[a] < hash[b];
            // 否则，按照数值升序排序
            return a < b;
        };

        // 对数组 arr1 按照自定义规则进行排序
        sort(arr1.begin(), arr1.end(), cmp);

        return arr1;
    }
};



// 无注释版本
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> hash;
        for (int i = 0; i < arr2.size(); i ++ ) {
            hash[arr2[i]] = i - arr2.size();
        }

        auto cmp = [&](int a, int b) {
            if (hash[a] != hash[b]) 
                return hash[a] < hash[b];
            return a < b;
        };

        sort(arr1.begin(), arr1.end(), cmp);

        return arr1;
    }
};

