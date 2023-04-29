#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,q;
    cin>>n>>k>>q;
    int count=0;

    vector<vector<int>> qu;
    int i=0;
    int j=0;
    int mx=0;

    while(n--){
        cin>>i>>j;
        mx=max(mx,j);
        qu.push_back({i,j});
    }
    vector<int> v(mx+1,0);
    vector<int> res(mx+1,0);
    for(auto i:qu){
        v[i[0]]++;
        v[(i[1])+1]--;
    }
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];
        if(v[i]==k){
            res[i]=res[i-1]+1;
        }else{
            res[i]=res[i-1];
        }
    }
    while(q--){
        cin>>i>>j;
        if(i>mx&&j>mx) cout<<0<<endl;
        else if(j>mx){
            cout<<res[mx]-res[i-1]<<endl;
        }else{
            cout<<res[j]-res[i-1]<<endl;
        }
    }
    return 0;
}
