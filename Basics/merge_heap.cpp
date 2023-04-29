//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void heapify(vector<int> &a,int n ){
        a[0]=a[n-1];
        int i=0;
        while(i<n-1){
            int left=2*i+1;
            int right=2*i+2;
            int parent=a[i];
            cout<<i;
            if(left<n-1&&right<n-1){
                if(parent>a[left]&&parent>a[right]) return;
                else if(a[left]>a[right]){
                    swap(a[i],a[left]);
                    i=left;
                }else{
                   swap(a[i],a[right]);
                    i=right;
                }
            }else if(left<n-1){
                if(parent>a[left]) return;
                swap(a[i],a[left]);
                    i=left;
            }else if(right<n-1){
                if(parent>a[right]) return;
                swap(a[i],a[right]);
                    i=right;
            }else{
                return;
            }
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        /*4 3
        10 5 6 2
        12 7 9*/
        vector<int> res;
        int i=0;
        while(n||m){
            if(n!=0&&m!=0&&a[0]>=b[0]){
                res.push_back(a[0]);
                heapify(a,n);
                n--;
            }else if(n!=0&&m!=0&&a[0]<b[0]){
                res.push_back(b[0]);
                heapify(b,m);
                m--;
            }else if(n!=0){
                res.push_back(a[0]);
                heapify(a,n);
                n--;
            }else if(m!=0){
                res.push_back(b[0]);
                heapify(b,m);
                m--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends
