#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(int x){
        data=x;
        next=NULL;
    }
};
void insert(Node **head,Node** tail,int x){
    Node* n= new Node(x);
    if((*head)==NULL){
      (*head)=n;
      (*tail)=(*head);
      return;
    }
    Node* p=(*head);
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=n;
    (*tail)=n;
}
void print(Node** head){
    Node* p=(*head);
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
Node* mid_(Node** head,Node** tail){
    Node* p=(*head);
    Node* q=(*head);
    while(q!=(*tail)||q->next!=(*tail)){
        if(q==(*tail)||q->next==(*tail)){
            return p;
        }
        p=p->next;
        q=q->next->next;
    }
    return NULL;
}
void merge(Node** head,Node** mid,Node** tail){
    Node* r=new Node();
    Node* c=r;
    Node* p=(*head);
    Node* q=(*mid)->next;
    while(p!=(*mid)->next||q!=(*tail)->next){
        if(p==(*mid)->next||q==(*tail)->next) break;
        if(p->data<q->data){
            c->next=new Node(p->data);
            p=p->next;
        }else{
            c->next=new Node(q->data);
            q=q->next;
        }
        c=c->next;
    }
    while(p!=(*mid)->next){
        if(p==(*mid)->next){
            break;
        }
        c->next=new Node(p->data);
        p=p->next;
        c=c->next;
    }
    while(q!=(*tail)->next){
        if(q==(*tail)->next){
            break;
        }
        c->next=new Node(q->data);
        q=q->next;
        c=c->next;
    }
    p=(*head);
    r=r->next;
    c=r;
    while(c!=NULL){
        //cout<<c->data<<" ";
        p->data=c->data;
        p=p->next;
        c=c->next;
    }
}
void mergeSort(Node** head,Node** tail){
    Node* mid=mid_(head,tail);
    if((*tail)!=mid){
        mergeSort(head,&mid);
        mergeSort(&mid->next,tail);
        merge(head,&mid,tail);
    }
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;

    for(int i=10;i>0;i-=2)
    insert(&head,&tail,i);
    insert(&head,&tail,0);
    print(&head);
    cout<<"\n";
    mergeSort(&head,&tail);
    print(&head);
    return 0;
}
