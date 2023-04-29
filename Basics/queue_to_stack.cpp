#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
void qpush(queue<int> &q,int n){
    if(q.empty()){q.push(n);return;}
    int temp=q.front();
    q.pop();
    qpush(q,n);
    q.push(temp);
}
int qpop(queue<int> &q){
    if(q.empty()) return -1;
    if(q.size()==1){
        int res = q.front();
        q.pop();
        return res;
    }
    int temp=q.front();
    q.pop();
    int res= qpop(q);
    qpush(q,temp);
    return res;
}
int main(){
    queue<int> q;
    vector<int> v{1,16,1 ,78 ,2 ,1,13,1 ,93 ,2 ,2 ,1 ,28 ,1 ,60 ,2 ,1 ,41 ,1 ,73 ,1 ,12 ,1 ,68 ,2,2 ,1 ,31 ,1 ,24 ,2 ,2 ,2};
    for(int i=0;i<v.size();i++){
        if(v[i]==1){qpush(q,v[i+1]);  i++;}
        else{

            if(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
            }
            else
            cout<<-1<<" ";
        }
    }
}
