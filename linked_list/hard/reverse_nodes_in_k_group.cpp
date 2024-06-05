// Leetcode 25. Reverse nodes in k group

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
    void reverseList(ListNode* head){ // no return, just changes head
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp!=nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        head = prev;
    }

    ListNode* findKthNode(ListNode* head, int k){ // returns nullptr if out of bounds 
        int count = 1;
        ListNode* temp = head;
        while (temp!=nullptr){
            if (count==k) break;
            count++;
            temp = temp->next;
            if (temp==nullptr) break;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp!=nullptr){
            ListNode* kth = findKthNode(temp, k);
            if (kth==nullptr) { // means no group of k, set prevLast to temp and break loop since has to be ended
                if (prevLast) prevLast->next = temp; // no reversal since no exact k group
                break;
            }   

            ListNode* nn = kth->next; // preserve next node 
            kth->next = nullptr; // so that reverse can be called
            reverseList(temp); // now, kth is the start of ll, and temp is at the end (since reverse)
            
            if (temp==head) head = kth; // IMP: for first instance, i.e first k group, we need to update head, else no 
            else prevLast->next = kth; // connect the linked list to next part

            prevLast = temp; // now, the previous Last Node is set to temp, (after reversal!!)
            temp = nn; // temp is set to new node 
        }

        return head;
    }
};