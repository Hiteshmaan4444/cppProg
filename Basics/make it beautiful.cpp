#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int count=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i-1>=0&&arr[i-1]==arr[i]){
                count++;

            }
        }
        if(count==n-1) {
            cout<<"No"<<endl;
            continue;
        }else cout<<"YES"<<endl;
        if(arr[0]==arr[1]) swap(arr[0],arr[count+1]);
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum==arr[i]){
                swap(arr[i],arr[i-1]);
            }
            sum+=arr[i];
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
