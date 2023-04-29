#include<iostream>
#include<regex>
#include<set>
using namespace std;

int main(){
 string data;
 getline(cin,data);
 regex r("../../....");
 int beg=0;
 set<string> st;
 int end=beg+10;
 while(beg<=data.size()-10){
    string temp=data.substr(beg++,10);
    if(regex_match(temp,r)){
        st.insert(temp.substr(6,4));
    }
 }
 cout<<st.size();

 return 0;
}
