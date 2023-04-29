#include<iostream>
using namespace std;

void findMaxMin(int *arr,int i,int j,int n,int &mx,int &mn){
    if(i==j){
        mx=arr[i];
        mn=arr[j];
    }else if(i==j-1){
        if(arr[i]<arr[j]){
            mx=arr[j];
            mn=arr[i];
        }else{
            mx=arr[i];
            mn=arr[j];
        }
    }else{
        int mid=(i+j)/2;
        findMaxMin(arr,i,mid,n,mx,mn);
        int mx1,mn1;
        findMaxMin(arr,mid+1,j,n,mx1,mn1);
        if(mx1>mx){
            mx=mx1;
        }
        if(mn1<mn){
            mn=mn1;
        }
    }
}
int main(){
    int arr[]={1,2,-1,3,4};
    int mx,mn;
    findMaxMin(arr,0,sizeof(arr)/sizeof(arr[0])-1,sizeof(arr)/sizeof(arr[0]),mx,mn);
    cout<<mx<<" "<<mn;
}
