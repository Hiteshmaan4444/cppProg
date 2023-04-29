#include<iostream>
using namespace std;

bool palin(string &str,int i){
    if(str[i]==str[str.size()-i-1]){
        if(i==0) return true;
        return palin(str,i-1);
    }else{
        return false;
    }
}

int main(){
    string str = "abcrba";
    if(palin(str,(str.size()-1)/2)) cout<<"yes";
    else cout<<"no";
    return 0;
}
