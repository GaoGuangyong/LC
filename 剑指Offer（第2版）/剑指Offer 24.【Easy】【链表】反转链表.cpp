/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ģ���⣺����
// ��ͼ���

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        auto a = head; // ��ǰ�ڵ�
        auto b = a->next; // ��ǰ�ڵ�ĺ��

        while (b != nullptr) {
            auto c = b->next;
            b->next = a; // ��ת�Ĳ���ֻ����һ��
            a = b;
            b = c;
        }
        head->next = nullptr;
        return a;
    }
};

// ��ע�Ͱ汾
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        auto a = head;
        auto b = head->next;

        while (b != nullptr) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }

        head->next = nullptr;

        return a;
    }
};




// �ⷨ�����ݹ�
// �ȿ��� reverseList ��������ʲô�������Է�תһ�������������������ͷ�ڵ㣬Ҳ����ԭ�����β�ڵ㡣
// ���ǿ����ȵݹ鴦�� reverseList(head->next)���������ǿ��Խ���head->nextΪͷ�ڵ������ת�����õ�ԭ�����β�ڵ�tail
// ��ʱhead->next���������β�ڵ㣬����������nextָ��ָ��head������head->nextָ��ռ��ɽ���������ת�����������ͷ�ڵ���tail��

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ����
        if (!head || !head->next) return head;
        
        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};
