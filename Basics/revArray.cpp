#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4};
    int *beg=arr;
    int *end=arr+(sizeof(arr)/sizeof(arr[0]))-1;
    while(beg<end){
        int temp=*beg;
        *beg=*end;
        *end=temp;
        beg++;
        end--;
    }
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        cout<<arr[i]<<" ";
    }
}
