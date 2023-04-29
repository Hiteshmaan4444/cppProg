#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
bool bfsTrav(unordered_map<int,list<int>> &adj,unordered_map<int,int> &visited,unordered_map<int,int> &parent,int start){
    queue<int> q;
        visited[start]=1;
        q.push(start);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto j:adj[x]){
                if(visited[j]==0){
                    visited[j]=1;
                    parent[j]=x;
                    q.push(j);
                }else if (parent[x]!=j){
                    return true;
                }
            }
        }
        return false;
}
void bfs(vector<pair<int,int>> &edges,int n){
    unordered_map<int,list<int>> adj;
    for(auto i:edges){
        int u=i.first;
        int v=i.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,int> visited;
    unordered_map<int,int> parent;
    if(bfsTrav(adj,visited,parent,1)){
        cout<<"cycle exist";
    }else{
        cout<<"cycle doesn't exist";
    }
}
int main(){
    vector<pair<int,int>> edges;
    cout<<"Enter the number of edges: ";
    int n;
    cin>>n;
    cout<<"Enter the edges:(u,v)\n";
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    bfs(edges,n);
    return 0;
}
