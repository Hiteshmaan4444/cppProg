#include<iostream>
using namespace std;

int main(){
    int arr[]={0,10,20,0,90,8,0,26,0,8,7,6};
    int n=sizeof(arr)/sizeof(int);
    int pindx=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[pindx]);
            pindx++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
