#include<iostream>
using namespace std;

int lower(int *arr,int n,int x){
    int low=0,high=n-1,mid;
    while(low<high){
        mid = low+((high-low)/2);
        if(arr[mid]==x){
            if(arr[mid-1]==x){
                high=mid;
            }else{
                return mid;
            }
        }
        if(arr[mid]>x){
            high=mid-1;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
    }
    if(arr[mid]>x){
        if(arr[mid-1]<x)
        return mid-1;
    }
    return mid;
}
int main(){
    int arr[]={1,3,5,7,8,9};
    cout<< lower(arr,6,6);
    return 0;
}
