#include<iostream>

using namespace std;

int pow(int n,int m){
    if(m==0) return 1;
    int mul=pow(n,m/2);
    if(m%2==0){
        return mul*mul;
    }else{
        return n*mul*mul;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<< pow(n,m);
}
