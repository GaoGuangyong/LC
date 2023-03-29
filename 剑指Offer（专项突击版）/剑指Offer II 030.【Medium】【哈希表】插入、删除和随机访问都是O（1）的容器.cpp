

class RandomizedSet {
public:
    vector<int> nums; // 定义一个数组
    unordered_map<int, int> hash; // 定义一个哈希表，存数组中的元素及其下标
    
    RandomizedSet() {
        
    }
    
    // O(1) 时间插入：每次把要插入的数字 val 放到数组尾部
    bool insert(int val) {
        // 当哈希表中不存在 val 时，将其插入数组，更新哈希表，返回 true
        if (!hash.count(val)) {
            //【1】将 val 插入 nums 数组尾部
            nums.push_back(val);
            //【2】更新哈希表（添加键值对）
            hash[val] = nums.size() - 1;  // 记录 val 的下标，假设插入后数组下标为 [0, 1, 2, 3, 4] ，可以发现元素对应的下标就是 nums.size() - 1
            return true;
        }
        // 否则，若 val 已存在，则返回 false
        return false;
    }

    // O(1) 时间删除：每次把要删除的数字 val 交换到数组尾部，然后再从数组中删除
    bool remove(int val) { 
        // 当哈希表中存在 val 时，将最后一个数的下标改为 val 的下标，交换 val 和最后一个数，删除此时的最后一个数，更新哈希表，返回 true
        if (hash.count(val)) {
            int idx = hash[val]; // 先拿到要删除的数 val 的下标
            hash[nums.back()] = idx; // 再将数组的最后一个数的下标改为要删除的数 val 的下标
            swap(nums[idx], nums.back()); // 交换要删除的数 val 和 数组的最后一个数

            //【1】在数组中删除数字 val，即只需删除数组尾部的元素 
            nums.pop_back();
            //【2】更新哈希表（删除键值对）
            hash.erase(val);
            return true; 
        }
        // 否则，不存在，则无法删除, 返回 false
        return false;
    }
    
    int getRandom() {
        // 随机获取 nums 中的一个元素
        return nums[rand() % nums.size()];
    }
};



// 无注释版本

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> hash;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (!hash.count(val)) {
            nums.push_back(val);
            hash[val] = nums.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (hash.count(val)) {
            int idx = hash[val];
            hash[nums.back()] = idx;
            swap(nums[idx], nums.back());

            nums.pop_back();
            hash.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
