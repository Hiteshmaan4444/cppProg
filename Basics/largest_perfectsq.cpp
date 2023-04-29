#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
bool isPerf(string x){
    int res=atol(x.c_str());
    if(res>=0){
        long long c=sqrt(res);

        if(c*c==res) return true;
    }
    return false;
}
void findPer(string num,vector<int> vec,int j,int k,long long &max,bool &found){
     if(-1==k) return;
     int i;
     for(int i=k;i>=j;i--){
        if(found) return;
        while(num[vec[i]]>='0'){
            //cout<<num<<"\n";
            findPer(num,vec,j,k-1,max,found);
            if(isPerf(num)){
                long long temp=atol(num.c_str());
                if(max<temp){
                    max=temp;
                    found=true;
                    return;
                }
            }
            num[vec[i]]=num[vec[i]]-1;
        }
        //cout<<"\n";
        num[vec[i]]='9';
     }

}
long long findLar(string num){
    long long res;
    int n=num.size();
    vector<int> vec;
    int i;
    for(i=n-1;i>0;i--){
        if(num[i]=='_'){
            num[i]='9';
            vec.push_back(i);
        }
    }
    if(num[i]=='_'){
        num[i]='9';
        vec.push_back(i);
    }
    int k=vec.size()-1;
    i=0;
    if(!vec.size()){
        if(isPerf(num))
            return atol(num.c_str());
        else{
            return -1;
        }
    }
    long long max=-1;
    int count=0;
    bool found=false;
    findPer(num,vec,i,k,max,found);
    return max;
}

int main(){
    string input="12____";
    long long lar = findLar(input);
    cout<<"lar: "<<lar;
    return 0;
}
