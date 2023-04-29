#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2};
    int n=sizeof(arr)/sizeof(int);
    int ele=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=ele;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
