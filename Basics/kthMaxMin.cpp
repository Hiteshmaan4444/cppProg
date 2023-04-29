#include<iostream>
#include<set>
using namespace std;
int quickSelect(int *arr,int n, int pivot)
{
    int i=-1;
    int j;
    for(j=0;j<n;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    int pos=++i;
    swap(arr[i],arr[j]);
    return pos;
}
void kthMaxMin(int *arr,int beg,int end,int k,int n){
    int pos=quickSelect(arr,end,*(arr+end));
    if(pos+1==k){
        cout<<arr[pos];
        return;
    }if(pos+1>k){
        kthMaxMin(arr,beg,pos-1,k,n);
    }else{
        kthMaxMin(arr,pos+1,end,k,n);
    }
}
int main(){
    int arr[]={1,3,-1,4,2};
    int k;
    int n=(sizeof(arr)/sizeof(arr[0]))-1;

    cin>>k;
    k=n-k+2;
    int pos;
    if(k>n+1){
        cout<<"Out of Bound";
        return 0;
    }
    kthMaxMin(arr,0,n,k,n);
}
