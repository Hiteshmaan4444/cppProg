#include<iostream>
using namespace std;
void merge(int beg,int mid,int end,int arr[]){
    int temp[end-beg+1];
    int n1=beg;
    int n2=mid+1;
    int i=0;
    while(n1<=mid&&n2<=end){
        if(arr[n1]<arr[n2]){
            temp[i]=arr[n1];
            n1++;
        }else{
            temp[i]=arr[n2];
            n2++;
        }
        i++;
    }
    while(n1<=mid){
        temp[i]=arr[n1];
        n1++;
        i++;
    }
    while(n2<=end){
        temp[i]=arr[n2];
        n2++;
        i++;
    }
    int j=0;
    for(int i=beg;i<=end;i++){
        arr[i]=temp[j];
        j++;
    }
}
void mergeSort(int beg,int end,int arr[]){
    int mid=(beg+end)/2;
    if(beg==end){
        return;
    }
    mergeSort(beg,mid,arr);
    mergeSort(mid+1,end,arr);
    merge(beg,mid,end,arr);
}
int main(){
    int arr[]={2,3,1,5,6,0,10,4,8,7,9};

    mergeSort(0,(sizeof(arr)/sizeof(arr[0]))-1,arr);
    for(int i=0;i<=(sizeof(arr)/sizeof(arr[0]))-1;i++){
        cout<<arr[i]<<" ";
    }
}
