// Leetcode 206. Reverse linked list
// Recursive solution
// revise solution once 

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
    ListNode* reverseList(ListNode* head) {

        if (head==nullptr || head->next==nullptr) return head;

        ListNode* newHead = reverseList(head->next); // new head will be the head of reversed linked list of next part
        ListNode* front = head->next; // front node stored
        front->next = head; //reverse linkage
        head->next = nullptr; // set next of head at nullptr, since this is now the last node

        return newHead;
    }
};