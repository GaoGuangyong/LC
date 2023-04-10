

// 输入：6 2 1 2 3 2 5 1 4 5 7 2 2
//  6 2 [1 2] [3 2] [5 1] [4 5] [7 2] 2 
//       1     3     5     4     7   是要加入的节点

// 共 6 个节点，头节点是 2，要删除的节点是 2
// 链表：2 7 3 1 5 4
// 删除：7 3 1 5 4

// 解法一：单链表
#include <iostream>
using namespace std;

// 链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} 
};

int main() {
    // 读入节点数 n，头节点值 x 
    int n, x;
    cin >> n >> x;
    // 创建头节点
    ListNode* head = new ListNode(x); 
    // 实现剩余 n - 1 个节点
    for (int i = 0; i < n - 1; i ++ ) {
        // 读入当前创建的节点 cur 及其前驱节点 pre
        int cur, pre;
        cin >> cur >> pre;
        ListNode* p = new ListNode(cur); // 创建节点 p，指向当前创建的节点
        
        // 从头节点向后遍历，找到前驱节点 pre
        ListNode* q = head;
        while (q->val != pre) q = q->next;
        
        // 将当前创建的节点 cur 插入到其前驱 pre 后面
        p->next = q->next;
        q->next = p;
    }

    // 读入要删除的节点
    int remove;
    cin >> remove;
    
    // 从头节点开始遍历，不输出 remove，其他的都输出
    for (ListNode* p = head; p != nullptr; p = p->next ) {
        if (p->val != remove) 
            cout << p->val << " ";
    }
    
    return 0;
}


// 解法二：数组模拟，考察数组的 find、erase insert 函数

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main() {
    vector<int> nums; // 用数组模拟链表
    // 读入节点数 n，头节点值 head 
    int n, head;
    cin >> n >> head;
    
    nums.push_back(head); // 将头节点加入 nums 数组

    // 实现剩余 n - 1 个节点
    for (int i = 0; i < n - 1; i ++ ) {
        // 读入当前创建的节点 cur 及其前驱节点 pre
        int cur, pre;
        cin >> cur >> pre; 
        // 在 nums 数组中找到前驱节点的下标
        auto it = find(nums.begin(), nums.end(), pre); 
        // 如果 it 指向 nums.end()，则在结尾 push_back
        if (it == nums.end()) nums.push_back(cur); 
        // 否则，在 it + 1 处插入当前节点
        else nums.insert(it + 1, cur);
    }

    // 读入要删除的节点
    int remove;
    cin >> remove;

    // 在 nums 中找到 remove 然后删掉它
    nums.erase(find(nums.begin(), nums.end(), remove));

    // 遍历 nums，输出所有的数    
    for (int x: nums) cout << x << " ";
    
    return 0;
}

 