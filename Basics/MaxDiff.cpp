#include<iostream>
using namespace std;

int main(){
    int arr[]={30,10,8,2};
    int res=arr[1]-arr[0];
    int minVal=arr[0];
    int n=sizeof(arr)/sizeof(int);
    for(int i=1;i<n;i++){
        res=max(res,arr[i]-minVal);
        minVal=min(minVal,arr[i]);
    }
    cout<<res;
}
