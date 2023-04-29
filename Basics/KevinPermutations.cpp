#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int size;
        cin>>size;
        string s;
        cin>>s;
        int j=0;
        int count=0;
        for(int i=0;i<s.size();i++){
               while(i<s.size()&&s[i]!='Q'){
                   i++;
               }
               if(i>=s.size()){
                break;
               }
                j=i;
               while(j<s.size()&&s[j]!='A'){
                   j++;
               }
               if(j>=s.size()){
                       count=1;
                       break;
               }
               s[j]='Z';
        }
        if(count){
            cout<<"No\n";
        }else
        cout<<"Yes\n";
    }
    return 0;
}
