// Geeks for Geeks: Add 1 to number represented by linked list
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node* head){
        Node* prev = nullptr;
        Node* temp = head;
        
        while (temp!=nullptr){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        Node* newHead = reverse(head);
        Node* temp = newHead;
        
        while (temp->data+1 > 9 && temp->next!=nullptr){
            temp->data = 0;
            temp = temp->next;
        }
        
        if (temp->next == nullptr && temp->data+1>9) {
            temp->data = 0;
            temp->next = new Node(1);
            return reverse(newHead);
        }
        
        temp->data += 1;
        
        return reverse(newHead);
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends