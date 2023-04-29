#include<bits/stdc++.h>
using namespace std;
void topo(unordered_map<int,vector<int>> &g,vector<int> &vis,stack<int> &st,int s,int n){

    for(auto i:g[s]){
        if(!vis[i]){
            vis[i]=1;
            topo(g,vis,st,i,n);
        }
    }
    st.push(s);
}
void topoSort(vector<pair<int,int>> &p,int n,int e){
    unordered_map<int,vector<int>> g;
    for(auto i:p){
        g[i.first].push_back(i.second);
    }
    for(auto i:g){
        cout<<i.first<<":";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vector<int> vis(n,0);
    stack<int> st;
    topo(g,vis,st,0,n);
    for(auto i:g){
        if(!vis[i.first]){
            topo(g,vis,st,i.first,n);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    cout<<"Enter the number of nodes: ";
    int n,e;
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;

    vector<pair<int,int>> p;
    cout<<"Enter the edges:";
    while(e--){
        int u,v;
        cin>>u>>v;
        p.push_back({u,v});
    }
    topoSort(p,n,p.size());
}
