
// 先将数组转化成带有环的链表，具体转化方式见笔记
// 采用快慢指针解法：参考 LeetCode 142题 环形链表 II
// 重复数字就是链表中环的起始节点

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 初始时，快慢指针都指向链表的头
        int slow = 0, fast = 0;

        while (true) {
            slow = nums[slow]; // 每次慢指针走一步
            fast = nums[nums[fast]]; // 每次快指针走两步

            // 当快慢指针第一次相遇时
            if (slow == fast) {
                fast = 0; // 将快/慢指针重新指向链表的头

                // 随后，快慢指针一起向后走
                while (slow != fast) { // 当快慢指针不相遇时循环
                    slow = nums[slow]; // 每次慢指针走一步
                    fast = nums[fast]; // 每次快指针走一步
                }
                // 当快慢指针第二次相遇时，指向的就是重复的数
                return fast; // 返回快/慢指针
            }
        }
    }
};

// 无注释版本
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                fast = 0;
                while (slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return fast;
            }
        }
        
    }
};