// Leetcode 206. Reverse Linked List
// Iterative solution

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
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp!=nullptr){
            ListNode* front = temp->next; // store next node so it doesnt get lost
            temp->next = prev; // reverse linkage
            prev = temp; // current node will be prev for next node
            temp = front; // move on to reversing the next node
        }

        return prev; // prev will be the last node of linked list, that should be returned as new head
    }
};