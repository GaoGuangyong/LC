

// 题意：
// 输入一个单向链表和一个节点的值，从单向链表中删除等于该值的节点，删除后如果链表中无节点则返回空指针
// 链表的值不能重复

// 输入：6 2 1 2 3 2 5 1 4 5 7 2 2
// 第一个参数 6 表示输入总共 6 个节点
// 第二个参数 2 表示头节点值为 2
// 剩下的 2 个一组表示第 2 个节点值后面插入第 1 个节点值，[1 2] 表示 2 后面插入 1
// 最后一个参数为 2，表示要删掉值为 2 的节点

//  6 2 [1 2] [3 2] [5 1] [4 5] [7 2] 2 
//    2                                  是头节点
//       1     3     5     4     7       是要加入的节点
//         2     2     1     5     2     是其前驱节点
//                                    2  是要删除的节点

// 共 6 个节点，头节点是 2，要删除的节点是 2
// 链表：2 7 3 1 5 4
// 删除：7 3 1 5 4

// 解法一：单链表（推荐，可以学习到单链表的各种操作）
#include <iostream>
using namespace std;

// 链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} 
};

int main() {
    // 读入节点数 n，头节点的值 x 
    int n, x;
    cin >> n >> x;

    // 创建头节点
    ListNode* head = new ListNode(x); 

    // 实现剩余 n - 1 个节点
    for (int i = 0; i < n - 1; i ++ ) {
        // 读入当前创建的节点的值 cur 及其前驱节点的值 pre
        int cur, pre;
        cin >> cur >> pre;
        ListNode* p = new ListNode(cur); // 创建节点 p，指向新创建的节点
        
        // 用 q 从头节点向后遍历，直到指向了前驱节点 pre
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


// 二刷
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

int main() {
    int n, x;
    cin >> n >> x;

    ListNode* head = new ListNode(x);

    for (int i = 0; i < n - 1; i ++ ) {
        int cur, pre;
        cin >> cur >> pre;

        ListNode* p = new ListNode(cur);

        ListNode* q = head;
        while (q->val != pre) q = q->next;

        p->next = q->next;
        q->next = p;        
    }
    
    int remove;
    cin >> remove;
    
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

 