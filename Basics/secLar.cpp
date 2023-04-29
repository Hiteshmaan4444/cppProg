#include<iostream>
using namespace std;
int secondLargest(int arr[],int n){
    int lar=0;
    int res=-1;
    for(int i=1;i<n;i++){
        if(arr[lar]<arr[i]){res=lar; lar=i;}
        else if(arr[i]!=arr[lar]&&(res==-1||arr[res]<arr[i])){res=i;}
    }
    return res;
}
int main(){
    int arr[]={10,20,10,39,30,40};
    int idx = secondLargest(arr,sizeof(arr)/sizeof(int));
    cout<<idx;
    return 0;
}
