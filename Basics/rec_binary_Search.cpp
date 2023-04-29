#include<iostream>

using namespace std;
int bi(int *arr,int s,int st,int en){
    if(st>en)return -1;

    int mid=st+((en-st)/2);

    if(arr[mid]==s){
        return mid;
    }else if(arr[mid]>s){
        return bi(arr,s,st,mid-1);
    }else{
        return bi(arr,s,mid+1,en);
    }
}
int main(){
    int arr[]={1,2,3,45,46,143,167};

    cout<<bi(arr,0,0,7);
}
