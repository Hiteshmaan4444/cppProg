#include<iostream>
using namespace std;

int main(){
    int len=7;
    int n=(len+1)/2;
    for(int i=n;i>=1;i--){
        int spaces=n-i;
        int star=2*(i-1)+1;
        for(int j=1;j<=spaces;j++)cout<<" ";
        for(int j=1;j<=star;j++)cout<<"*";
        cout<<endl;
    }
    for(int i=2;i<=n;i++){
        int spaces=n-i;
        int star=2*(i-1)+1;
        for(int j=1;j<=spaces;j++)cout<<" ";
        for(int j=1;j<=star;j++)cout<<"*";
        cout<<endl;
    }
    return 0;
}
