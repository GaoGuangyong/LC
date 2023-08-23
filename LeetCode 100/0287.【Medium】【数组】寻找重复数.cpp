
// 先将数组转化成带有环的链表，具体转化方式见笔记
// 采用快慢指针解法：参考 LeetCode 142题 环形链表 II
// 重复数字就是链表中环的起始节点

// 写法一：不推荐
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 初始时，快慢指针都指向链表的头
        int slow = 0, fast = 0;

        while (true) {
            slow = nums[slow]; // 每次慢指针走一步
            fast = nums[nums[fast]]; // 每次快指针走两步

            // 当快慢指针第一次相遇时，将快（慢）指针重新指向链表的头
            if (slow == fast) {
                fast = 0;
                // 随后，快慢指针一起向后走
                while (slow != fast) { // 当快慢指针不相遇时循环
                    slow = nums[slow]; // 每次慢指针走一步
                    fast = nums[fast]; // 每次快指针走一步
                }
                // 当快慢指针第二次相遇时，快（慢）指针指向的就是重复的数
                
                return fast; // 返回快（慢）指针
            }
        }
    }
};


// 写法二：模仿 LC 142 (推荐)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // 初始时，快慢指针都指向链表的头
        int slow = 0;
        int fast = 0;

        while (fast != n && nums[fast] != n) {
            slow = nums[slow]; // 每次慢指针走一步
            fast = nums[nums[fast]]; // 每次快指针走两步
            if (fast == slow) break; // 当快慢指针相遇时，退出
        }

        fast = 0; // 当快慢指针第一次相遇时，将快（慢）指针重新指向链表的头
        
        // 随后，快慢指针一起向后走
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast; // 当快慢指针第二次相遇时，快（慢）指针指向的就是重复的数
    }
};


// 无注释版
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        int n = nums.size();

        while (fast != n && nums[fast] != n) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (fast == slow) break;
        }

        fast = 0;

        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};
