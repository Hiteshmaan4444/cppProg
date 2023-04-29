#include<iostream>
using namespace std;

int main(){
    int a,b;
    int sum=0;
    cout<<"enter a and b: ";
    cin>>a;
    cin>>b;
    int big=a>b?a:b;
    for(int i=2;i<=big/2;i++){
        if(a%i==0&&b%i==0){
            sum=i;
        }
    }
    cout<<sum;
}
