#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
void bfsTrav(unordered_map<int,list<int>> &adj,unordered_map<int,int> &visited,int start){
    queue<int> q;
        visited[start]=1;
        q.push(start);
        while(!q.empty()){
            int x=q.front();
            cout<<q.front();
            q.pop();
            for(auto j:adj[x]){
                if(visited[j]==0){
                    visited[j]=1;
                    q.push(j);
                }
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
    bfsTrav(adj,visited,0);
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
