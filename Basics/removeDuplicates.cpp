#include<iostream>
using namespace std;

int rem(int arr[],int n){
    int pindx=0;
    for(int i=0;i<n;i++){
        if(arr[pindx]!=arr[i]){
            pindx++;
            arr[pindx]=arr[i];
        }
    }
    return pindx;
}

int main(){
    int arr[]={10,20,20,30,30,30,30,40,50,6,6};
    int n=rem(arr,sizeof(arr)/sizeof(int));
    for(int i=0;i<=n;i++){
            cout<<arr[i]<<" ";
    }
}

