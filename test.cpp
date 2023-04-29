#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int doUnion(int a[], int n, int b[], int m)  {
        //code here
        sort(a,a+n);
        sort(b,b+m);

        int i=0,j=0,count=0;
        while(i<n&&j<m){
            if(a[i]==b[j]){
                i++;
                j++;
                count++;
            }else if(a[i]>b[j]){
                j++;
                count++;
            }else if(a[i]<b[j]){
                i++;
                count++;
            }
        }
        while(i<n){
            i++;
            count++;
        }
        while(j<m){
            j++;
            count++;
        }
        return count;
    }
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    cout<<doUnion(a,n,b,m);
	return 0;
}
