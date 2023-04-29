#include<iostream>
using namespace std;
int reverse(int *start,int *end){
    while(start<end){
        swap(*start,*end);
        start++;
        end--;
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int d=4;
    int n=sizeof(arr)/sizeof(int);
    d%=n;
    reverse(arr,arr+n-1);
    reverse(arr,arr+n-d-1);
    reverse(arr+n-d,arr+n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
