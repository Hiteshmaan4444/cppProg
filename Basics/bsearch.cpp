#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(i>0&&vec[i-1]>vec[i]){
            cout<<"Values should be sorted\n";
            return 0;
        }
    }
    int beg=0;
    int end=n-1;
    int mid=(beg+end)/2;
    cout<<"Enter the value to search: ";
    int ele;
    cin>>ele;
    while(beg<=n end){
        if(vec[mid]==ele){
            cout<<"Element "<<ele<<" found at "<<mid<<"\n";
            return 0;
        }else if(vec[mid]<ele){
            beg=mid+1;
        }else{
            end=mid-1;
        }
        mid =(beg+end)/2;
    }
    cout<<"Element not found";
    return 0;
}
