#include<iostream>
#include<set>
using namespace std;

int GoodString(string str){
    int i=0,j=0,sum=1,count=0;
    set<char> s;
    int size=INT_MAX;
    for(i=0;i<str.size();i++){
        while(s.size()<3&&j<str.size()){
            s.insert(str[j]);
            count++;
            j++;
        }
        //cout<<s.size();
        s.clear();
        size=min(count,size);
        while(str[i]!=str[i+1]&&i<str.size()){
            i++;
            count--;
        }
        i++;
        count--;
        while(str[i]!=str[i+1]&&i<str.size()){
            i++;
            count--;
        }
    }
    return size;
}
int main(){
    string s;
    cin>>s;
    cout<<GoodString(s);
}
