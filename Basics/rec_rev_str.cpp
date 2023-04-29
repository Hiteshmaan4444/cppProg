#include<iostream>
using namespace std;
void rev(string &str,int n){
    if(n<0) return;
    swap(str[n],str[str.size()-n-1]);
    rev(str,n-1);
}
int main(){
    string str = "abcdef";
    rev(str,(str.size()-1)/2);
    cout<< str;
}
