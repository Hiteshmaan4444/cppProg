//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;

    Node* head = new Node(val);
    Node* tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
/*1
2
9 9
2
9 9*/
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
     Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        /* reverse the rest list and put
          the first element at the end */
        Node* rest = reverse(head->next);
        head->next->next = head;

        /* tricky step -- see the diagram */
        head->next = NULL;

        /* fix the head pointer */
        return rest;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* head3=new Node(0),*n=head3;
        stack<int> s1,s2;
        while(first!=NULL){
            s1.push(first->data);
            first=first->next;
        }
        while(second!=NULL){
            s2.push(second->data);
            second=second->next;
        }
        int carr=0;
        while(!s1.empty()&&!s2.empty()){
            int sum=s1.top()+s2.top()+carr;
            s1.pop();
            s2.pop();
            carr=sum/10;
            n->next=new Node(sum%10);
             n=n->next;
        }
        while(!s1.empty()){
            int sum=s1.top()+carr;
            s1.pop();
            carr=sum/10;
            n->next=new Node(sum%10);
             n=n->next;
        }
        while(!s2.empty()){
            int sum=s2.top()+carr;
            s2.pop();
            carr=sum/10;
            n->next=new Node(sum%10);
            n=n->next;
        }
        while(carr) {n->next=new Node(carr%10); carr=carr/10;}
        head3=head3->next;
        //printList(head3);
        Node* root,*prev=NULL;

        return reverse(head3);;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;

        cin>>n;
        Node* first = buildList(n);

        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
