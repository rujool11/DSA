// Leetcode 19. Remove Nth node from end of linked list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // to have 2 pointers such that one is at end, and other at 
        // Nth from last, so have a gap of N

        ListNode* slow = head;
        ListNode* fast = head;

        for (int i=0;i<n;i++) fast = fast->next;
        if (fast == nullptr) return head->next; // edge case where list has exactly n nodes, and head must be deleted

        while (fast->next!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        return head;

    }
};