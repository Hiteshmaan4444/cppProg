#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n=2,m=3;
    int arr[n][m]={{1,2,3},{1,3,4}};
    int x1=0,y1=1,x2=1,y2=2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>> p(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            p[i][j]=arr[i-1][j-1]+p[i][j-1]+p[i-1][j]-p[i-1][j-1];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
                cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    int sum=0;
    sum=p[x2+1][y2+1]-p[x2+1][y1]-p[x1][y2+1]+p[x1][y1];
    cout<<sum;
    return sum;
}
