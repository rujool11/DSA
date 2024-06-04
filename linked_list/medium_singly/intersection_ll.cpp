// Leetcode 160. Intersection of two linked lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // naive: traverse one, and put all nodes in map
        // traverse second, check if node in map

        // no extra space solution->
        // find difference in length d
        // make larger one move by d
        // simultaneous movement, and check of nodes equal

        
        // our solution --> 
        // traverse both ll together with temp1 and temp2
        // when any one reaches null, take it to head of other linked list
        // keep moving, when other reaches end, move it to head of first one
        // (basically, when any temp reaches null, move to opposite head)
        // take them together, and eventually you will reach the node where intersection starts

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1!=temp2){ // first head is collision point if no intersection
            temp1 = temp1->next;
            temp2 = temp2->next;

            if (temp1==temp2) return temp1;

            if (temp1==nullptr) temp1 = headB;
            if (temp2==nullptr) temp2 = headA;
        } 

        return temp1;
    }
};