#include<iostream>
using namespace std;

int main(){
    int arr[]={7,10,2,10,5,6,3,2,1};
    int max=0;
    int n=sizeof(arr)/sizeof(int);
    for(int i=n-1;i>=0;i--){
        if(arr[i]>max){
            max=arr[i];
            cout<<arr[i]<<" ";
        }
    }
}
