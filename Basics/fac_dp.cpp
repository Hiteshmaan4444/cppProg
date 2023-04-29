
#include<iostream>
using namespace std;

int fac(int n,int dp[]){
    if(n==1) return 1;
    if(dp[n]){
        return dp[n];
    }

    return dp[n]=n*fac(n-1,dp);
}

int main(){
    int n;
    cin>>n;
    int dp[n+1]={0};
    cout<<fac(n,dp);
}
