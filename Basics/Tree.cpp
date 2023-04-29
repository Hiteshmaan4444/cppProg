#include<iostream>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
struct node{
    node(){
        x=0;
        left=NULL;
        right=NULL;
    }
    node(int t){
        x=t;
        left=NULL;
        right=NULL;
    }
    int x;
    struct node* left;
    struct node* right;
};
void insert(struct node** head,int x){
    struct node *p= new node(x);
    if((*head)==NULL){
        (*head)=p;
    }else{
        if((*head)->x>x){
            insert(&(*head)->left,x);
        }else{
            insert(&(*head)->right,x);
        }
    }
}
void post(node **head){
    if(*head!=NULL){
        cout<<(*head)->x<<" ";
        post(&(*head)->left);
        post(&(*head)->right);
    }
}
void inorder(struct node** head){
    queue<struct node*> q;
    if((*head)!=NULL){
        q.push((*head));
        q.push(NULL);
    }else{
        cout<<"Tree is empty\n";
    }
    while(!q.empty()){
        struct node *p=q.front();
        q.pop();
        if(p!=NULL){
            cout<<p->x<<" ";;
            if(p->left!=NULL)
            q.push(p->left);
            if(p->right!=NULL)
            q.push(p->right);
        }else{
            cout<<"\n";

            if(!q.empty())
            q.push(NULL);
        }
    }
}
void mapIns(unordered_map<struct node*,int> &m,struct node** head,int count){
    if((*head)!=NULL){
        m.insert({*head,count});
        if((*head)->left!=NULL){
            mapIns(m,&(*head)->left,count-1);
        }
        if((*head)->right!=NULL){
            mapIns(m,&(*head)->right,count+1);
        }
    }
}
void vertTrav(struct node** head){
    unordered_map<struct node*,int> m;
    map<int,vector<int>> ver;
     mapIns(m,&(*head),0);
     for(auto i:m){
        ver[i.second].push_back(i.first->x);
     }
     for(auto i:ver){
        for(auto j:i.second){
            cout<<i.first<<":"<<j<<" ";
        }
     }
}
int main(){
    struct node *head=NULL;
    insert(&head,10);
    insert(&head,5);
    insert(&head,8);
    insert(&head,2);
    insert(&head,20);
    //post(&head);
    //inorder(&head);
    vertTrav(&head);
    return 0;
}
