//{ Driver Code Starts
// driver code
// Geeks for Geeks Find length of Loop

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.

int findLength(Node* slow, Node* fast){
    
    int count = 1;
    fast = fast->next;
    
    while (slow!=fast){
        fast = fast->next;
        count++;
    }
    
    return count;
}

int countNodesinLoop(struct Node *head)
{
    // naive solution: keep a timer, put all elements in map
    // when node found that already is in map, return timer - value, value = m[node], m is map
    // map: {node, timer} : timer is the time/counter of each step
    
    // slow and fast pointer solution -->
    // S1: loop if two pointers meet
    // S2: if we start at intersection point, meet again at intersection point, use this to find length
    
    if (head==nullptr || head->next==nullptr) return 0;
    
    Node* slow = head;
    Node* fast = head;
    
    
    while (fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        
        if (fast==slow) {
            return findLength(slow, fast);
        }
        
    }
    
    return 0;
    
    
}