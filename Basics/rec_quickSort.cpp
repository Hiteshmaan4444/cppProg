#include<iostream>
using namespace std;
int partition(int *arr,int i,int n){
    int p=i;
    int pivot=arr[n];
    for(int j=i;j<=n;j++){
        if(arr[j]<=pivot){
            swap(arr[j],arr[p]);
            p++;
        }
    }
    return p-1;
}
void quickSort(int *arr,int i,int n){
    if(i>=n) return;
    int m=partition(arr,i,n);
    quickSort(arr,i,m-1);
    quickSort(arr,m+1,n);
}

int main(){
    int arr[]={3,2,90,4,1,8,7};
    quickSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}
