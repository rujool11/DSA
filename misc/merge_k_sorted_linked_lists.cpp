// Leetcode 23. merge k sorted linked lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        }; // comparator for pq

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);


        for (auto it: lists) {
            if (it != nullptr)
                pq.push(it);
        }

        ListNode* head = new ListNode();
        ListNode* temp = head;


        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            if (node->next) pq.push(node->next);

            temp->next = node;
            temp = temp->next;

        }

        return head->next;
    }
};