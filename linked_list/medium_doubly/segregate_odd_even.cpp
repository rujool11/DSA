// Leetcode 328. Odd even linked list

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
    ListNode* oddEvenList(ListNode* head) {

        if (head==nullptr || head->next==nullptr) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenStart = head->next;

        // if even has not reached the end, odd will also not reach
        // since even is after odd
        while (even!=nullptr && even->next!=nullptr){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;

        }

        odd->next = evenStart;
        return head;
    }
};