#include<iostream>
using namespace std;
vector<vector<int>> mulMat(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    vector<vector<int>> rslt(0,2,vector<int>(0,2));

    cout << "Multiplication of given two matrices is:\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < 2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return rslt;
}
void multiply(vector<vector<int>> a,vector<vector<int>>b,int s,int e,int r,int c){
    vector<vector<int>> c,a12,a21,a11,a22;
    while(r>2&&c>2){
         a11=multiply(a,b,0,0,r/2,c/2);
         a12=multiply(a,b,0,c/2,r/2,c);
         a21=multiply(a,b,r/2,0,r,c/2);
         a22=multiply(a,b,r/2,c/2,r,c);
    }
    if(r-s=2&&c-e==2){
        matMul(a,b)
    }

}
int main(){
    vector<vector<int>> a={{1,2,1,1},{2,1,1,1},{1,1,1,2},{1,0,0,1}};
    vector<vector<int>> b={{1,0,0,0},{0,1,1,1},{1,1,2,1},{1,2,1,1}};

    c=Multiply(a,b,0,0,a.size(),b.size());
}
