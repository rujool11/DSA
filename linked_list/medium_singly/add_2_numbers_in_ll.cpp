// Leetcode 2. Add 2 numbers


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* newHead = new ListNode(-1);
        ListNode* curr = newHead;
        int carry = 0;
        int data = 0;

        while (t1!=nullptr || t2!=nullptr){
            data = carry;
            if (t1) data += t1->val;
            if (t2) data += t2->val;
            curr->next = new ListNode(data%10);
            curr = curr->next;
            carry = data/10;

            if (t1) t1 = t1->next;
            if (t2) t2 = t2->next;
        }

        if (carry){
            curr->next = new ListNode(carry);
        }

        return newHead->next;
    }
};