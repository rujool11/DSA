// Geeks for Geeks flatten linked list

//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* merge(Node* root1, Node* root2){
    Node* dummy = new Node(-1);
    Node* ans = dummy;
    Node* temp1 = root1;
    Node* temp2 = root2;
    
    while (temp1!=nullptr && temp2!=nullptr){
        if (temp1->data < temp2->data){
            ans->bottom = temp1;
            ans = temp1;
            temp1 = temp1->bottom;
        }
        else {
            ans->bottom = temp2;
            ans = temp2;
            temp2 = temp2->bottom;
        }
        
        ans->next = nullptr;
    }
    
    if (temp1) ans->bottom = temp1;
    if (temp2) ans->bottom = temp2;
    
    if (dummy->bottom) dummy->next = nullptr;
    return dummy->bottom;
}

Node *flatten(Node *root)
{
    // Maive soultions: traverse all, put into array, and copy to linked list
    // S(n) = O(nxm), but we need to do in linear space
    
    if (root==nullptr || root->next==nullptr) return root;
    
    Node* mergedRoot = flatten(root->next); // use merge to keep combining 2 sub-lists
    return merge(root, mergedRoot);
}

