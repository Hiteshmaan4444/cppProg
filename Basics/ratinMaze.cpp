//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> ltor(n,0);
        vector<int> rtol(n,0);
        int mx=0;
        for(int i=0;i<n;i++){
            ltor[i]=max(mx,arr[i]);
            mx=ltor[i];
        }
        mx=0;
        for(int i=n-1;i>=0;i--){
            rtol[i]=max(mx,arr[i]);
            mx=ltor[i];
        }
        long long water;
        for(int i=0;i<n;i++){
            int mn=min(ltor[i],rtol[i]);
            water+=mn-arr[i];
        }
        return water;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    //testcases
    cin >> t;

    while(t--){
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;

    }

    return 0;
}
// } Driver Code Ends
