// Leetcode 61. Rotate List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* findNthNode(ListNode* head, int x){
        int count = 1;
        ListNode* temp = head;
        while (temp!=nullptr){
            if (count == x) return temp;
            count++;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k){
        if (head==nullptr || head->next==nullptr) return head;

        int len = 1;
        ListNode* tail = head;

        while (tail->next!=nullptr){
            tail = tail->next;
            len++;
        }

        if (k%len == 0) return head;

        k = k%len;

        tail->next = head;
        ListNode* newTail = findNthNode(head, len - k);
        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};