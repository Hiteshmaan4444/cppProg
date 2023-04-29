#include<iostream>
using namespace std;
int path(int startr,int startc,int n,int m){
    if(startr>n){return 0;}
    if(startc>m){return 0;}
    if(startr==n&&startc==m){
        return 1;
    }
    return path(startr+1,startc,n,m)+path(startr,startc+1,n,m);
}
int main(){
    int n,m;
    cout<<"Enter rows:";
    cin>>n;
    cout<<"Enter cols:";
    cin>>m;
    cout<<path(0,0,n-1,m-1);
}
