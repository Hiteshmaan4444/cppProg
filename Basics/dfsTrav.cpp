#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
void dfsTrav(unordered_map<int,list<int>> &adj,unordered_map<int,int> &visited,int start){
    visited[start]=1;
    cout<<start<<" ";

    for(auto i: adj[start]){
        if(!visited[i]){
            dfsTrav(adj,visited,i);
        }
    }
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
    dfsTrav(adj,visited,1);
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
