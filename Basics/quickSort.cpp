#include<iostream>
using namespace std;
quickSort(int arr[],int n){
    int pivot=arr[n];
    int p=0,q=0;
    while(p<n){
        while(arr[p]<pivot&&p<=n){
            p++;
        }
        q=p;
        while(arr[q]>pivot&&q<=n){
            q++;
        }
        int temp=arr[p];
        arr[p]=arr[q];
        arr[q]=temp;
        p++;
    }
}
int main(){
    int arr[]={2,3,8,7,9,1,6};
    quickSort(arr,(sizeof(arr)/sizeof(arr[0]))-1);
    for(int i=0;i<=(sizeof(arr)/sizeof(arr[0]))-1;i++){
        cout<<arr[i]<<" ";
    }
}
