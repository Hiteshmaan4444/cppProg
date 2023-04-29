#include<iostream>
using namespace std;

int main(){
    int len;
    cin>>len;
    int n=(len+1)/2;
    for(int i=0;i<n;i++){
        for(int j=0;j<len;j++){
                cout<<n-min(i,j);
        }
        for(int j=0;j<len;j++){
            cout<<n+len-max(i,j);
        }
        cout<<endl;
    }
}
