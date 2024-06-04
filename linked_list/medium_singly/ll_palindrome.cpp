// Leetcode 234. Palindrome Linked List

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
            ListNode* front = temp->next; 
            temp->next = prev; 
            prev = temp; 
            temp = front; 
        }

        return prev; 
    }

    bool isPalindrome(ListNode* head) {
        // need to match first half with second half

        // S1: recognize second half -> slow and fast pointers, stop when fast reaches second last node (since we need first middle here)
        // S2: reverse second half
        // S3: again take 2 ptrs, first to head and second to new head of reversed list second half
        // S4: check palindrome, and reverse again before returning ans so list is not changed

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while (second!=nullptr){
            if (first->val != second->val) {
                reverseList(newHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverseList(newHead);
        // reverseList called before returning so that list is not changed
        return true;

    }
};