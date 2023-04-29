#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value you want to print";
    cin>>n;

    for(int i=1;i<=n;i++){
            int j,k;
        for(j=1;j<=n-i+1;j++){
            cout<<" ";
        }
        int count=1;
        for(k=j;k<=n;k++){
            cout<<count++;
        }
        while(count>0){
            cout<<count--;
        }
        cout<<endl;
    }
}
