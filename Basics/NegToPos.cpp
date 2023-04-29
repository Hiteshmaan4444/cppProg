//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// calculate the maximum sum with out adjacent
	int max_sum(int *arr,int i,int n){
	    if(i>=n){
	        return 0;
	    }
	    return arr[i]+max(max_sum(arr,i+2,n),max_sum(arr,i+3,n));
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    int sum=0;
	    int pos1=0;
	    int pos2=0;
	    int i=0;
	    int sum1=arr[0];
	    int sum2=arr[1];
	    while(i<n){
	        if(i+3<n){
	            pos1=arr[i+2]>arr[i+3]?i+2:i+3;
	            sum1+=max(arr[i+2],arr[i+3]);
	        }else if(i+2<n){
	            pos1=i+2;
	            sum1+=arr[i+2];
	        }else{
	            pos1=n;
	        }
	        if(i+4<n){
	            pos2=arr[i+3]>arr[i+4]?i+3:i+4;
	            sum2+=max(arr[i+3],arr[i+4]);
	        }if(i+3<n){
                pos2=i+3;
	            sum2+=arr[i+3];
	        }else{
	            pos2=n;
	        }
	        sum+=max(sum1,sum2);
	        i=sum1>=sum2?pos1:pos2;
	        sum1=0;
	        sum2=0;
	    }
	    return sum;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
