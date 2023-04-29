#include<iostream>
#include<queue>
#include<map>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    char name;
    int data;
    Node* left;
    Node* right;
    Node(char a,int b){
        name=a;
        data=b;
        left=NULL;
        right=NULL;
    }
};
void insert(Node **root,char x,int v){
    Node* n=new Node(x,v);

    if((*root)==NULL){
        (*root)=n;
        //cout<<(*root)->name;
        return;
    }

    queue<Node*> q;
    q.push((*root));
    q.push(NULL);
    while(!q.empty()){
        Node* p=q.front();

        q.pop();
        if(p==NULL){
            if(q.empty()) return;
            q.push(NULL);
            continue;
        }
        if(p->left==NULL){
            p->left=n;
            return;
        }else if(p->left!=NULL){
            q.push(p->left);
        }
        if(p->right==NULL){
            p->right=n;
            return;
        }else{
            q.push(p->right);
        }
    }
}
void print(Node** root){
    queue<Node*> q;
    q.push((*root));
    cout<<(*root)->name<<endl;
    q.push(NULL);
    while(!q.empty()){
        Node* p=q.front();
        q.pop();
        if(p==NULL){
            if(q.empty()) return;
            cout<<endl;
            q.push(NULL);
            continue;
        }
        if(p->left!=NULL){
            cout<<p->left->name;
            q.push(p->left);
        }
        if(p->right!=NULL){
            cout<<p->right->name;
            q.push(p->right);
        }
    }
}
void Goal_Path(Node** head,char j){
    map<int,Node*> m;
    if(*head==NULL) return;
    m.insert({(*head)->data,(*head)});
    unordered_map<char,char> p;
    p[(*head)->name]='0';
    auto i=m.begin();
    while(i!=m.end()){
        if(i->second->left!=NULL){
            p[i->second->left->name]=i->second->name;
            if(i->second->left->name==j) break;
            m.insert({i->second->left->data,i->second->left});
        }
        if(i->second->right!=NULL){
            p[i->second->right->name]=i->second->name;
            if(i->second->right->name==j) break;
            m.insert({i->second->right->data,i->second->right});
        }
        auto it=i;
        i++;
        m.erase(it);
    }
    char parent;
    vector<char> path;
    parent=j;
    while(parent!='0'){
        path.push_back(parent);
        parent=p[parent];
    }
    reverse(path.begin(),path.end());
    for(auto i:path){
        cout<<i<<" ";
    }
}
int main(){
    Node* root=NULL;
    char x='A';
    for(int i=0;i<100;i++)
    insert(&root,x+i,i);
    print(&root);
    Goal_Path(&root,'`');
}
