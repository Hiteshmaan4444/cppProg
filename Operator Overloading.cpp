#include<iostream>
using namespace std;

class Complex{
    float i,r;
public:
    Complex(){}
    Complex(float i,float r){
        this->i=i;
        this->r=r;
    }

    friend Complex operator +(Complex &A,Complex& B){
        Complex obj;
        obj.r=A.r+B.r;
        obj.i=A.i+B.i;
        return obj;
    }
    void display(){
        cout<<r<<" +i "<<i<<endl;
    }
};
int main(){
   Complex A(10,20);
   Complex B(10,20);
   Complex C=A+B;
   C.display();
}

