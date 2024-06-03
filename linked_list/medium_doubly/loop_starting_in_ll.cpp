// Leetcode 142. Linked List cycle II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // method 1 - put all nodes in hashmap, and return node that is already in map
        // method 2 - Floyds cycle detection, (fast and slow ptr) : we have implemented method 2 here

        // S1: Find loop : slow and fast collide
        // S2: Keep fast at collision point, and slow at head
        // S3: move both by 1 simultaneously
        // S4: point where they re-collide is starting point of loop

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if (slow==fast) {
                slow = head;
                
                while (slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};