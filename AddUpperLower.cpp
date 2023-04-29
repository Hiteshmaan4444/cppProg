#include<iostream>
using namespace std;

int main(){
   int a[3][3];
   cout<<"Enter the matrix elements: ";
   int sum_1=0;
   int sum_2=0;
   for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
        cin>>a[i][j];
     }
   }
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(i-j<=0)
        sum_1+=a[i][j];
        else{
            sum_2+=a[i][j];
        }
    }
   }
   cout<<"Sum Of Upper: "<<sum_1<<endl;
   cout<<"Sum Of Lower: "<<sum_2<<endl;
}

