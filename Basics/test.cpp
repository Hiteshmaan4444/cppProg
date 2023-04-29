//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        unordered_map<int,pair<int,int>> m;
        vector<long,long> ans(n,0);
        int mx=0;
        for(int i=0;i<n;i++){
            m[arr[i]]={0,i};
            mx=max(mx,arr[i]);
        }
        int prev=-1;
        for(int i=1;i<=mx;i++){
            if(m.find(i)!=m.end()){
                if(prev==-1){
                    ans[m[i].second]=0;
                    prev=i;
                }else{
                    ans[m[i].second]+=prev+m[prev].first;
                    m[i].first=ans[m[i].second];
                    prev=i;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
