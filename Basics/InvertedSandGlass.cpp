#include<iostream>
using namespace std;

int main(){
    int n;
    int len;
    cin>>len;
    n=(len+1)/2;
    int spaces=(2*n)-2;
    for(int i=1;i<=n;i++){
        int stars=i;
        for(int k=0;k<stars;k++)cout<<"*";
        for(int k=spaces;k>0;k--)cout<<" ";
        for(int k=0;k<stars;k++)cout<<"*";
        cout<<endl;
        spaces-=2;
    }
    spaces=2*(len%2);
    for(int i=len/2;i>0;i--){
        int stars=i;
        for(int k=0;k<stars;k++)cout<<"*";
        for(int k=spaces;k>0;k--)cout<<" ";
        for(int k=0;k<stars;k++)cout<<"*";
        cout<<endl;
        spaces+=2;
    }
}
