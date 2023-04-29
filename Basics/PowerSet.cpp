#include<iostream>
#include<vector>
using namespace std;
void rec(int *arr,int i,int n,vector<vector<int>> &sets,vector<int> temp){
    if(i==n-1){
    temp.push_back(arr[i]);
    sets.push_back(temp);
    temp.pop_back();
        return;
    }
    temp.push_back(arr[i]);
    sets.push_back(temp);
    rec(arr,i+1,n,sets,temp);
    temp.pop_back();
    rec(arr,i+1,n,sets,temp);
}
int main(){
    int arr[]={1,2,3,8};
    vector<vector<int>> sets;
    vector<int> temp;

    int n=4;
    rec(arr,0,n,sets,temp);

    for(auto i:sets){
        for(auto j:i){
            cout<<j;
        }
        cout<<endl;
    }
}
